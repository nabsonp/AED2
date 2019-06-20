#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include "lista.h"

void criar(tipoLista *l){
  l->prim = NULL;
}

int inserirEmLista(tipoLista *l, int d) {
  tipoNo *aux = (tipoNo *) malloc(sizeof(tipoNo)*8);
  if (aux) {
    aux->dado = d;
    aux->prox = l->prim;
    l->prim = aux;
    return 1;
  } else {
    free(aux);
    return 0;
  }
}

int remover(tipoLista *l, int valor) {
  tipoNo *aux, *aux1;
  if (l->prim) {
    aux = l->prim;
    if (aux->dado == valor){
      l->prim = l->prim->prox;
      free(aux);
      return 1;
    }
    while(aux->prox){
      if (aux->prox->dado == valor) {
        aux1 = aux->prox;
        aux->prox = aux->prox->prox;
        free(aux1);
        return 1;
      }
    }
  }
  return 0;
}

tipoNo* buscaSequencialLista(tipoLista l, int valor) {
  while (l.prim != NULL && l.prim->dado != valor ) {
    l.prim = l.prim->prox;
  }
  return l.prim;
}

void mostrarLista(tipoLista l) {
  printf("Lista: ");
  while (l.prim != NULL) {
    printf("%d ", l.prim->dado);
    l.prim = l.prim->prox;
  }
}

void mostrarListaInversa(tipoNo *l) {
  if (l) {
      mostrarListaInversa(l->prox);
      printf("%d ", l->dado);
  }
}

void dropLista(tipoLista *l) {
  tipoNo *aux;
  while (l->prim != NULL) {
    aux = l->prim;
    l->prim = aux->prox;
    free(aux);
  }
  l->prim = NULL;
}
