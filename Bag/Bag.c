#include <stdio.h>
#include <stdlib.h>
#include "Bag.h" //inclui os Protótipos

//Definição do tipo Bag
struct NO{
    int valor;
    struct NO *prox;
};

//Definição do Nó Descritor
struct descritor{
    struct NO *inicio;
    struct NO *iterator;
    int qtd;
};

Bag* criaBag(){
    Bag* b = (Bag*) malloc(sizeof(Bag));
    if(b != NULL){
        b->inicio = NULL;
        b->qtd = 0;
        b->iterator = NULL;
    }
    return b;
}

void liberaBag(Bag* b){
    if(b != NULL){
        struct NO* no;
        while(b->inicio != NULL){
            no = b->inicio;
            b->inicio = b->inicio->prox;
            free(no);
        }
        free(b);
    }
}

int insereBag(Bag* b, int num){
    if(b == NULL)
        return 0;
    struct NO* no;
    no = (struct NO*) malloc(sizeof(struct NO));
    if(no == NULL)
        return 0;
    no->valor = num;
    no->prox = b->inicio;
    b->inicio = no;
    b->qtd++;
    return 1;
}

int removeBag(Bag* b, int num){
    if(b == NULL)
        return 0;

    int cont = 0;
    struct NO *ant;
    struct NO *no = b->inicio;
    while(no != NULL){
        if(no->valor == num){
            cont++;
            if(b->inicio == no){//remover o primeiro?
                b->inicio = no->prox;
                free(no);
                no = b->inicio;
            }else{
                ant->prox = no->prox;
                free(no);
                no = ant->prox;
            }
        }else{
            ant = no;
            no = no->prox;
        }
    }
    b->qtd = b->qtd - cont;
    return cont;
}

int tamanhoBag(Bag* b){
    if(b == NULL)
        return 0;

    return b->qtd;
}

int consultaBag(Bag* b, int num){
    if(b == NULL)
        return 0;
    struct NO *no = b->inicio;
    int cont = 0;
    while(no != NULL){
        if(no->valor == num)
            cont++;
        no = no->prox;
    }

    return cont;
}

void imprimeBag(Bag* b){
    if(b == NULL)
        return;
    struct NO* no = b->inicio;
    while(no != NULL){
        printf("%d, ",no->valor);
        no = no->prox;
    }
}

void beginBag(Bag *b){
    if(b == NULL)
        return;
    b->iterator = b->inicio;
}

int endBag(Bag *b){
    if(b == NULL)
        return 1;
    if(b->iterator == NULL)
        return 1;
    else
        return 0;
}

void nextBag(Bag *b){
    if(b == NULL)
        return;
    if(b->iterator != NULL)
        b->iterator = b->iterator->prox;
}

void getItemBag(Bag *b, int *num){
    if(b == NULL)
        return;
    if(b->iterator != NULL)
        *num = b->iterator->valor;
}
