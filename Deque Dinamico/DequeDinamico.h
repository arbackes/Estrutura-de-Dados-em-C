//Arquivo DequeDinamico.h
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct Deque Deque;

Deque* cria_Deque();
void libera_Deque(Deque* dq);
int consultaInicio_Deque(Deque* dq, struct aluno *al);
int consultaFinal_Deque(Deque* dq, struct aluno *al);
int insereFinal_Deque(Deque* dq, struct aluno al);
int insereInicio_Deque(Deque* dq, struct aluno al);
int removeInicio_Deque(Deque* dq);
int removeFinal_Deque(Deque* dq);
int tamanho_Deque(Deque* dq);
int Deque_vazio(Deque* dq);
int Deque_cheio(Deque* dq);
void imprime_Deque(Deque* dq);

