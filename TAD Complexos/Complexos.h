typedef struct complexo cplx;

cplx* cria_cplx(float r, float i);
void destroi_cplx(cplx* c);
int real(cplx* c, float *r);
int imag(cplx* c, float *i);
int igual_cplx(cplx*c1,cplx*c2);
int oposto_cplx(cplx*c,cplx*res);
int soma_cplx(cplx*c1,cplx*c2,cplx*res);
int subtracao_cplx(cplx*c1,cplx*c2,cplx*res);
int produto_cplx(cplx*c1,cplx*c2,cplx*res);
int modulo_cplx(cplx*c,float *res);
int divisao_cplx(cplx*c1,cplx*c2,cplx*res);
int inverso_cplx(cplx*c1,cplx*res);
int conj_cplx(cplx*c1,cplx*res);
