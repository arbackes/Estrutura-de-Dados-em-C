//Arquivo Bag.h

typedef struct descritor Bag;

Bag* criaBag();
void liberaBag(Bag* b);
int insereBag(Bag* b, int num);
int removeBag(Bag* b, int num);
int tamanhoBag(Bag* b);
void imprimeBag(Bag* b);
int consultaBag(Bag* b, int num);

void beginBag(Bag *b);
int endBag(Bag *b);
void nextBag(Bag *b);
void getItemBag(Bag *b, int *num);
