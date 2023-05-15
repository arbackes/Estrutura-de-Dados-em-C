#include <stdio.h>
#include <stdlib.h>
#include "DequeDinamico.h" //inclui os Protótipos
//Definição do tipo Deque
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Definição do Nó Descritor do Deque
struct Deque{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Deque* cria_Deque(){
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if(dq != NULL){
        dq->final = NULL;
        dq->inicio = NULL;
        dq->qtd = 0;
    }
    return dq;
}

void libera_Deque(Deque* dq){
    if(dq != NULL){
        Elem* no;
        while(dq->inicio != NULL){
            no = dq->inicio;
            dq->inicio = dq->inicio->prox;
            free(no);
        }
        free(dq);
    }
}

int tamanho_Deque(Deque* dq){
    if(dq == NULL)
        return 0;
    return dq->qtd;
}

int Deque_vazio(Deque* dq){
    if(dq == NULL)
        return 1;
    if(dq->inicio == NULL)
        return 1;
    return 0;
}

int Deque_cheio(Deque* dq){
    return 0;
}

int insereFinal_Deque(Deque* dq, struct aluno al){
    if(dq == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(dq->final == NULL){//Deque vazio
        no->ant = NULL;
        dq->inicio = no;
    }
    else{
        no->ant = dq->final;
        dq->final->prox = no;
    }
    dq->final = no;
    dq->qtd++;
    return 1;
}

int insereInicio_Deque(Deque* dq, struct aluno al){
    if(dq == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = dq->inicio;
    no->ant = NULL;
    if(dq->inicio == NULL)
        dq->final = no;
    else//Deque não vazio: apontar para o anterior!
        dq->inicio->ant = no;
    dq->inicio = no;
    dq->qtd++;
    return 1;
}


int removeInicio_Deque(Deque* dq){
    if(dq == NULL)
        return 0;
    if(dq->inicio == NULL)//Deque vazio
        return 0;
    Elem *no = dq->inicio;
    dq->inicio = dq->inicio->prox;
    if(dq->inicio == NULL)//Deque ficou vazio
        dq->final = NULL;
    else
        dq->inicio->ant = NULL;
    free(no);
    dq->qtd--;
    return 1;
}

int removeFinal_Deque(Deque* dq){
    if(dq == NULL)
        return 0;
    if(dq->inicio == NULL)//Deque vazio
        return 0;
    Elem *no = dq->final;

    if(no == dq->inicio){//remover o primeiro?
        dq->inicio = NULL;
        dq->final = NULL;
    }else{
        no->ant->prox = NULL;
        dq->final = no->ant;
    }
    free(no);
    dq->qtd--;
    return 1;
}

int consultaInicio_Deque(Deque* dq, struct aluno *al){
    if(dq == NULL)
        return 0;
    if(dq->inicio == NULL)//Deque vazio
        return 0;
    *al = dq->inicio->dados;
    return 1;
}

int consultaFinal_Deque(Deque* dq, struct aluno *al){
    if(dq == NULL)
        return 0;
    if(dq->final == NULL)//Deque vazio
        return 0;
    *al = dq->final->dados;
    return 1;
}

void imprime_Deque(Deque* dq){
    if(dq == NULL)
        return;
    Elem* no = dq->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

