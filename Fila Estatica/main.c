#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"
int main(){
    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Fila* fi = cria_Fila();
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    int i;
    for(i=0; i < 4; i++){
        insere_Fila(fi,a[i]);
        consulta_Fila(fi,&al);
        printf("Consulta: %d \t %s\n",al.matricula,al.nome);
    }

    imprime_Fila(fi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));

    for(i=0; i < 4; i++){
        remove_Fila(fi);
        consulta_Fila(fi,&al);
        printf("Consulta: %d \t %s\n",al.matricula,al.nome);
    }
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    for(i=0; i < 4; i++)
        insere_Fila(fi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    libera_Fila(fi);
    system("pause");
    return 0;
}


