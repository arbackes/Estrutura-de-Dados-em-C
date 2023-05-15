
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//============================================
void printfVet(int *V  , int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%2d ",V[i]);
    printf("\n");
}

void printfLinha(){
    printf("----------------------------------------------\n");
}
//============================================

int particiona(int *V, int inicio, int final ){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        while(esq <= final && V[esq] <= pivo)
            esq++;

        while(dir >= 0 && V[dir] > pivo)
            dir--;

        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    printf("---------------\n");
    return dir;
}

void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

//============================================

int main(){
    int vet[7] = {23,4,67,-8,90,54,21};
    int N = 7;

    printf("Sem ordenar:\n");
    printfVet(vet,N);
    printfLinha();

    quickSort(vet,0,N-1);//OK
    printf("Ordenado:\n");
    printfVet(vet,N);

    system("pause");
    return 0;
}
