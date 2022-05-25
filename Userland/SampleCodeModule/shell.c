#include <stdlib.h>
#include <shell.h>
#define LENGTH 100

void shell(void){
    char buffer[LENGTH];
    while(1){
        printf("User:$ ");
        int length = scanf(buffer);
        buffer[length]=0;
        if (strcmp(buffer,"date")){
            printf("La fecha actual es: ");
            printdate();
        }
        //Acá va el procesamiento de lo que recibio la funcion para ejecutar un programita
    }
}