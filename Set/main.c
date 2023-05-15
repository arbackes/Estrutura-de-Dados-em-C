#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

int main(){
    int numeros[10] = {10,20,30,20,10,30,5,20,90,30};

    Set* A = criaSet();
    printf("Tamanho: %d\n",tamanhoSet(A));

    int i;
    for(i=0; i < 10; i++)
        insereSet(A,numeros[i]);

    printf("Set: ");
    imprimeSet(A);
    printf("\n");

    printf("Tamanho: %d\n",tamanhoSet(A));

    int x = 20;
    printf("%d existe: %d\n\n",x,consultaSet(A,x));

    // Teste iterator
    for(beginSet(A); !endSet(A); nextSet(A)){
        getItemSet(A, &x);
        printf("Iterator %d: %d\n",i,x);
    }

    //Teste Uniao
    printf("======================\n");
    printf("Teste Uniao\n");
    printf("======================\n");
    Set* B = criaSet();
    insereSet(B,5);
    insereSet(B,20);
    insereSet(B,25);
    insereSet(B,35);

    Set* C = uniaoSet(A, B);

    printf("Set A: "); imprimeSet(A); printf("\n");
    printf("Set B: "); imprimeSet(B); printf("\n");
    printf("Set C: "); imprimeSet(C); printf("\n");
    liberaSet(C);

    //Teste Intersecçção
    printf("======================\n");
    printf("Teste Interseccao\n");
    printf("======================\n");

    C = interseccaoSet(A, B);

    printf("Set A: "); imprimeSet(A); printf("\n");
    printf("Set B: "); imprimeSet(B); printf("\n");
    printf("Set C: "); imprimeSet(C); printf("\n");
    liberaSet(C);

    liberaSet(B);
    liberaSet(A);

    system("pause");

    return 0;
}
