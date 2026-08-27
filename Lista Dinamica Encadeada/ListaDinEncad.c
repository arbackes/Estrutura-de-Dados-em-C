#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os protótipos

// Definição do nó da lista
struct PrimeiroAlunoDalista
{
    struct Aluno informacoesDoluno;
    struct PrimeiroAlunoDalista *prox;
};
typedef struct PrimeiroAlunoDalista AlunoDalista;

// Cria uma lista vazia
Lista *CriarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

// Libera toda a memória da lista
void LiberaListaDaMemoria(Lista *lista)
{
    if (lista != NULL)
    {
        AlunoDalista *no;
        while ((*lista) != NULL)
        {
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
        }
        free(lista);
    }
}

// Consulta aluno por posição
int ConsultarPosicaoDoAluno(Lista *lista, int posicao, struct aluno *aluno)
{
    if (lista == NULL || posicao <= 0)
        return 0;

    AlunoDalista *no = *lista;
    int i = 1;
    while (no != NULL && i < posicao)
    {
        no = no->prox;
        i++;
    }

    if (no == NULL)
        return 0;

    *aluno = no->informacoesDoluno;
    return 1;
}

// Consulta aluno pela matrícula
int ConsultarAlunoPelaMatricula(Lista *lista, int matricula, struct aluno *aluno)
{
    if (lista == NULL)
        return 0;

    AlunoDalista *no = *lista;
    while (no != NULL && no->informacoesDoluno.matricula != matricula)
        no = no->prox;

    if (no == NULL)
        return 0;

    *aluno = no->informacoesDoluno;
    return 1;
}

// Insere aluno no final da lista
int InserirNovoAlunoFInalDaLista(Lista *lista, struct aluno aluno)
{
    if (lista == NULL)
        return 0;

    AlunoDalista *no = (AlunoDalista *)malloc(sizeof(AlunoDalista));
    if (no == NULL)
        return 0;

    no->informacoesDoluno = aluno;
    no->prox = NULL;

    if (*lista == NULL)
    {
        *lista = no;
    }
    else
    {
        AlunoDalista *aux = *lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
    }

    return 1;
}

// Insere aluno no início da lista
int InserirAlunoNoInicio(Lista *lista, struct aluno aluno)
{
    if (lista == NULL)
        return 0;

    AlunoDalista *no = (AlunoDalista *)malloc(sizeof(AlunoDalista));
    if (no == NULL)
        return 0;

    no->informacoesDoluno = aluno;
    no->prox = *lista;
    *lista = no;

    return 1;
}

// Insere aluno em ordem crescente de matrícula
int InserirAlunoEmOrdemCrescente(Lista *lista, struct aluno aluno)
{
    if (lista == NULL)
        return 0;

    AlunoDalista *no = (AlunoDalista *)malloc(sizeof(AlunoDalista));
    if (no == NULL)
        return 0;

    no->informacoesDoluno = aluno;

    if (*lista == NULL || (*lista)->informacoesDoluno.matricula > aluno.matricula)
    {
        no->prox = *lista;
        *lista = no;
        return 1;
    }

    AlunoDalista *atual = *lista;
    while (atual->prox != NULL && atual->prox->informacoesDoluno.matricula < aluno.matricula)
        atual = atual->prox;

    no->prox = atual->prox;
    atual->prox = no;

    return 1;
}


int RemoverAluno(Lista *lista, int matricula)
{
    if (lista == NULL || *lista == NULL)
        return 0;

    AlunoDalista *atual = *lista;
    AlunoDalista *ant = NULL;

    while (atual != NULL && atual->informacoesDoluno.matricula != matricula)
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0;

    if (ant == NULL)
        *lista = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);
    return 1;
}

// Remove o primeiro aluno
int RemoverPriemiroAlunoDaLista(Lista *lista)
{
    if (lista == NULL || *lista == NULL)
        return 0;

    AlunoDalista *no = *lista;
    *lista = no->prox;
    free(no);
    return 1;
}

// Remove o último aluno
int RemoverUltimoAlunoDaLista(Lista *lista)
{
    if (lista == NULL || *lista == NULL)
        return 0;

    AlunoDalista *atual = *lista;
    AlunoDalista *ant = NULL;

    while (atual->prox != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }

    if (ant == NULL)
        *lista = NULL;
    else
        ant->prox = NULL;

    free(atual);
    return 1;
}

// Retorna o tamanho da lista
int RetornarTamanhoDaLista(Lista *lista)
{
    if (lista == NULL)
        return 0;

    int cont = 0;
    AlunoDalista *no = *lista;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

// Lista nunca cheia (dinâmica)
int ListaCheia(Lista *lista)
{
    return 0;
}


int VerificarSeListaEstaVazia(Lista *lista)
{
    return (lista == NULL || *lista == NULL);
}

void ImprimirLista(Lista *lista)
{
    if (lista == NULL)
        return;

    AlunoDalista *no = *lista;
    while (no != NULL)
    {
        printf("Matrícula: %d\n", no->informacoesDoluno.matricula);
        printf("Nome: %s\n", no->informacoesDoluno.nome);
        printf("Notas: %.2f %.2f %.2f\n",
               no->informacoesDoluno.n1,
               no->informacoesDoluno.n2,
               no->informacoesDoluno.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
