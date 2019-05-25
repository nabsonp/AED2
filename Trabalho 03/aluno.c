#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

noAVL* gerarAlunosIdAVL(FILE* arq, int tam) {
    aluno a;
    noAVL *arv = criarAVL();
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<tam; i++) {
        a.id = 2019000 + i;
        a.cr = (rand() % 10);
        a.idade = 18 + (rand() % 10);
        strcpy(a.curso,"Ciência da Computação");
        strcpy(a.nome,"Aluno");
        fwrite(&a,sizeof(aluno),1,arq);
        arv = inserirEmAVL(arv, a.id, i);
    }
    return arv;
}

noAVL* gerarAlunosCrAVL(FILE* arq, int tam) {
    aluno a;
    noAVL *arv = criarAVL();
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<tam; i++) {
        a.id = 2019000 + i;
        a.cr = (rand() % 10);
        a.idade = 18 + (rand() % 10);
        strcpy(a.curso,"Ciência da Computação");
        strcpy(a.nome,"NOME");
        fwrite(&a,sizeof(aluno),1,arq);
        arv = inserirEmAVL(arv, a.cr, i);
    }
    return arv;
}

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id) {
    noAVL *no = buscaAVL(indice,id);
    aluno a;
    a.id = -1;
    if (no) {
      fseek(arq,0,SEEK_SET);
      fseek(arq,no->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
    }
    return a;
}

void gerarAlunos(FILE* arq, int tam) {
    aluno a;
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<tam; i++) {
        a.id = 2019000 + i;
        a.cr = (rand() % 10);
        a.idade = 18 + (rand() % 10);
        strcpy(a.curso,"Ciência da Computação");
        strcpy(a.nome,"Aluno");
        fwrite(&a,sizeof(aluno),1,arq);
    }
}

aluno buscaSequencial(FILE *arq, int id) {
  aluno a;
  fseek(arq,0,SEEK_SET);
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.id == id) return a;
  }
  a.id = -1;
  return a;
}

void gerarAlunosIdHash(FILE* arq, int tam, int tamTH, hash th[]) {
    aluno a;
    tabelaHash(tamTH, th);
    int j;
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<tam; i++) {
        a.id = 2019000 + i;
        a.cr = (rand() % 10);
        a.idade = 18 + (rand() % 10);
        strcpy(a.curso,"Ciência da Computação");
        strcpy(a.nome,"Aluno");
        fwrite(&a,sizeof(aluno),1,arq);
        inserirHash(a.id, i, tamTH, th);
    }
}

aluno buscaIdHash(FILE *arq, int tamTH, hash th[], int id) {
    int indice = buscaHash(id,tamTH, th);
    aluno a;
    a.id = -1;
    if (indice != -1) {
      fseek(arq,0,SEEK_SET);
      fseek(arq,indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
    }
    return a;
}
