//Arquivo Grafo.h

typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);

//void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont);
void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado);
void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado);
void menorCaminho_Grafo(Grafo *gr, int ini, int *antecessor, float *distancia);

void imprime_Grafo(Grafo *gr);
