typedef struct noAVL {
    int d;
    int altura;
    struct noAVL *esq;
    struct noAVL *dir;
} noAVL;

noAVL* criarAVL();

noAVL* inserirEmAVL(noAVL *r, int d);

int fb(noAVL *n);

noAVL* balanceianoAVL(noAVL* raiz);

noAVL* converterVetorAVL(noAVL* r, int tam, int vet[]);

noAVL* buscaAVL(noAVL *r, int v);

int alturaAVL(noAVL* n);

noAVL* dropAVL(noAVL *r);
