#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int linha;
    int coluna;
    double valor;
    struct No *prox;
} No;

No *matrizParaLista(int N, int M, double D[N][M]){
    No *inicio = NULL;
    No *fim = NULL;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (D[i][j] != 0) {
                No *novo = (No *) malloc(sizeof(No));

                if (novo == NULL) {
                    printf("Erro de alocacao de memoria.\n");
                    exit(EXIT_FAILURE);
                }

                novo->linha = i;
                novo->coluna = j;
                novo->valor = D[i][j];
                novo->prox = NULL;

                if (inicio == NULL) {
                    inicio = novo;
                    fim = novo;
                }
                else {
                    fim->prox = novo;
                    fim = novo;
                }
            }
        }
    }

    return inicio;
}

// Imprime a lista
void imprimirLista(No *lista){
    while (lista != NULL) {
        printf("(%d,%d) = %.1f\n",
               lista->linha,
               lista->coluna,
               lista->valor);
        lista = lista->prox;
    }
}

// Libera a memória
void liberarLista(No *lista){
    No *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main(){
    double D[4][4] = {
        {0, 0, 5, 0},
        {0, 8, 0, 0},
        {3, 0, 0, 7},
        {0, 0, 0, 0}
    };

    No *lista = matrizParaLista(4, 4, D);

    printf("Lista encadeada:\n\n");
    imprimirLista(lista);
    liberarLista(lista);

    return 0;
}
