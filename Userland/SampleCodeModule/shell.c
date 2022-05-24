#include <stdlib.h>
#include <shell.h>
#define LENGTH 100

void shell(void){
    char buffer[LENGTH];
    while(1){
        int num = date(6);
        printInt(num);
        printf("User:$ ");
        int length = scanf(buffer);
        printf("Programa: ");
        printf(buffer);
        //Acá va el procesamiento de lo que recibio la funcion para ejecutar un programita
    }
}