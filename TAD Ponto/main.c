#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"
int main(){
    float d;
    Ponto *p,*q;
    //Ponto r; //ERRO
    p = pto_cria(10,21);
    q = pto_cria(7,25);
    //q->x = 2; //ERRO
    d = pto_distancia(p,q);
    printf("Distancia entre pontos: %f\n",d);

    pto_libera(q);
    pto_libera(p);

    system("pause");
    return 0;
}
