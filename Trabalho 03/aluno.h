#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"
#ifndef _LISTA_H_
#include "lista.h"
#define _LISTA_H_
#endif
// #include "lista.h"

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
