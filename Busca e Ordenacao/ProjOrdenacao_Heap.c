
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//============================================
//void printfVet(int *V  , int N){
//    int i;
//    for(i = 0; i < N; i++)
//        printf("%2d ",V[i]);
//    printf("\n");
//}
//
//void printfLinha(){
//    printf("----------------------------------------------\n");
//}
//
//void printfHeap(int *V){
//    printf("\t\t%d\n",V[0]);
//    printf("\t%d\t\t%d\n",V[1],V[2]);
//    printf("%d\t%d\t\t%d\t%d\n",V[3],V[4],V[5],V[6]);
//    printfLinha();
//}
//============================================
void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            if(vet[j] < vet[j + 1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}

void heapSort(int *vet, int N){
    int i, aux;
    for(i=(N - 1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--){
        aux = vet[0];
        vet [0] = vet [i];
        vet [i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}


int main(){
//==============================================================================
    //int vet[11] = {1,23,4,67,-8,54,90,21,14,-5,1};
    int vet[7] = {23,4,67,-8,90,54,21};
    //int vet[7] = {1,2,3,4,5,6,7};
    int N = 7;

    printf("Sem ordenar:\n");
    //printfVet(vet,N);
    //printfLinha();

    heapSort(vet,N);
    //printfHeap(vet);

    printf("Ordenado:\n");
    //printfVet(vet,N);
//==============================================================================

    system("pause");
    return 0;
}
