#include <stdlib.h>
#include <shell.h>
#include <programs.h>
#define LENGTH 100
#define MAXDIGITS 21
#define MAXBUFFER 100


void shell(void){

    setScreenMode(1);
    char buffer[LENGTH];
    printf(buffer);
    while(1){
        printf("User:$ ");
        int length = scanf(buffer);
        buffer[length-1]=0;
        parser(buffer);
        //Acá va el procesamiento de lo que recibio la funcion para ejecutar un programita
    }
}

void parser(char * buffer){
    int i = 0,j = 0, k = 0;
    char commands[2][100];
    int flag = 0;
    while(buffer[i] != 0){ //faltan chequeos
        if(buffer[i] == '|'){
            commands[j][k] = 0;
            j++;
            k = 0;
            flag = 1;
        } else if(buffer[i] != ' '){
            commands[j][k++] = buffer[i];
        }

        i++;
    }
    commands[j][k] = 0;
    if(flag == 0){
        simpleScreenWrapper(getFuncFromString(commands[0]));
    }  else {
        // El flag es 1, entonces hay un pipe
        uint64_t prog1 = getFuncFromString(commands[0]);
        uint64_t prog2 = getFuncFromString(commands[1]);
        SplitScreenWrapper(prog1,prog2);
    }
}

uint64_t getFuncFromString(char*str){
    uint64_t toRet;
    if (strcmp("date",str)){
        toRet = &date;
    } else if (strcmp("help",str)){
        toRet = &help;
    } else if (strcmp("fibonacci",str)){
        toRet = &fibo;
    } else if (strcmp("primos",str)){
        toRet = &primos;
    } else if (strcmp("opcode",str)){
        toRet = &opcode;
    } else if (strcmp("divzero",str)){
        toRet = &divzero;
    } else if (strcmp("clear",str)){
        toRet = &clear;
    } else if (strcmp("printmem",str)){
        toRet =&invalid;
        //toRet = &printmem;
    } else{
        toRet =&invalid;
    }
    return toRet;
}

void simpleScreenWrapper(char(*fn)(char*)){
    char buffer[MAXBUFFER];
    char isRunning=fn(buffer);
    printf(buffer);
    putchar('\n');
    while(isRunning = fn(buffer)){
        printf(buffer);
        putchar('\n');
    }
    //printf("Program ended\n");
}

void SplitScreenWrapper(char(*fn1)(char*),char(*fn2)(char*)){
    char isRunning1=1;
    char isRunning2=1;
    char buffer[MAXBUFFER];
    while(isRunning1||isRunning2){
        sleep(1);
      if (isRunning1){
          isRunning1 = fn1(buffer);
          setScreenMode(2);
          printf(buffer);
          printf("\n");
          // Hay que chequear porque entra una vez mas de las que deberia
      }
      if (isRunning2){
          isRunning2 = fn2(buffer);
          setScreenMode(3);
          printf(buffer);
          printf("\n");
          // Idem anterior
      }
      //sleep(1);
    }
}
