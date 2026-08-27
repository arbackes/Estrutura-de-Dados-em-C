#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int main(){
    struct aluno aluno, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* lista = CriarLista();
    printf("Tamanho: %d\n\n\n\n",TamanhoDaLista(lista));

    int i;
    for(i=0; i < 4; i++)
        InserirListaOrdenada(lista,a[i]);

    ImprimirLista(lista);
    printf("\n\n\n\n Tamanho: %d\n",TamanhoDaLista(lista));

    for(i=0; i < 4; i++){
        RemoverListaFinal(lista);
        ImprimirLista(lista);
        printf("\n Tamanho: %d\n\n\n",TamanhoDaLista(lista));
    }

    for(i=0; i < 4; i++)
        InserirListaOrdenada(lista,a[i]);
    ImprimirLista(lista);

    LiberarLista(lista);
    system("pause");
    return 0;
}

