#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

int main(){
    int tamanho = 1024;
    Hash *tabela = criaHash(tamanho);


    struct aluno al, a[4] = {{12352,"Andre",9.5,7.8,8.5},//64
                         {7894,"Ricardo",7.5,8.7,6.8},//726
                         {3451,"Bianca",9.7,6.7,8.4},//379
                         {5293,"Ana",5.7,6.1,7.4}};//173

    int i;
    for(i=0; i < 4; i++){
        insereHash_SemColisao(tabela,a[i]);
    }

    printf("------------\n\n");

    buscaHash_SemColisao(tabela, 12352, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_SemColisao(tabela, 3451, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_SemColisao(tabela, 5293, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    liberaHash(tabela);

    return 0;
}
