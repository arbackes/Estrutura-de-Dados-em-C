#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();
    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n");

    for(i=0; i < 5; i++){
        if (!remove_lista_otimizado(li,i))
            printf("Erro\n");

        imprime_lista(li);
        printf("\n\n\n\n");
    }

    libera_lista(li);
    system("pause");
    return 0;
}

