#include <stdlib.h>
#include <shell.h>
#include <programs.h>
#define LENGTH 100
#define LIMIT64 0b0111111111111111111111111111111111111111111111111111111111111111 //2^(63)-1

void shell(void){

    //Pruebas:
    //printfLeft("Llamando a printfLeft: este texto deberia aparecer del lado izquierdo de la pantalla");
    //printfRight("Llamando a printfRight: este texto deberia aparecer del lado derecho de la pantalla puto el que lee");
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
    char commands[2][10];
    int flag = 0;
    while(buffer[i] != 0){ //faltan chequeos
        if(buffer[i] != ' '){
            commands[j][k++] = buffer[i];
        }
        else if(buffer[i] == '|'){
            commands[j][k] = 0;
            j++;
            k = 0;
            flag = 1;
        }
        i++;
    }
    commands[j][k] = 0;
    if(flag == 0){
        if (strcmp(commands[0],"date")){
            printf("La fecha actual es: ");
            printdate();
        }
    	else if (strcmp(commands[0],"divzero")) {
    		divzero();
    	}
        else if (strcmp(commands[0],"clear")){
            clear();
        }
        else if(strcmp(commands[0],"opcode")){
            opcode();
        }
        else if(strcmp(commands[0],"fibonacci")){
            simpleScreenWrapper(fibo);
            reset_fibo();
        }
        else if(strcmp(commands[0],"primos")){
            simpleScreenWrapper(primos);
            reset_primo();
        }
        else
            printf("Invalid command: try 'help'\n");
    }
}

void simpleScreenWrapper(uint64_t(*fn)(void)){
    uint64_t current;
    while((current = fn()) < LIMIT64){
        printInt64(current);
        putchar('\n');
        sleep(1);
    }
    printf("Program ended.\n");
}

void SplitScreenWrapper(uint64_t(*fn1)(void),uint64_t(*fn2)(void)){
    uint64_t current1;
    uint64_t current2;
    int p1Running=1;
    int p2Running=1;
    while(p1Running&&p2Running){
      current1 = fn1();
      if (p1Running&&current1>LIMIT64){
        p1Running=0;
      }
      current2 = fn2();
      if (p2Running&&current2>LIMIT64){
        p1Running=0;
      }
      if (!p1Ended){
        printfL(current1);
        printfL("\n");
      }
      if (!p2Ended){
        printfR(current2);
        printfR("\n");
      }
      sleep(1);
    }
}
