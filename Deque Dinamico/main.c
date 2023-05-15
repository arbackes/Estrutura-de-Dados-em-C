#include <stdio.h>
#include <stdlib.h>
#include "DequeDinamico.h"

int main(){
    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Deque* dq = cria_Deque();
    printf("Tamanho: %d\n\n\n\n",tamanho_Deque(dq));
    int i;
    for(i=0; i < 4; i++){
        if(i%2 == 0){
            insereInicio_Deque(dq,a[i]);
            consultaInicio_Deque(dq,&al);
        }else{
            insereFinal_Deque(dq,a[i]);
            consultaFinal_Deque(dq,&al);
        }
        printf("Consulta: %d \t %s\n",al.matricula,al.nome);
    }

    imprime_Deque(dq);
    printf("Tamanho: %d\n\n\n\n",tamanho_Deque(dq));

    removeInicio_Deque(dq);
    removeInicio_Deque(dq);
    imprime_Deque(dq);
    printf("Tamanho: %d\n\n\n\n",tamanho_Deque(dq));

    for(i=0; i < 4; i++){
        if(i%2 == 0){
            insereInicio_Deque(dq,a[i]);
            consultaInicio_Deque(dq,&al);
        }else{
            insereFinal_Deque(dq,a[i]);
            consultaFinal_Deque(dq,&al);
        }
        printf("Consulta: %d \t %s\n",al.matricula,al.nome);
    }
    imprime_Deque(dq);
    printf("Tamanho: %d\n\n\n\n",tamanho_Deque(dq));

    removeFinal_Deque(dq);
    removeFinal_Deque(dq);
    imprime_Deque(dq);
    printf("Tamanho: %d\n\n\n\n",tamanho_Deque(dq));

    libera_Deque(dq);
    system("pause");
    return 0;
}
