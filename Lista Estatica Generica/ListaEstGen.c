#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEstGen.h" //inclui os Protótipos

//Definição do tipo lista
struct item{
    int chave;
    void *info;
};

struct lista{
    int qtd, TAMANHO_TIPO;
    struct item dados[MAX];
};

Lista* criaLista(int TAMANHO_TIPO){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
        li->TAMANHO_TIPO = TAMANHO_TIPO;
    }
    return li;
}

void liberaLista(Lista* li){
    int i;
    for(i=0; i< li->qtd; i++){
        free(li->dados[i].info);
    }
    free(li);
}

int buscaLista(Lista* li, int chave, void *dados){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i < li->qtd && li->dados[i].chave != chave)
        i++;

    if(i == li->qtd)//elemento nao encontrado
        return 0;

    memcpy(dados,li->dados[i].info,li->TAMANHO_TIPO);

    return 1;
}


int insereLista(Lista* li, int chave, void *dados){
    if(li == NULL)
        return 0;

    if(li->qtd == MAX)//lista cheia
        return 0;

    void *novo = malloc(li->TAMANHO_TIPO);
    if(novo == NULL)
        return 0;

    memcpy(novo,dados,li->TAMANHO_TIPO);

    int k,i = 0;
    while(i < li->qtd && li->dados[i].chave < chave)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i].chave = chave;
    li->dados[i].info = novo;

    li->qtd++;
    return 1;
}

int removeLista(Lista* li, int chave){
    if(li == NULL)
        return 0;

    if(li->qtd == 0)
        return 0;

    int k,i = 0;
    while(i<li->qtd && li->dados[i].chave != chave)
        i++;

    if(i == li->qtd)//elemento nao encontrado
        return 0;

    free(li->dados[i].info);

    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1;
}

void imprimeLista(Lista* li, void (*formato_impressao)(void *)){
    if(li == NULL)
        return;
    int i;
    for(i=0; i< li->qtd; i++){
        printf("Chave: %d\n",li->dados[i].chave);
        formato_impressao(li->dados[i].info);
    }
}
