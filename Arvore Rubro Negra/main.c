#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"
int main(){
    ArvLLRB * raiz = cria_ArvLLRB();
    //system ("color C");
    //https://www.youtube.com/watch?v=rcDF8IqTnyI

    //int i, N = 7, val[7] ={20,15,30,85,50,21,70};
    int i, N = 9, val[9] = {11,2,1,5,4,7,8,14,15};
    //int i, N = 10, val[10] ={10,15,10,20,30,70,70,85,50,50};

    for(i=0; i< N; i++){
        /*
        if(insere_ArvLLRB(raiz,val[i]))
            printf("Insercao: %d -> OK\n",val[i]);
        else
            printf("Insercao: %d -> ERRO\n",val[i]);
        */
        //printf("Insercao: %d -> OK\n",val[i]);
        insere_ArvLLRB(raiz,val[i]);
        //emOrdem_ArvLLRB(raiz,0);
        //printf("\n\n==========================\n\n");
    }

    //printf("Tamanho: %d \n",totalNO_ArvLLRB(raiz));
    emOrdem_ArvLLRB(raiz,0);

    printf("\n\n==========================\n\n");

    remove_ArvLLRB(raiz,4);
    emOrdem_ArvLLRB(raiz,0);
    printf("\n\n==========================\n\n");
    remove_ArvLLRB(raiz,1);
    emOrdem_ArvLLRB(raiz,0);

    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* avl;
    int res,i;
    int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    //int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};

    avl = cria_ArvAVL();

    for(i=0;i<N;i++){
        printf("Inserindo: %d\n",dados[i]);
        res = insere_ArvAVL(avl,dados[i]);
        //printf("\n\nres = %d\n",res);
        //preOrdem_ArvAVL(avl);
        //printf("\n\n");
    }

    printf("\nAVL tree:\n");
    preOrdem_ArvAVL(avl);
    printf("\n\n");

    int NR = 4, dadosR[4] = {7,51,3,5};
    for(i=0;i<NR;i++){
        printf("\nRemovendo: %d\n",dadosR[i]);
        res = remove_ArvAVL(avl,dadosR[i]);
        printf("\n\nres = %d\n",res);
        preOrdem_ArvAVL(avl);
        //printf("\n\n");
    }

    printf("\nAVL tree:\n");
    preOrdem_ArvAVL(avl);
    printf("\n\n");

    libera_ArvAVL(avl);

//    int x = 5;
//    printf("%d \n",labs(x));
//    printf("%d \n",labs(-x));
//    x = -10;
//    printf("%d \n",labs(x));
//    printf("%d \n",labs(-x));

    return 0;
}

*/
