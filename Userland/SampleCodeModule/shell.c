#include <stdlib.h>
#include <shell.h>
#define LENGTH 100

static char buffer[LENGTH];

void shell(void){
    while(1){
        printf("User:$ ");
        int length = scanf(buffer);
        printf("Programa: ");
        printf(buffer);
        //Acá va el procesamiento de lo que recibio la funcion para ejecutar un programita
    }
}