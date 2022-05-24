#include <stdlib.h>
#include <shell.h>
#define LENGTH 100

void shell(void){
    char buffer[LENGTH];
    printf("La fecha actual es: ");
    printdate();
    while(1){
        printf("User:$ ");
        int length = scanf(buffer);
        printf("Programa: ");
        printf(buffer);
        //Acá va el procesamiento de lo que recibio la funcion para ejecutar un programita
    }
}