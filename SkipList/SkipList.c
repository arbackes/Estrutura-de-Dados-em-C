#include <stdio.h>
#include <stdlib.h>
#include "SkipList.h"

struct NO{
    int chave;
    struct NO **prox;
};

struct SkipList{
    // N�vel m�ximo
	int NivelMAX;
	// Fra��o dos n�s
	float P;
	// N�vel atual do n�
	int nivel;
	// ponteiro para o n� cabe�alho
	struct NO *inicio;
};

struct NO* novoNo(int chave, int nivel){
	struct NO* novo = malloc(sizeof(struct NO));
	if(novo != NULL){
        // Cria um novo n� apontando para NULL
        novo->chave = chave;
        novo->prox = malloc((nivel+1)* sizeof(struct NO*));
        int i;
        for(i=0; i<(nivel+1); i++)
            novo->prox[i] = NULL;
	}
	return novo;
}

SkipList* criaSkipList(int NivelMAX, float P){
    SkipList *sk = (SkipList*) malloc(sizeof(SkipList));
    if(sk != NULL){
        sk->NivelMAX = NivelMAX;
        sk->P = P;
        sk->nivel = 0;
        // cria o cabe�alho com chave -1
        // a SkipList armazena apenas valores positivos
        sk->inicio = novoNo(-1, NivelMAX);
    }

	return sk;
}

int sorteiaNivel(SkipList *sk){
    // Sorteia o n�vel para o n�
	float r = (float)rand()/RAND_MAX;
	int nivel = 0;
	while(r < sk->P && nivel < sk->NivelMAX){
		nivel++;
		r = (float)rand()/RAND_MAX;
	}
	return nivel;
}


int buscaSkipList(SkipList *sk, int chave){
    if(sk == NULL)
        return 0;

	struct NO *atual = sk->inicio;

	// Partindo do maior n�vel, v� para o pr�ximo n�
	// enquanto a chave for maior do que a do pr�ximo n�
	// Caso contr�rio, desca um n�vel e continue a busca
	int i;
	for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
	}

	// Acesse o n�vel 0 do pr�ximo n�, que �
	// onde a chave procurada deve estar
	atual = atual->prox[0];
	if(atual != NULL && atual->chave == chave)
		return 1;
    else
        return 0;
}

int insereSkipList(SkipList *sk, int chave){
    if(sk == NULL)
        return 0;

	int i;
	struct NO *atual = sk->inicio;
	// Cria um array de n�s auxiliar apontando para NULL
	struct NO **aux;
	aux = malloc((sk->NivelMAX+1) * sizeof(struct NO*));
	for(i = 0; i <= sk->NivelMAX; i++)
	    aux[i] = NULL;

    // Partindo do maior n�vel, v� para o pr�ximo n�
	// enquanto a chave for maior do que a do pr�ximo n�
	// Caso contr�rio, insira o n� no array auxiliar,
	// desca um n�vel e continue a busca
	for(i = sk->nivel; i >= 0; i--){
		while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
			atual = atual->prox[i];
		aux[i] = atual;
	}

	// Acesse o n�vel 0 do pr�ximo n�, que �
	// onde a chave deve ser inserida
	atual = atual->prox[0];

    // Cria e insere um novo n� se a chave n�o existir
    // Final da lista (atual == NULL) ou
    // entre auxiliar[0] e atual
	if(atual == NULL || atual->chave != chave){
		// Sorteia o n�vel
		int novo_nivel = sorteiaNivel(sk);
		// Cria um novo n� apontando para NULL
		struct NO* novo = novoNo(chave, novo_nivel);
		if(novo == NULL){
            free(aux);
            return 0;
		}

		// Se o n�vel sorteado for maior do que o n�vel
		// atual da SkipList, atualizar os novos n�veis
		// do array auxiliar.
		if(novo_nivel > sk->nivel){
			for(i = sk->nivel+1; i <= novo_nivel; i++)
				aux[i] = sk->inicio;

			// Atualiza o n�vel da SkipList
			sk->nivel = novo_nivel;
		}

		// Insere o n�, arrumando os ponteiros
		for(i = 0; i <= novo_nivel; i++){
			novo->prox[i] = aux[i]->prox[i];
			aux[i]->prox[i] = novo;
		}

		free(aux);
		return 1;
	}

	free(aux);
	return 0;
}

int removeSkipList(SkipList *sk, int chave){
    if(sk == NULL)
        return 0;

	int i;
	struct NO *atual = sk->inicio;
	// Cria um array de n�s auxiliar apontando para NULL
	struct NO **aux;
	aux = malloc((sk->NivelMAX+1) * sizeof(struct NO*));
	for(i = 0; i <= sk->NivelMAX; i++)
	    aux[i] = NULL;

	// Partindo do maior n�vel, v� para o pr�ximo n�
	// enquanto a chave for maior do que a do pr�ximo n�
	// Caso contr�rio, insira o n� no array auxiliar,
	// desca um n�vel e continue a busca
	for(i = sk->nivel; i >= 0; i--){
		while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
			atual = atual->prox[i];
		aux[i] = atual;
	}

	// Acesse o n�vel 0 do pr�ximo n�, que �
	// onde a chave a ser removida deve estar
	atual = atual->prox[0];

	// Achou a chave a ser removida?
	if(atual != NULL && atual->chave == chave){
		// Come�ando no n�vel 0, se o array auxiliar
		// aponta para o n� a ser removido, fa�a ele
		// apontar para o pr�ximo n� (remo��o de lista encadeada)
		for(i = 0; i <= sk->nivel; i++){
			if(aux[i]->prox[i] != atual)
				break;

			aux[i]->prox[i] = atual->prox[i];
		}
		// Remova os n�veis sem elemento
		while(sk->nivel > 0 && sk->inicio->prox[sk->nivel] == NULL)
			sk->nivel--;

		free(atual->prox);
		free(atual);
		free(aux);
		return 1;
	}

	free(aux);
	return 0;
}

void imprimeSkipList(SkipList *sk){
    if(sk == NULL)
        return;
    int i;
	printf("\n*****Skip List*****\n");
	for(i=0; i <= sk->nivel; i++){
		struct NO *no = sk->inicio->prox[i];
		printf("Nivel %d: ",i);
		while(no != NULL){
			printf("%d ",no->chave);
			no = no->prox[i];
		}
		printf("\n");
	}
}

void liberaSkipList(SkipList* sk){
    if(sk == NULL)
        return;

    struct NO *no, *atual;
    atual = sk->inicio->prox[0];
    while(atual != NULL){
        no = atual;
        atual = atual->prox[0];
        free(no->prox);
        free(no);
    }

    free(sk->inicio);
    free(sk);
}

int vaziaSkipList(SkipList* sk){
    if(sk == NULL)
        return 1;

    if(sk->inicio->prox[0] == NULL)
        return 1;
    else
        return 0;
}

int tamanhoSkipList(SkipList* sk){
    if(sk == NULL)
        return 0;

    int cont = 0;
    struct NO *atual;
    atual = sk->inicio->prox[0];
    while(atual != NULL){
        atual = atual->prox[0];
        cont++;
    }
    return cont;
}

