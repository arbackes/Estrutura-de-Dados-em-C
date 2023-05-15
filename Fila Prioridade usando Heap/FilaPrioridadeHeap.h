
//Arquivo FilaPrioridadeHeap.h
#define MAX 100

typedef struct fila_prioridade FilaPrio;

FilaPrio* cria_FilaPrio();
void libera_FilaPrio(FilaPrio* fp);
int consulta_FilaPrio(FilaPrio* fp, char* nome);
int insere_FilaPrio(FilaPrio* fp, char *nome, int  prioridade);
int remove_FilaPrio(FilaPrio* fp);
int tamanho_FilaPrio(FilaPrio* fp);
int estaCheia_FilaPrio(FilaPrio* fp);
int estaVazia_FilaPrio(FilaPrio* fp);
void imprime_FilaPrio(FilaPrio* fp);
