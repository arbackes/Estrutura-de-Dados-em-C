#include <stdio.h>
#include <stdlib.h>
#include "Complexos.h"
void imprime(cplx *z){
    float x,y;
    real(z,&x);
    imag(z,&y);
    printf("Complexo = %.2f + %.2f i\n",x,y);
}
int main(){
    cplx *z1,*z2=NULL;

    z1 = cria_cplx(12,3);
    z2 = cria_cplx(1,31);
    imprime(z1);
    imprime(z2);

    if(igual_cplx(z1,z2)==1)
        printf("Numeros iguais\n");
    else
        printf("Numeros diferentes\n");

    oposto_cplx(z1,z2);
    printf("Oposto\n");
    imprime(z2);

    soma_cplx(z1,z1,z2);
    printf("Soma\n");
    imprime(z2);

    subtracao_cplx(z2,z1,z2);
    printf("Subtracao\n");
    imprime(z2);

    produto_cplx(z1,z1,z2);
    printf("Produto\n");
    imprime(z2);

    destroi_cplx(z1);
    destroi_cplx(z2);

    return 0;
}
