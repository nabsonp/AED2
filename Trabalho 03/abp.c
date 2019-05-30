#include "abp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

no* criarArvore() {
    return NULL;
}

no* inserirEmABP(no *r, int d, int indice){
    if (r != NULL) {
        if (d < r->d) r->esq = inserirEmABP(r->esq,d,indice);
        else if (d > r->d) r->dir = inserirEmABP(r->dir,d,indice);
        else {
            no *aux = (no *) malloc(sizeof(no));
            aux->d = d;
            aux->indice = indice;
            aux->esq = r->esq;
            r->esq = aux;
            aux->dir = NULL;
            return r;
        }
    } else {
        r = (no *) malloc(sizeof(no));
        r->d = d;
        r->indice = indice;
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

void caminhamentoPrefixadoABP(no *r){
    if (r != NULL) {
        printf("%.2f ",r->d);
        caminhamentoPrefixadoABP(r->esq);
        caminhamentoPrefixadoABP(r->dir);
    }
}

void caminhamentoInfixadoABP(no *r){
    if (r != NULL) {
        caminhamentoInfixadoABP(r->esq);
        printf("%.2f ",r->d);
        caminhamentoInfixadoABP(r->dir);
    }
}

void caminhamentoPosfixadoABP(no *r){
    if (r != NULL) {
        caminhamentoPosfixadoABP(r->esq);
        caminhamentoPosfixadoABP(r->dir);
        printf("%.2f ",r->d);
    }
}

no* criarArvoreAleatoria(no* r, int tam, int indice) {
  time_t t;
  srand((unsigned) time(&t));
  r = inserirEmABP(r, rand()%100000,indice);
  for (int i=1; i<tam; i++) {
    if (inserirEmABP(r, rand()%100000,indice) == NULL) i--;
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

no* inserirEmABPSemRepeticao(no *r, int d, int indice){
    if (r != NULL) {
        if (d < r->d) r->esq = inserirEmABP(r->esq,d,indice);
        else if (d > r->d) r->dir = inserirEmABP(r->dir,d,indice);
        else return NULL;
    } else {
        r = (no *) malloc(sizeof(no));
        r->d = d;
        r->indice = indice;
        r->esq = NULL;
        r->dir = NULL;
    }
    return r;
}
//
// no* recebimentoDePacotes(no* r, int tam, int pacotes[]) {
//   int d, i = 1;
//   time_t t;
//   srand((unsigned) time(&t));
//   r = inserirEmABP(r, pacotes[0]);
//   for (;i < tam;i++) {
//     inserirEmABPSemRepeticao(r, pacotes[i]);
//   }
//   return r;
// }
//
// no* converterVetorABP(no* r, int tam, int vet[]) {
//   r = inserirEmABP(r,vet[0]);
//   for (int i=1; i < tam; i++) {
//     inserirEmABP(r,vet[i]);
//   }
//   return r;
// }
