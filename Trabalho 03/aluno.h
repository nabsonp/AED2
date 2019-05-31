#include "avl.h"
#include "hash.h"
#include "vetor.h"
#include "lista.h"

typedef struct aluno {
    int id;
    char nome[20];
    float cr;
    char curso[30];
    int idade;
} aluno;

// ARQUIVO
void gerarAlunos(FILE* arq, int tam, int buscas[]);

aluno buscaSequencial(FILE *arq, int id);

void mostrarArquivo(FILE* arq);

void buscarMaioresArq(FILE *arq, float dado, tipoLista *lista) ;

void buscarMenoresArq(FILE *arq, float dado, tipoLista *lista);

void buscarMaioresOuIguaisArq(FILE *arq, float dado, tipoLista *lista);

void buscarMenoresOuIguaisArq(FILE *arq, float dado, tipoLista *lista);

// INDEXAÇÃO POR HASH

int indexarHash(FILE* arq, int tam, int tamTH, hash th[]);

aluno buscaIdHash(FILE *arq, int tamTH, hash th[], int id);

// INDEXAÇÃO POR AVL
noAVL* indexarIdAVL(FILE* arq, int t);

noAVL* indexarCrAVL(FILE* arq, int t);

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id);

void buscarMaioresAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);

void buscarMenoresAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);

void buscarMaioresOuIguaisAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);

void buscarMenoresOuIguaisAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista);
