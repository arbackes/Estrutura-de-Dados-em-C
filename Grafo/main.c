#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    int eh_digrafo = 1;
    Grafo* gr = cria_Grafo(5, 5, 0);

    insereAresta(gr, 0, 1, eh_digrafo, 0);
    insereAresta(gr, 1, 3, eh_digrafo, 0);
    insereAresta(gr, 1, 2, eh_digrafo, 0);
    insereAresta(gr, 2, 4, eh_digrafo, 0);
    insereAresta(gr, 3, 0, eh_digrafo, 0);
    insereAresta(gr, 3, 4, eh_digrafo, 0);
    insereAresta(gr, 4, 1, eh_digrafo, 0);

    imprime_Grafo(gr);
    printf("\nBusca \n");
    int vis[5];
    // http://www.thelearningpoint.net/computer-science/algorithms-graph-traversal---breadth-first-search-with-c-program-source-code
    //buscaProfundidade_Grafo(gr, 0, vis);
    //buscaLargura_Grafo(gr, 0, vis);

    int i,ant[5];
    float dist[5];
    menorCaminho_Grafo(gr, 0, ant, dist);
    for(i=0; i<5; i++)
        printf("%d: %d -> %f\n",i,ant[i],dist[i]);

    libera_Grafo(gr);

    system("pause");
    return 0;
}
