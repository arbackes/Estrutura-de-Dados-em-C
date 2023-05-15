#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridadeHeap.h"

struct paciente{
    char nome[30];
    int prio;
};

int main(){
    struct paciente itens[6] = {{"Andre",1},
                                {"Bianca",2},
                                {"Carlos",5},
                                {"Nilza",8},
                                {"Inacio",6},
                                {"Edu",4}};

    FilaPrio* fp;
    fp = cria_FilaPrio();

    int i;
    for (i=0; i< 6; i++){
        printf("%d) %d %s\n",i,itens[i].prio, itens[i].nome);
        insere_FilaPrio(fp, itens[i].nome,itens[i].prio);
    }

    printf("=================================\n");

    imprime_FilaPrio(fp);

    //teste
    printf("=================================\n");
    insere_FilaPrio(fp, "Teste",9);
    imprime_FilaPrio(fp);

    printf("=================================\n");
    remove_FilaPrio(fp);
    imprime_FilaPrio(fp);

    printf("=================================\n");
    for (i=0; i< 6; i++){
        char nome[30];
        consulta_FilaPrio(fp, nome);
        printf("%d) %s\n",i,nome);
        remove_FilaPrio(fp);
    }

    libera_FilaPrio(fp);

    system("pause");
    return 0;
}
