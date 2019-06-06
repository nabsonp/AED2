#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"

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

int buscarMaioresArq(FILE *arq, float dado) ;

int buscarMenoresArq(FILE *arq, float dado);

int buscarMaioresOuIguaisArq(FILE *arq, float dado);

int buscarMenoresOuIguaisArq(FILE *arq, float dado);
