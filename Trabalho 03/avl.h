#ifndef _ALUNO_H_
#include "aluno.h"
#define _ALUNO_H_
#endif
#include <stdio.h>
#include <stdlib.h>

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

noAVL* indexarIdAVL(FILE* arq, int t);

noAVL* indexarCrAVL(FILE* arq, int t);

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id);

void buscarMaioresAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);

void buscarMenoresAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);

void buscarMaioresOuIguaisAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);

void buscarMenoresOuIguaisAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);
