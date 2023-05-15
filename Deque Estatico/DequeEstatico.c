#include <stdio.h>
#include <stdlib.h>
#include "DequeEstatico.h" //inclui os Protótipos

//Definição do tipo Deque
struct Deque{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Deque* cria_Deque(){
    Deque *dq;
    dq = (Deque*) malloc(sizeof(struct Deque));
    if(dq != NULL){
        dq->inicio = 0;
        dq->final = 0;
        dq->qtd = 0;
    }
    return dq;
}

void libera_Deque(Deque* dq){
    free(dq);
}

int tamanho_Deque(Deque* dq){
    if(dq == NULL)
        return -1;
    return dq->qtd;
}

int Deque_cheio(Deque* dq){
    if(dq == NULL)
        return -1;
    if (dq->qtd == MAX)
        return 1;
    else
        return 0;
}

int Deque_vazia(Deque* dq){
    if(dq == NULL)
        return -1;
    if (dq->qtd == 0)
        return 1;
    else
        return 0;
}

int consultaInicio_Deque(Deque* dq, struct aluno *al){
    if(dq == NULL || dq->qtd == 0)
        return 0;
    *al = dq->dados[dq->inicio];
    return 1;
}

int consultaFinal_Deque(Deque* dq, struct aluno *al){
    if(dq == NULL || dq->qtd == 0)
        return 0;
    int pos = dq->final-1;
    if(pos < 0)
        pos = MAX-1;
    *al = dq->dados[pos];
    return 1;
}

int insereFinal_Deque(Deque* dq, struct aluno al){
    if(dq == NULL || dq->qtd == MAX)
        return 0;
    dq->dados[dq->final] = al;
    dq->final = (dq->final+1)%MAX;
    dq->qtd++;
    return 1;
}

int insereInicio_Deque(Deque* dq, struct aluno al){
    if(dq == NULL || dq->qtd == MAX)
        return 0;
    dq->inicio--;
    if(dq->inicio < 0)
        dq->inicio = MAX-1;
    dq->dados[dq->inicio] = al;
    dq->qtd++;
    return 1;
}

int removeInicio_Deque(Deque* dq){
    if(dq == NULL || dq->qtd == 0)
        return 0;
    dq->inicio = (dq->inicio+1)%MAX;
    dq->qtd--;
    return 1;
}

int removeFinal_Deque(Deque* dq){
    if(dq == NULL || dq->qtd == 0)
        return 0;
    dq->final--;
    if(dq->final < 0)
        dq->final = MAX-1;
    dq->qtd--;
    return 1;
}

void imprime_Deque(Deque* dq){
    if(dq == NULL)
        return;
    int n, i = dq->inicio;
    for(n=0; n < dq->qtd; n++){
        printf("Matricula: %d\n",dq->dados[i].matricula);
        printf("Nome: %s\n",dq->dados[i].nome);
        printf("Notas: %f %f %f\n",dq->dados[i].n1,
                                   dq->dados[i].n2,
                                   dq->dados[i].n3);
        printf("-------------------------------\n");
        i = (i + 1) % MAX;
    }
}

