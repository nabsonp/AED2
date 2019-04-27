typedef struct no {
    int d;
    struct no *esq;
    struct no *dir;
} no;

void criarArvore(no *r);

no* inserirEmABP(no *r, int d);

void caminhamentoPrefixado(no *r);

void caminhamentoInfixado(no *r);

void caminhamentoPosfixado(no *r);

no* criarArvoreAleatoria(no* r, int tam);
