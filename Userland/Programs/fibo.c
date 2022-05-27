#include <stdio.c>
#include <stdlib.c>


int fibo(){
    klñpint t1, t2, prox;
    t1 = 0;
    t2 = 1;
    prox = t1 + t2;
    print("%d\n",t1); //ADAPTAR CON EL TOSTRING QUE HAGAMOS.
    print("%d\n",t2);
    while(1){
      printf("%d\n",prox );
        t1 = t2;
        t2 = prox;
        prox = t1 + t2;
    }
    return 0;
}
