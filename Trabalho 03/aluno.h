#include "avl.h"
#include "hash.h"

typedef struct aluno {
    int id;
    char nome[20];
    float cr;
    char curso[30];
    int idade;
} aluno;


// Lista
typedef struct tipoNo{
  aluno a;
  struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
  tipoNo *prim;
} tipoLista;


void criar(tipoLista *l);

int inserirEmLista(tipoLista *l, aluno a);

tipoNo* buscaSequencialLista(tipoLista l, float valor);

void mostrarLista(tipoLista lista);

void dropLista(tipoLista *l);

noAVL* gerarAlunosIdAVL(FILE* arq, int t);

noAVL* gerarAlunosCrAVL(FILE* arq, int t);

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id);

aluno buscaSequencial(FILE *arq, int id);

void gerarAlunos(FILE* arq, int tam);

int gerarAlunosIdHash(FILE* arq, int tam, int tamTH, hash th[]);

aluno buscaIdHash(FILE *arq, int tamTH, hash th[], int id);

void buscarMaiores(FILE *arq, noAVL *no, float dado, tipoLista *lista);

void buscarMenores(FILE *arq, noAVL *no, float dado, tipoLista *lista);

void buscarMaioresOuIguais(FILE *arq, noAVL *no, float dado, tipoLista *lista);

void buscarMenoresOuIguais(FILE *arq, noAVL *no, float dado, tipoLista *lista);

//lista
