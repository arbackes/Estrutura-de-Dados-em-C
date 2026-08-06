#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *valores;
    int *colunas;
    int *linhas;
    int nnz;  // quantidade de elementos não nulos
    int N;    // número de linhas
    int M;    // número de colunas
} CSR;


CSR matrizParaCSR(int N, int M, double D[N][M]){
    CSR csr;
    csr.N = N;
    csr.M = M;

    //Conta os elementos não nulos
    csr.nnz = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (D[i][j] != 0)
                csr.nnz++;

    //Aloca memória
    csr.valores = malloc(csr.nnz * sizeof(int));
    csr.colunas = malloc(csr.nnz * sizeof(int));
    csr.linhas  = malloc((N + 1) * sizeof(int));

    //Constrói o vetor linhas
    int k = 0;
    for (int i = 0; i < N; i++) {
        //Primeiro elemento da linha i
        csr.linhas[i] = k;

        for (int j = 0; j < M; j++) {
            if (D[i][j] != 0) {
                csr.valores[k] = D[i][j];
                csr.colunas[k] = j;
                k++;
            }
        }
    }
    //Final do vetor de elementos
    csr.linhas[N] = k;
    return csr;
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

    // Conversão para CSR
    CSR csr = matrizParaCSR(N, M, D);

    // Exibe os vetores
    printf("Valores:\n");
    for (int i = 0; i < csr.nnz; i++)
        printf("%.1f ", csr.valores[i]);
    printf("\n\n");

    printf("Colunas:\n");
    for (int i = 0; i < csr.nnz; i++)
        printf("%d ", csr.colunas[i]);
    printf("\n\n");

    printf("Linhas:\n");
    for (int i = 0; i <= csr.N; i++)
        printf("%d ", csr.linhas[i]);
    printf("\n");

    // Libera memória
    free(csr.valores);
    free(csr.colunas);
    free(csr.linhas);

    return 0;
}
