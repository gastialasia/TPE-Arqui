#include <stdlib.h>
#include <shell.h>
#include <programs.h>
#define LENGTH 100
#define MAXDIGITS 21

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
            //printdate();
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
        } else if(strcmp(commands[0],"split")){
            SplitScreenWrapper(fibo,help);
            reset_primo();
            reset_fibo();
        }
        else
            printf("Invalid command: try 'help'\n");
    }
}

void simpleScreenWrapper(char(*fn)(char*)){
    char isRunning=1;
    char buffer[21];
    while(isRunning=fn(buffer)){
        printf(buffer);
        putchar('\n');
    }
    printf("Program ended.\n");
}

void SplitScreenWrapper(char(*fn1)(char*),char(*fn2)(char*)){
    char isRunning1=1;
    char isRunning2=1;
    char buffer[100];
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
