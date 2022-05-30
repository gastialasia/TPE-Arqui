#include <stdlib.h>


int fibo(){
    int t1, t2, prox;
    t1 = 0;
    t2 = 1;
    prox = t1 + t2;
    printInt(t1); //ADAPTAR CON EL TOSTRING QUE HAGAMOS.
    printInt(t2);
    while(1){
        /*if(getchar() == 'c'){
            printf("CANCELADO\n" );
            return 0;
        }*/

      printInt(prox);
        t1 = t2;
        t2 = prox;
        prox = t1 + t2;
        putchar('\n');
    }
    return 0;
}
