typedef struct noAVL {
    float d;
    int indice;
    int altura;
    struct noAVL *esq;
    struct noAVL *dir;
} noAVL;

noAVL* criarAVL();

void caminhamentoInfixado(noAVL *r);

void caminhamentoPrefixado(noAVL *r);

noAVL* inserirEmAVL(noAVL *r, int d, int ind);

int fb(noAVL *n);

noAVL* balanceianoAVL(noAVL* raiz);

noAVL* converterVetorAVL(noAVL* r, int tam, int vet[]);

noAVL* buscaAVL(noAVL *r, int v);

int alturaAVL(noAVL* n);

noAVL* dropAVL(noAVL *r);
