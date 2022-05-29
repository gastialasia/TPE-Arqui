#include <stdlib.h>
#include <shell.h>
#define LENGTH 100

void shell(void){

    //Pruebas:
    //printfLeft("Llamando a printfLeft: este texto deberia aparecer del lado izquierdo de la pantalla");
    //printfRight("Llamando a printfRight: este texto deberia aparecer del lado derecho de la pantalla puto el que lee");
    char buffer[LENGTH];
    while(1){
        printf("User:$ ");
        int length = scanf(buffer);
        buffer[length]=0;
        if (strcmp(buffer,"date\n")){
            printf("La fecha actual es: ");
            printdate();
        }
	else if (strcmp(buffer,"divzero\n")) {
		divzero();
	}
        //Acá va el procesamiento de lo que recibio la funcion para ejecutar un programita
    }
}
