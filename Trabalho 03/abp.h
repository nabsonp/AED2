typedef struct no {
    float d;
    int indice;
    int altura;
    struct no *esq;
    struct no *dir;
} no;

no* criarArvore();

no* inserirEmABP(no *r, int d, int indice);

void caminhamentoPrefixadoABP(no *r);

void caminhamentoInfixadoABP(no *r);

void caminhamentoPosfixadoABP(no *r);

no* explodirArvore(no* r);

no* criarArvoreAleatoria(no* r, int tam,int indice);

// no* recebimentoDePacotes(no* r, int tam, int pacotes[]);
//
// no* converterVetorABP(no* r, int tam, int vet[]);

int alturaArvore(no* n);

no* buscaABP(no *r, int v);

no* dropABP(no *r);
