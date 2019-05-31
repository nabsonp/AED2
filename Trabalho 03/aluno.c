#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

// ARQUIVO
void gerarAlunos(FILE* arq, int tam, int buscas[]) {
    aluno a;
    time_t t;
    srand((unsigned) time(&t));
    int ids[tam],i;
    gerarVetorDesordenadoSemRepeticoes(tam, ids);
    for (i=0; i<10; i++) {
      buscas[i] = -1;
    }
    for (i=10; i < 30; i++) {
      buscas[i] = ids[i*330];
    }
    for(i=0; i<tam; i++) {
        a.id = ids[i];
        a.cr = (rand() % 10);
        a.idade = 18 + (rand() % 10);
        strcpy(a.curso,"Ciência da Computação");
        strcpy(a.nome,"Aluno");
        fwrite(&a,sizeof(aluno),1,arq);
    }
}

void mostrarArquivo(FILE* arq) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    printf("\nID: %d", a.id);
    printf("\nNome: %s", (a.nome));
    printf("\nCR: %f", a.cr);
    printf("\nCurso: %s", (a.curso));
    printf("\nIdade: %d\n", a.idade);
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

void buscarMaioresArq(FILE *arq, float dado, tipoLista *lista) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr > dado)
      inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
  }
}

void buscarMenoresArq(FILE *arq, float dado, tipoLista *lista) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr < dado)
      inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
  }
}

void buscarMaioresOuIguaisArq(FILE *arq, float dado, tipoLista *lista) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr >= dado)
      inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
  }
}

void buscarMenoresOuIguaisArq(FILE *arq, float dado, tipoLista *lista) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr <= dado)
      inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
  }
}

// INDEXAÇÃO POR HASH
int indexarHash(FILE* arq, int tam, int tamTH, hash th[]) {
    aluno a;
    tabelaHash(tamTH, th);
    int colisoes = 0;
    fseek(arq,0,SEEK_SET);
    for (int i=0; fread(&a,sizeof(aluno),1,arq); i++) {
        if (inserirHash(a.id, i, tamTH, th) == -1)
            colisoes++;
    }
    return colisoes;
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

// INDEXAÇÃO POR AVL
noAVL* indexarIdAVL(FILE* arq, int tam) {
    aluno a;
    noAVL *arv = criarAVL();
    fseek(arq,0,SEEK_SET);
    for (int i=0; fread(&a,sizeof(aluno),1,arq); i++)
        arv = inserirEmAVL(arv, a.id, i);
    return arv;
}

noAVL* indexarCrAVL(FILE* arq, int tam) {
  aluno a;
  noAVL *arv = criarAVL();
  fseek(arq,0,SEEK_SET);
  for (int i=0; fread(&a,sizeof(aluno),1,arq); i++)
      arv = inserirEmAVL(arv, a.cr, i);
  return arv;
}

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id) {
    noAVL *n = buscaAVL(indice,id);
    aluno a;
    a.id = -1;
    if (n) {
      fseek(arq,0,SEEK_SET);
      fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
    }
    return a;
}

void inserirLista(FILE *arq,noAVL *n, tipoLista *lista) {
  if (n) {
    inserirLista(arq, n->esq, lista);
    aluno a;
    fseek(arq,0,SEEK_SET);
    fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
    fread(&a,sizeof(aluno),1,arq);
    inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
    inserirLista(arq, n->dir, lista);
  }
}

void buscarMaioresAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d < dado)
      buscarMaioresAVL(arq,n->dir,dado,lista);
    else {
      if (n->d > dado) {
        buscarMaioresAVL(arq,n->esq,dado,lista);
        aluno a;
        fseek(arq,0,SEEK_SET);
        fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
        inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
        inserirLista(arq, n->dir,lista);
      } else
        inserirLista(arq,n->dir, lista);
    }
  }
}

void buscarMenoresAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d >= dado)
      buscarMenoresAVL(arq,n->esq,dado,lista);
    else {
      if (n->d < dado) {
        buscarMenoresAVL(arq,n->dir,dado,lista);
        aluno a;
        fseek(arq,0,SEEK_SET);
        fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
        inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
        inserirLista(arq, n->esq, lista);
      }
    }
  }
}

void buscarMaioresOuIguaisAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d < dado)
      buscarMaioresOuIguaisAVL(arq,n->dir,dado,lista);
    else {
      aluno a;
      fseek(arq,0,SEEK_SET);
      fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
      inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
      buscarMaioresOuIguaisAVL(arq,n->esq,dado,lista);
      inserirLista(arq,n->dir, lista);
    }
  }
}

void buscarMenoresOuIguaisAVL(FILE *arq, noAVL *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d > dado)
      buscarMenoresOuIguaisAVL(arq,n->esq,dado,lista);
    else {
      aluno a;
      fseek(arq,0,SEEK_SET);
      fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
      inserirEmLista(lista, a.id, a.cr, a.idade,a.curso,a.nome);
      buscarMenoresOuIguaisAVL(arq,n->dir,dado,lista);
      inserirLista(arq, n->esq, lista);
    }
  }
}
