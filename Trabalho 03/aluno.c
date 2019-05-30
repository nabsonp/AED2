#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

noAVL* indexarIdAVL(FILE* arq, int tam) {
    aluno a;
    noAVL *arv = criarAVL();
    for (int i=0; fread(&a,sizeof(aluno),1,arq); i++)
        arv = inserirEmAVL(arv, a.id, i);
    return arv;
}

noAVL* indexarCrAVL(FILE* arq, int tam) {
  aluno a;
  noAVL *arv = criarAVL();
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

int indexarHash(FILE* arq, int tam, int tamTH, hash th[]) {
    aluno a;
    tabelaHash(tamTH, th);
    int colisoes = 0;
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

void inserirLista(FILE *arq,noAVL *no, tipoLista *lista) {
  if (no) {
    inserirLista(arq, no->esq, lista);
    aluno a;
    fseek(arq,0,SEEK_SET);
    fseek(arq,no->indice*sizeof(aluno),SEEK_SET);
    fread(&a,sizeof(aluno),1,arq);
    inserirEmLista(lista, a);
    inserirLista(arq, no->dir, lista);
  }
}

void buscarMaioresAVL(FILE *arq, noAVL *no, float dado, tipoLista *lista) {
  if (no) {
    if (no->d < dado)
      buscarMaioresAVL(arq,no->dir,dado,lista);
    else {
      if (no->d > dado) {
        buscarMaioresAVL(arq,no->esq,dado,lista);
        aluno a;
        fseek(arq,0,SEEK_SET);
        fseek(arq,no->indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
        inserirEmLista(lista, a);
        inserirLista(arq, no->dir,lista);
      } else
        inserirLista(arq,no->dir, lista);
    }
  }
}

void buscarMenoresAVL(FILE *arq, noAVL *no, float dado, tipoLista *lista) {
  if (no) {
    if (no->d > dado)
      buscarMenoresAVL(arq,no->esq,dado,lista);
    else {
      if (no->d <= dado) {
        buscarMenoresAVL(arq,no->dir,dado,lista);
        aluno a;
        fseek(arq,0,SEEK_SET);
        fseek(arq,no->indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
        inserirEmLista(lista, a);
        inserirLista(arq, no->esq, lista);
      } else
        inserirLista(arq, no->esq, lista);
    }
  }
}

void buscarMaioresOuIguaisAVL(FILE *arq, noAVL *no, float dado, tipoLista *lista) {
  if (no) {
    if (no->d < dado)
      buscarMaioresAVL(arq,no->dir,dado,lista);
    else {
      aluno a;
      fseek(arq,0,SEEK_SET);
      fseek(arq,no->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
      inserirEmLista(lista, a);
      buscarMaioresAVL(arq,no->esq,dado,lista);
      inserirLista(arq,no->dir, lista);
    }
  }
}

void buscarMenoresOuIguaisAVL(FILE *arq, noAVL *no, float dado, tipoLista *lista) {
  if (no) {
    if (no->d > dado)
      buscarMenoresAVL(arq,no->esq,dado,lista);
    else {
      if (no->d <= dado) {
        buscarMenoresAVL(arq,no->dir,dado,lista);
        aluno a;
        fseek(arq,0,SEEK_SET);
        fseek(arq,no->indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
        inserirEmLista(lista, a);
        inserirLista(arq, no->esq, lista);
      }
    }
  }
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
