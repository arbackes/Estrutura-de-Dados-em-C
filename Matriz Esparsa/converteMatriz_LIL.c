#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int coluna;
    double valor;
    struct No *prox;
} No;

typedef struct {
    int N;
    int M;
    No **linhas;
} LIL;

LIL matrizParaLIL(int N, int M, double D[N][M]){
    LIL lil;
    lil.N = N;
    lil.M = M;
    lil.linhas = (No **) malloc(N * sizeof(No*));

    if (lil.linhas == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++)
        lil.linhas[i] = NULL;

    for (int i = 0; i < N; i++) {
        No *fim = NULL;
        for (int j = 0; j < M; j++) {
            if (D[i][j] != 0) {
                No *novo = (No *) malloc(sizeof(No));
                if (novo == NULL) {
                    printf("Erro de alocacao de memoria.\n");
                    exit(EXIT_FAILURE);
                }

                novo->coluna = j;
                novo->valor = D[i][j];
                novo->prox = NULL;

                if (lil.linhas[i] == NULL) {
                    lil.linhas[i] = novo;
                    fim = novo;
                }
                else {
                    fim->prox = novo;
                    fim = novo;
                }
            }
        }
    }
    return lil;
}

void imprimirLIL(LIL lil){
    for (int i = 0; i < lil.N; i++) {
        printf("Linha %d:", i);
        No *aux = lil.linhas[i];
        while (aux != NULL) {
            printf(" -> (%d, %.1f)",
                   aux->coluna,
                   aux->valor);

            aux = aux->prox;
        }
        printf("\n");
    }
}

void liberarLIL(LIL *lil){
    for (int i = 0; i < lil->N; i++) {
        No *aux = lil->linhas[i];
        while (aux != NULL) {
            No *temp = aux;
            aux = aux->prox;
            free(temp);
        }
    }
    free(lil->linhas);
}

int main(){
    double D[4][4] = {
        {0, 0, 5, 0},
        {0, 8, 0, 0},
        {3, 0, 0, 7},
        {0, 0, 0, 0}
    };

    LIL lil = matrizParaLIL(4, 4, D);

    imprimirLIL(lil);

    liberarLIL(&lil);

    return 0;
}
