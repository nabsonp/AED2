#include "avl.h"
#include "hash.h"
#include "vetor.h"
#include "abp.h"
#include "lista.h"

typedef struct aluno {
    int id;
    char nome[20];
    float cr;
    char curso[30];
    int idade;
} aluno;


void criar(tipoLista *l);

noAVL* indexarIdAVL(FILE* arq, int t);

noAVL* indexarCrAVL(FILE* arq, int t);

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id);

aluno buscaSequencial(FILE *arq, int id);

void gerarAlunos(FILE* arq, int tam);

void mostrarArquivo(FILE* arq);

int indexarHash(FILE* arq, int tam, int tamTH, hash th[]);

aluno buscaIdHash(FILE *arq, int tamTH, hash th[], int id);

void buscarMaioresABP(FILE *arq, no *n, float dado, tipoLista *lista);

void buscarMenoresABP(FILE *arq, no *n, float dado, tipoLista *lista);

void buscarMaioresOuIguaisABP(FILE *arq, no *n, float dado, tipoLista *lista);

void buscarMenoresOuIguaisABP(FILE *arq, no *n, float dado, tipoLista *lista);

void buscarMaioresArq(FILE *arq, float dado, tipoLista *lista) ;

void buscarMenoresArq(FILE *arq, float dado, tipoLista *lista);

void buscarMaioresOuIguaisArq(FILE *arq, float dado, tipoLista *lista);

void buscarMenoresOuIguaisArq(FILE *arq, float dado, tipoLista *lista);

no* indexarCrABP(FILE* arq, int tam);

aluno buscaIdABP(FILE *arq, no *indice, int id);
