#include "avl.h"

typedef struct aluno {
    int id;
    char nome[50];
    float cr;
} aluno;

int inserirAluno(FILE* arq, int id, char nome[50], int cr);

noAVL* gerarAlunosID(FILE* arq, int t);

noAVL* gerarAlunosCR(FILE* arq, int t);

aluno pesqIndice(FILE *arq, int i);
