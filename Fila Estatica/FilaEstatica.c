#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h" //inclui os Protótipos

//Definição do tipo Fila
struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Fila* cria_Fila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi);
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    if(Fila_cheia(fi))
        return 0;
    fi->dados[fi->final] = al;
    fi->final = (fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->qtd == 0)
        return 1;
    else
        return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    int n, i = fi->inicio;
    for(n=0; n < fi->qtd; n++){
        printf("Matricula: %d\n",fi->dados[i].matricula);
        printf("Nome: %s\n",fi->dados[i].nome);
        printf("Notas: %f %f %f\n",fi->dados[i].n1,
                                   fi->dados[i].n2,
                                   fi->dados[i].n3);
        printf("-------------------------------\n");
        i = (i + 1) % MAX;
    }
}
