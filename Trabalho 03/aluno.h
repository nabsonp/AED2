#include "avl.h"
#include "hash.h"

typedef struct aluno {
    int id;
    char nome[20];
    float cr;
    char curso[30];
    int idade;
} aluno;

noAVL* gerarAlunosIdAVL(FILE* arq, int t);

noAVL* gerarAlunosCrAVL(FILE* arq, int t);

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id);

aluno buscaSequencial(FILE *arq, int id);

void gerarAlunos(FILE* arq, int tam);

void gerarAlunosIdHash(FILE* arq, int tam, int tamTH, hash th[]);

aluno buscaIdHash(FILE *arq, int tamTH, hash th[], int id);
