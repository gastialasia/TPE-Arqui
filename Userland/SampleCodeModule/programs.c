#include <stdlib.h>
#include <stdint.h>

#define LIMIT64 0b0111111111111111111111111111111111111111111111111111111111111111 //2^(63)-1

static uint64_t fibo1=0;
static uint64_t fibo2=1;
static uint64_t lastPrimo=1;

static char buff[300];

char help(void){
    printf("Commands:\n-fibonacci\n-help\n-printmem\n-date\n-opcode\n");
    return 0;
}

char invalid(void){
    printf("Invalid command: try 'help'\n");
    return 0;
}

char date(void){
    int values[5] = {7,8,9,4,2}; //En orden: D, M, Y, H, M
    char buffer[3]; // Cada numero de la fecha no va a tener más de dos digitos, 3 contando el cero null terminated
    for (int i=0;i<5;i++){
        char num = getDateComponent(values[i]);
        uintToBase(num,buffer,16);
        if (num<0xA){
            // Si el numero es de un solo digito, lo muevo un lugar a la derecha y a la izquierda le pongo un cero
            char aux = buffer[0];
            buffer[0]='0';
            buffer[1]=aux;
        }
        buffer[2]=0; // Al string del numero le agrego un cero null terminated asi puedo usar strcpy
        printf(buffer);
        if (i<2){
            printf("/");
        } else if (i==3){
            printf(":");
        } else {
            printf(" ");
        }
    }
    printf("UTC\n");
    return 0;
}

char fibo(void){
    // Deja en el buffer el numero convertido a string
    // Devuelve 1 si el programa sigue corriendo, 0 sino
    uint64_t aux = fibo1;
    fibo1 = fibo2;
    fibo2 = aux+fibo1;
    if (aux>LIMIT64){
        return 0;
    }
    uintToBase(aux,buff,10);
    printf(buff);
    putchar('\n');
    return 1;
}

void reset_fibo(){
    fibo1=0;
    fibo2=1;
}

char primos(void){ //Esta funcion es una criba de Eratosthenes casera
  // deja en el buffer el numeor convertido a string
  // devuelve 1 si el programa no termino, 0 si termino
    uint64_t j, limit;
    for(uint64_t i=lastPrimo+1; i <= LIMIT64; i++){
        limit = i/2;
        int isPrimo=1;
        for(j=2; j <= limit && isPrimo; j++){
            if(i%j==0)
                isPrimo = 0;
        }
        if(isPrimo){
            lastPrimo = i;
            uintToBase(lastPrimo,buff,10);
            printf(buff);
            putchar('\n');
            return 1;
        }
    }
    return 0;
}

void reset_primo(){
    lastPrimo=1;
}

char infoRegisters(){
    inforeg();
    return 0;
}

char nullProgram(){
    return 0;
}
