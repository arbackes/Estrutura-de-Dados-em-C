
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int M = 0;

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

void printfVet(int *V  , int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%2d ",V[i]);
    printf("\n");
}

//============================================

void bubbleSort(int *V  , int N){
    int i, continua, aux;
    do{
        continua = 0;
        for(i = 0; i < N-1; i++){
            if (V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = 1;
            }
        }
    }while(continua);
}

void bubbleSort2(int *V  , int N){//otimizado
    int i, continua, aux, fim = N;
    do{
        continua = 0;
        for(i = 0; i < fim-1; i++){
            if (V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}
//============================================
void insertionSort(int *V, int N){
    int i, j, aux;
    for(i = 1; i < N; i++){
        aux = V[i];
        for(j = i; (j > 0) && (aux < V[j - 1]); j--)
            V[j] = V[j - 1];
        V[j] = aux;
    }
}
//============================================
void selectionSort(int *V, int N){
    int i, j, menor, troca;
    for(i = 0; i < N-1; i++){
        menor = i;
        for(j = i+1; j < N; j++){
            if(V[j] < V[menor])
                menor = j;
        }
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}
//============================================
void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            V[k]=temp[j];
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V,inicio,meio);
        mergeSort(V,meio+1,fim);
        merge(V,inicio,meio,fim);
    }
}

//============================================

void insertionSortMatricula(struct aluno *V, int N){
    int i, j;
    struct aluno aux;
    for(i = 1; i < N; i++){
        aux = V[i];
        for(j=i;(j>0) && (aux.matricula<V[j-1].matricula);j--)
            V[j] = V[j - 1];
        V[j] = aux;
    }
}
/*saída strcmp(str1,str2)
    == 0: str1 é igual a str2
     > 0: str1 vem depois de str2
     < 0: str1 vem antes de str2
*/
void insertionSortNome(struct aluno *V, int N){
    int i, j;
    struct aluno aux;
    for(i = 1; i < N; i++){
        aux = V[i];
        for(j=i;(j>0) && (strcmp(aux.nome,V[j-1].nome)<0);j--)
            V[j] = V[j-1];
        V[j] = aux;
    }
}

//============================================


int main(){
    int i;

//    struct aluno V[4] = {{2,"Andre",9.5,7.8,8.5},
//                         {4,"Ricardo",7.5,8.7,6.8},
//                         {1,"Bianca",9.7,6.7,8.4},
//                         {3,"Ana",5.7,6.1,7.4}};
//
//    //insertionSortMatricula(V,4);
//    insertionSortNome(V,4);
//    for(i = 0; i < 4; i++)
//        printf("%d) %s\n",V[i].matricula,V[i].nome);
//
//
//
//    system("pause");
//    return 0;
//}






//==============================================================================

//    int vet[10] = {23,4,67,-8,54,90,21,14,-5,1};
//    int N = 10;

    int vet[7] = {23,4,67,-8,90,54,21};
    int N = 7;

//    int vet[7] = {23,4,67,-8,21};
//    int N = 5;

    printf("Sem ordenar:\n");

    //bubbleSort(vet,N);//OK
    //bubbleSort2(vet,N);//OK
    //insertionSort(vet,N);//OK
    //selectionSort(vet,N);//OK
    mergeSort(vet,0,N);//OK
    //quickSort(vet,0,N-1);//OK
//    for(i=0; i<N; i++)
//        printf("%d\n",vet[i]);

//==============================================================================
//    int vet[8] = {0,23,4,67,-8,90,54,21};
//    int N = 8;
//
//    printf("Sem ordenar:\n");
//    printfVet(vet,N);
//    printfLinha();
//
//    printf("Ordenado:\n");
//    printfVet(vet,N);
//==============================================================================


    system("pause");
    return 0;
}
