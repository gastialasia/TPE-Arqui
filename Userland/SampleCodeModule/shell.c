#include <stdlib.h>
#include <shell.h>
#include <programs.h>
#include <stdint.h>
#define LENGTH 100
#define MAXDIGITS 21
#define MAXBUFFER 100

void shell(void){

    setScreenMode(1);
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
        simpleScreenWrapper(getFuncFromString(commands[0]));
    }  else {
        // El flag es 1, entonces hay un pipe
        function_type prog1 = getFuncFromString(commands[0]);
        function_type prog2 = getFuncFromString(commands[1]);
        SplitScreenWrapper(prog1,prog2);
    }
}

function_type getFuncFromString(char*str){
    function_type toRet;
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
    } else if (strcmp("inforeg",str)){
        toRet = &infoRegisters;
    } else if (strcmp("printmem",str)){
        toRet =&invalid;
        //toRet = &printmem;
    } else{
        toRet =&invalid;
    }
    return toRet;
}

void simpleScreenWrapper(char(*fn)(void)){
    //char buffer[MAXBUFFER];
    char isRunning=fn();

    //printf(buffer);
    while(isRunning){
        //printf(buffer);
        putchar('\n');
        isRunning = fn();
    }
    //printf("Program ended\n");
}

void SplitScreenWrapper(char(*fn1)(void),char(*fn2)(void)){
    char isRunning1=1;
    char isRunning2=1;
    while(isRunning1||isRunning2){
        //sleep(1);
      if (isRunning1){
          setScreenMode(2);
          printf("\n");
          isRunning1 = fn1();
          // Hay que chequear porque entra una vez mas de las que deberia
      }
      if (isRunning2){
          setScreenMode(3);
          printf("\n");
          isRunning2 = fn2();
          // Idem anterior
      }
      //sleep(1);
    }
    //Completar con esperar la tecla
    setScreenMode(1);
}
