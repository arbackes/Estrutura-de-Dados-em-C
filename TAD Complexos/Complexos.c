#include <math.h>
#include <stdlib.h>
#include "Complexos.h"
struct complexo{
    float r,i;
};

cplx* cria_cplx(float r, float i){
    cplx* c;
    c = (cplx*) malloc(sizeof(struct complexo));
    if(c!=NULL){
        c->r = r;
        c->i = i;
    }
    return c;
}
void destroi_cplx(cplx* c){
    free(c);
}

int real(cplx* c, float *r){
    if(c == NULL)
        return 0;
    *r = c->r;
    return 1;
}
int imag(cplx* c, float *i){
    if(c == NULL)
        return 0;
    *i = c->i;
    return 1;
}

int igual_cplx(cplx*c1,cplx*c2){
    //if(!c1 || !c2)
    if(c1 == NULL || c2 == NULL)
        return 0;
    //return (c1->r == c2->r && c1->i == c2->i);
    if(c1->r == c2->r && c1->i == c2->i)
        return 1;
    else
        return 0;
}

int oposto_cplx(cplx*c,cplx*res){
    if(c == NULL || res == NULL)
        return 0;
    res->r = -(c->r);
    res->i = -(c->i);
    return 1;
}

int soma_cplx(cplx*c1,cplx*c2,cplx*res){
    if(c1==NULL || c2==NULL || res==NULL)
        return 0;
    res->r = c1->r + c2->r;
    res->i = c1->i + c2->i;
    return 1;
}

int subtracao_cplx(cplx*c1,cplx*c2,cplx*res){
    if(c1==NULL || c2==NULL || res==NULL)
        return 0;
    res->r = c1->r - c2->r;
    res->i = c1->i - c2->i;
    return 1;
}

int produto_cplx(cplx*c1,cplx*c2,cplx*res){
    if(c1==NULL || c2==NULL || res==NULL)
        return 0;
    res->r = (c1->r * c2->r) - (c1->i * c2->i);
    res->i = (c1->r * c2->i) + (c1->i * c2->r);
    return 1;
}

int modulo_cplx(cplx*c,float *res){
    if(c == NULL)
        return 0;
    *res = sqrt(pow(c->r,2) + pow(c->i,2));
    return 1;
}

int inverso_cplx(cplx*c1,cplx*res){
    if(c1==NULL || res==NULL)
        return 0;
    float m = pow(c1->r,2) + pow(c1->i,2);
    res->r = c1->r/m;
    res->i = c1->i/m;
    return 1;
}

int divisao_cplx(cplx*c1,cplx*c2,cplx*res){
    if(c1==NULL || c2==NULL || res==NULL)
        return 0;
    float m = pow(c2->r,2) + pow(c2->i,2);
    float r = c2->r/m;
    float i = c2->i/m;
    res->r = (c1->r * r) - (c1->i * i);
    res->i = (c1->r * i) + (c1->i * r);
    return 1;
}

int conj_cplx(cplx*c1,cplx*res){
    if(c1 == NULL || res == NULL)
        return 0;
    res->r = c1->r;
    res->i = -(c1->i);
    return 1;
}
