#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

// ARQUIVO
void gerarAlunos(FILE* arq, int tam) {
    aluno a;
    time_t t;
    srand((unsigned) time(&t));
    int ids[tam];
    gerarVetorDesordenadoSemRepeticoes(tam, ids);
    for(int i=0; i<tam; i++) {
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
      inserirEmLista(lista, a);
  }
}

void buscarMenoresArq(FILE *arq, float dado, tipoLista *lista) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr < dado)
      inserirEmLista(lista, a);
  }
}

void buscarMaioresOuIguaisArq(FILE *arq, float dado, tipoLista *lista) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr >= dado)
      inserirEmLista(lista, a);
  }
}

void buscarMenoresOuIguaisArq(FILE *arq, float dado, tipoLista *lista) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr <= dado)
      inserirEmLista(lista, a);
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

// INDEXAÇÃO POR ABP
no* indexarCrABP(FILE* arq, int tam) {
  aluno a;
  no *arv = criarArvore();
  fseek(arq,0,SEEK_SET);
  for (int i=0; fread(&a,sizeof(aluno),1,arq); i++)
      arv = inserirEmABP(arv, a.cr, i);
  return arv;
}

aluno buscaIdABP(FILE *arq, no *indice, int id) {
    no *n = buscaABP(indice,id);
    aluno a;
    a.id = -1;
    if (n) {
      fseek(arq,0,SEEK_SET);
      fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
    }
    return a;
}

int inserirEmLista(tipoLista *l, aluno a) {
  tipoNo *aux = (tipoNo *) malloc(sizeof(tipoNo)*8);
  if (aux) {
    aux->a = a;
    aux->prox = l->prim;
    l->prim = aux;
    return 1;
  } else {
    free(aux);
    return 0;
  }
}

void inserirLista(FILE *arq,no *n, tipoLista *lista) {
  if (n) {
    inserirLista(arq, n->esq, lista);
    aluno a;
    fseek(arq,0,SEEK_SET);
    fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
    fread(&a,sizeof(aluno),1,arq);
    inserirEmLista(lista, a);
    inserirLista(arq, n->dir, lista);
  }
}

void buscarMaioresABP(FILE *arq, no *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d < dado)
      buscarMaioresABP(arq,n->dir,dado,lista);
    else {
      if (n->d > dado) {
        buscarMaioresABP(arq,n->esq,dado,lista);
        aluno a;
        fseek(arq,0,SEEK_SET);
        fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
        inserirEmLista(lista, a);
        inserirLista(arq, n->dir,lista);
      } else
        inserirLista(arq,n->dir, lista);
    }
  }
}

void buscarMenoresABP(FILE *arq, no *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d >= dado)
      buscarMenoresABP(arq,n->esq,dado,lista);
    else {
      if (n->d < dado) {
        buscarMenoresABP(arq,n->dir,dado,lista);
        aluno a;
        fseek(arq,0,SEEK_SET);
        fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
        inserirEmLista(lista, a);
        inserirLista(arq, n->esq, lista);
      }
    }
  }
}

void buscarMaioresOuIguaisABP(FILE *arq, no *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d < dado)
      buscarMaioresOuIguaisABP(arq,n->dir,dado,lista);
    else {
      aluno a;
      fseek(arq,0,SEEK_SET);
      fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
      inserirEmLista(lista, a);
      buscarMaioresOuIguaisABP(arq,n->esq,dado,lista);
      inserirLista(arq,n->dir, lista);
    }
  }
}

void buscarMenoresOuIguaisABP(FILE *arq, no *n, float dado, tipoLista *lista) {
  if (n) {
    if (n->d > dado)
      buscarMenoresOuIguaisABP(arq,n->esq,dado,lista);
    else {
      aluno a;
      fseek(arq,0,SEEK_SET);
      fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
      inserirEmLista(lista, a);
      buscarMenoresOuIguaisABP(arq,n->dir,dado,lista);
      inserirLista(arq, n->esq, lista);
    }
  }
}

void criar(tipoLista *l){
  l->prim = NULL;
}

tipoNo* buscaSequencialLista(tipoLista l, float valor) {
  while (l.prim != NULL && l.prim->a.id != valor ) {
    l.prim = l.prim->prox;
  }
  return l.prim;
}

void mostrarLista(tipoLista lista) {
  while (lista.prim) {
    printf("\nID: %d", lista.prim->a.id);
    printf("\nNome: %s", (lista.prim->a.nome));
    printf("\nCR: %f", lista.prim->a.cr);
    printf("\nCurso: %s", (lista.prim->a.curso));
    printf("\nIdade: %d\n", lista.prim->a.idade);
    lista.prim = lista.prim->prox;
  }
}
