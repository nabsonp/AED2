typedef struct no {
    int d;
    struct no *esq;
    struct no *dir;
} no;

no* criarArvore();

no* inserirEmABP(no *r, int d);

void caminhamentoPrefixado(no *r);

void caminhamentoInfixado(no *r);

void caminhamentoPosfixado(no *r);

no* explodirArvore(no* r);

no* criarArvoreAleatoria(no* r, int tam);

no* recebimentoDePacotes(no* r, int tam, int pacotes[]);

no* converterVetorABP(no* r, int tam, int vet[]);

no* buscaABP(no *r, int v);
