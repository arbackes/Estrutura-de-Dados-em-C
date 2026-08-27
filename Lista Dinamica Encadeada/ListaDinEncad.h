// Arquivo: ListaDinEncad.h

// Define a struct do aluno (os dados)
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

// Define que "Lista" é um ponteiro para um "struct elemento"
// (A definição completa do struct elemento fica no arquivo .c)
typedef struct elemento* Lista;

// --- Protótipos das Funções ---
// (Esta é a lista de funções que o main.c pode "enxergar")

Lista* CriarLista();
void LiberaListaDaMemoria(Lista* lista);
int InserirNovoAlunoFInalDaLista(Lista* lista, struct aluno aluno);
int InserirAlunoNoInicio(Lista* lista, struct aluno aluno);
int InserirAlunoEmOrdemCrescente(Lista* lista, struct aluno aluno);
int RemoverAluno(Lista* lista, int matricula);
int RemoverPriemiroAlunoDaLista(Lista* lista);
int RemoverUltimoAlunoDaLista(Lista* lista);
int RetornarTamanhoDaLista(Lista* lista);
int VerificarSeListaEstaVazia(Lista* lista);
int ListaCheia(Lista* lista); // Corrigi o parâmetro 'Lista' para 'lista'
void ImprimirLista(Lista* lista);
int ConsultarAlunoPelaMatricula(Lista* lista, int matricula, struct aluno *aluno);
int ConsultarPosicaoDoAluno(Lista* lista, int posicao, struct aluno *aluno);