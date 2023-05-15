#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDesc.h"
int main(){
    struct aluno a1,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_final(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));


    for(i=0; i < 4; i++){
        if (consulta_lista_pos(li, i+1, &a1))
            printf("ok: %s\n",a1.nome);
        else
            printf("erro: %s\n",a1.nome);

    }

//    imprime_lista(li);
//    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));
//
    for(i=1; i <= 6; i++){
        //remove_lista(li,i+1);
        if(!remove_lista_final(li))
            printf("Erro!!!!!!!!!\n");
        imprime_lista(li);
        printf("\n\n======================\n\n");
    }
//    for(i=0; i < 4; i++)
//        insere_lista_ordenada(li,a[i]);
//
//    imprime_lista(li);

    for(i=0; i < 2; i++)
        insere_lista_final(li,a[i]);

    imprime_lista(li);

    libera_lista(li);
    system("pause");
    return 0;
}
