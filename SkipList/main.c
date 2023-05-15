#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SkipList.h"

int main(){
    // Seed random number generator
	srand((unsigned)time(0));
    // create SkipList object with MAXLVL and P
    SkipList* sk = criaSkipList(10, 0.5);

    printf("Vazia = %d\n",vaziaSkipList(sk));

    int i, vet[10] = {3,6,7,9,12,19,17,26,21,25};
    for(i=0; i<10; i++){
        insereSkipList(sk, vet[i]);
        printf("Tamanho = %d\n",tamanhoSkipList(sk));
    }
    imprimeSkipList(sk);
    printf("Vazia = %d\n",vaziaSkipList(sk));
    printf("Tamanho = %d\n",tamanhoSkipList(sk));

    if(buscaSkipList(sk, 19))
        printf("Achou o 19\n");
    else
        printf("NAO achou o 19\n");

    removeSkipList(sk, 19);
    imprimeSkipList(sk);

    printf("Vazia = %d\n",vaziaSkipList(sk));
    printf("Tamanho = %d\n",tamanhoSkipList(sk));

    liberaSkipList(sk);

    return 0;
}
