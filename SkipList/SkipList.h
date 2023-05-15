
typedef struct SkipList SkipList;

SkipList* criaSkipList(int MAXLVL, float P);
void liberaSkipList(SkipList* sk);
int insereSkipList(SkipList *sk, int key);
int removeSkipList(SkipList *sk, int key);
int buscaSkipList(SkipList *sk, int key);
int tamanhoSkipList(SkipList* sk);
int vaziaSkipList(SkipList* sk);
void imprimeSkipList(SkipList *sk);

//struct NO* novoNo(int key, int level);
