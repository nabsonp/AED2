typedef struct no {
    int d;
    struct no *esq;
    struct no *dir;
} no;

void criarArvore(no *r);

no* inserirEmAVL(no *r, int d);

void caminhamentoPrefixado(no *r);

void caminhamentoInfixado(no *r);

void caminhamentoPosfixado(no *r);

int alturaArvore(no* n);

int  fb(no *n);

no* balanceiaNo(no* raiz);
