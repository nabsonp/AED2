typedef struct no {
    int d;
    struct no *esq;
    struct no *dir;
} no;

void criarArvore(no *r);

no* inserirEmAVL(no *r, int d);

int alturaArvore(no* n);

int  fb(no *n);

no* balanceiaNo(no* raiz);
