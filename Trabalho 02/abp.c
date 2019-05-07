#include "abp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

no* criarArvore() {
    return NULL;
}

no* inserirEmABP(no *r, int d){
    if (r != NULL) {
        if (d < r->d) r->esq = inserirEmABP(r->esq,d);
        else r->dir = inserirEmABP(r->dir,d);
    } else {
        r = (no *) malloc(sizeof(no));
        r->d = d;
        r->esq = NULL;
        r->dir = NULL;
    }
    return r;
}

int alturaArvore(no* n) {
    if (n) {
        int e = alturaArvore(n->esq), d = alturaArvore(n->dir);
        return d > e ? ++d : ++e;
    } else
        return 0;
}

no* buscaABP(no *r, int v) {
  if (r != NULL) {
    if (v < r->d) return buscaABP(r->esq,v);
    else if (v > r->d) return buscaABP(r->dir,v);
    else return r;
  } else return NULL;
}

no* dropABP(no *r) {
  if (r != NULL) {
    r->esq = dropABP(r->esq);
    r->dir = dropABP(r->dir);
    free(r);
  }
  return NULL;
}

void caminhamentoPrefixado(no *r){
    if (r != NULL) {
        printf("%d ",r->d);
        caminhamentoPrefixado(r->esq);
        caminhamentoPrefixado(r->dir);
    }
}

void caminhamentoInfixado(no *r){
    if (r != NULL) {
        caminhamentoInfixado(r->esq);
        printf("%d ",r->d);
        caminhamentoInfixado(r->dir);
    }
}

void caminhamentoPosfixado(no *r){
    if (r != NULL) {
        caminhamentoPosfixado(r->esq);
        caminhamentoPosfixado(r->dir);
        printf("%d ",r->d);
    }
}

no* criarArvoreAleatoria(no* r, int tam) {
  time_t t;
  srand((unsigned) time(&t));
  r = inserirEmABP(r, rand()%100000);
  for (int i=1; i<tam; i++) {
    if (inserirEmABP(r, rand()%100000) == NULL) i--;
  }
  return r;
}

no* explodirArvore(no* r) {
  if (r != NULL) {
    explodirArvore(r->esq);
    explodirArvore(r->dir);
    free(r);
  }
  return NULL;
}

no* inserirEmABPSemRepeticao(no *r, int d){
    if (r != NULL) {
        if (d < r->d) r->esq = inserirEmABP(r->esq,d);
        else if (d > r->d) r->dir = inserirEmABP(r->dir,d);
        else return NULL;
    } else {
        r = (no *) malloc(sizeof(no));
        r->d = d;
        r->esq = NULL;
        r->dir = NULL;
    }
    return r;
}

no* recebimentoDePacotes(no* r, int tam, int pacotes[]) {
  int d, i = 1;
  time_t t;
  srand((unsigned) time(&t));
  r = inserirEmABP(r, pacotes[0]);
  for (;i < tam;i++) {
    inserirEmABPSemRepeticao(r, pacotes[i]);
  }
  return r;
}

no* converterVetorABP(no* r, int tam, int vet[]) {
  r = inserirEmABP(r,vet[0]);
  for (int i=1; i < tam; i++) {
    inserirEmABP(r,vet[i]);
  }
  return r;
}
