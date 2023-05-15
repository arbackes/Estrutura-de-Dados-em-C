//Arquivo ListaEstGen.h
#define MAX 100

typedef struct lista Lista;

Lista* criaLista(int TAMANHO_TIPO);

void liberaLista(Lista* li);

int buscaLista(Lista* li, int chave, void *dados);

int insereLista(Lista* li, int chave, void *dados);

int removeLista(Lista* li, int chave);

void imprimeLista(Lista* li, void (*formato_impressao)(void *));

