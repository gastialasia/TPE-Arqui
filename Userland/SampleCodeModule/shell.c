#include <stdlib.h>
#include <shell.h>
#include <programs.h>
#define LENGTH 100
#define MAXDIGITS 21
#define MAXBUFFER 100


void shell(void){

    char buffer[LENGTH];
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
        if (strcmp(commands[0],"divzero")){
            divzero();
        }
    	else if (strcmp(commands[0],"clear")) {
    		clear();
    	}
        else if(strcmp(commands[0],"opcode")){
            opcode();
        }
        else{
            simpleScreenWrapper(getFuncFromString(commands[0]));
        }

    } else if (flag==1) {
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
    } else{
        toRet =&invalid;
    }
    return toRet;
}

void simpleScreenWrapper(char(*fn)(char*)){
    char isRunning=1;
    char buffer[MAXBUFFER];
    while(isRunning){
        isRunning = fn(buffer);
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
      if (isRunning1){
          isRunning1 = fn1(buffer);
          printfLeft(buffer);
          printfLeft("\n");
          // Hay que chequear porque entra una vez mas de las que deberia
      }
      if (isRunning2){
          isRunning2 = fn2(buffer);
          printfRight(buffer);
          printfRight("\n");
          // Idem anterior
      }
      //sleep(1);
    }
}
