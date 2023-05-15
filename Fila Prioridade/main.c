#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridade.h"

struct paciente{
    char nome[30];
    int prio;
};

int main(){
    struct paciente itens[6] = {{"Andre",1},
                                {"Bianca",2},
                                {"Carlos",5},
                                {"Nilza",10},
                                {"Inacio",9},
                                {"Edu",2}};

    FilaPrio* fp;
    fp = cria_FilaPrio();

    int i;
    for (i=0; i< 6; i++){
        printf("%d) %d %s\n",i,itens[i].prio, itens[i].nome);
        insere_FilaPrio(fp, itens[i].nome,itens[i].prio);
    }

    printf("=================================\n");

    imprime_FilaPrio(fp);

    printf("=================================\n");
    for (i=0; i< 6; i++){
        remove_FilaPrio(fp);
        imprime_FilaPrio(fp);
        printf("=================================\n");
    }

    libera_FilaPrio(fp);

    system("pause");
    return 0;
}
