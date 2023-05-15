#include <stdio.h>
#include <stdlib.h>
#include "Bag.h"

int main(){
    int numeros[10] = {10,20,30,20,10,30,5,20,90,30};

    Bag* b = criaBag();
    printf("Tamanho: %d\n\n\n\n",tamanhoBag(b));

    int i;
    for(i=0; i < 10; i++)
        insereBag(b,numeros[i]);

    imprimeBag(b);
    printf("\n\n\n\n Tamanho: %d\n",tamanhoBag(b));

    int x = 20;
    printf("%d ocorre: %d\n\n\n",x,consultaBag(b,x));

    for(beginBag(b); !endBag(b); nextBag(b)){
        getItemBag(b, &x);
        printf("Iterator %d: %d\n",i,x);
    }

    x = 10;
    printf("%d remove: %d\n\n\n",x,removeBag(b,x));
    imprimeBag(b);
    printf("\n\n\n\n Tamanho: %d\n",tamanhoBag(b));
    printf("\n");

    for(beginBag(b); !endBag(b); nextBag(b)){
        getItemBag(b, &x);
        printf("Iterator %d: %d\n",i,x);
    }

    liberaBag(b);
    system("pause");

    return 0;
}

