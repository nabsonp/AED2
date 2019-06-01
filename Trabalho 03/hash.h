#ifndef _ALUNO_H_
#include "aluno.h"
#define _ALUNO_H_
#endif
#include<stdio.h>
#include<stdlib.h>

typedef struct hash {
  int id;
  int indice;
} hash;

int h(int id);

int buscaHash(int id, int tam, hash ht[]);

int inserirHash(int id, int indice, int tam, hash th[]);

void tabelaHash(int tam, hash th[]);

int indexarHash(FILE* arq, int tam, int tamTH, hash th[]);

aluno buscaIdHash(FILE *arq, int tamTH, hash th[], int id);
