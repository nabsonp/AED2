#include "avl.h"

typedef struct aluno {
    int id;
    char nome[20];
    float cr;
    char curso[30];
    int idade;
} aluno;

noAVL* gerarAlunosID(FILE* arq, int t);

noAVL* gerarAlunosCR(FILE* arq, int t);

aluno pesqID(FILE *arq, noAVL *indice, int id);
