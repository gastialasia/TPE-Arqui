#include <stdlib.h>
#include <stdint.h>

#define BIGGEST64INT 0xFFFFFFFFFFFFFFFF

static uint64_t fibo1=0;
static uint64_t fibo2=1;
static uint64_t lastPrimo=1;

uint64_t fibo(){
    uint64_t aux = fibo1;
    fibo1 = fibo2;
    fibo2 = aux+fibo1;
    return aux;
}

void reset_fibo(){
    fibo1=0;
    fibo2=1;
}

uint64_t primos(){ //Esta funcion es una criba de Eratosthenes casera
    uint64_t j, limit;
    for(uint64_t i=lastPrimo+1; i <= BIGGEST64INT; i++){
        limit = i/2;
        int isPrimo=1;
        for(j=2; j <= limit && isPrimo; j++){
            if(i%j==0)
                isPrimo = 0;
        }
        if(isPrimo){
            lastPrimo = i;
            return lastPrimo;
        }
    }
    return 0;
}

void reset_primo(){
    lastPrimo=1;
}
