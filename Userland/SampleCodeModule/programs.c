#include <stdlib.h>


int fibo(){
    unsigned long long t1, t2, prox;
    t1 = 0;
    t2 = 1;
    prox = t1 + t2;
    printInt64(t1); //ADAPTAR CON EL TOSTRING QUE HAGAMOS.
    putchar('\n');
    sleep(1);
    printInt64(t2);
    putchar('\n');
    sleep(1);
    while(1){
        /*if(getchar() == 'c'){
            printf("CANCELADO\n" );
            return 0;
        }*/

        printInt64(prox);
        t1 = t2;
        t2 = prox;
        prox = t1 + t2;
        putchar('\n');
        //sleep(1);
    }
    return 0;
}
