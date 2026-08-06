#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int linha;
    int coluna;
    double valor;
} ElementoCOO;

ElementoCOO* matrizParaCOO(int N, int M, double D[N][M], int *nnz){
    int i, j;
    *nnz = 0;

    // Conta os elementos não nulos
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (D[i][j] != 0)
                (*nnz)++;

    // Aloca o vetor COO
    ElementoCOO *coo = malloc(*nnz * sizeof(ElementoCOO));
    if (coo == NULL && *nnz > 0) {
        printf("Erro de alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }

    // Preenche o vetor
    int k = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (D[i][j] != 0) {
                coo[k].linha = i;
                coo[k].coluna = j;
                coo[k].valor = D[i][j];
                k++;
            }
        }
    }

    return coo;
}

int main(){
    int N = 4;
    int M = 4;

    double D[4][4] = {
        {0, 0, 5, 0},
        {0, 8, 0, 0},
        {3, 0, 0, 7},
        {0, 0, 0, 0}
    };

    int nnz;
    ElementoCOO *coo = matrizParaCOO(N, M, D, &nnz);

    printf("Representacao COO:\n");
    printf("Linha  Coluna  Valor\n");
    for (int i = 0; i < nnz; i++) {
        printf("%5d  %6d  %5.1f\n",
               coo[i].linha,
               coo[i].coluna,
               coo[i].valor);
    }

    free(coo);

    return 0;
}
