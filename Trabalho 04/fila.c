#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include "fila.h"

void criar(tipoFila *l){
  l->prim = NULL;
  l->ult = NULL;
}

int enfileirarSemRepeticao(tipoFila *l, int d) {
  tipoNo *aux = l->prim;
  while (aux != NULL) {
    if (aux->dado == d) return -1; // Já está na fila
    aux = aux->prox;
  }
  aux = (tipoNo *) malloc(sizeof(tipoNo));
  if (aux) {
    aux->dado = d;
    if (!l->prim) l->prim = aux;
    else l->ult->prox = aux;
    aux->prox = NULL;
    l->ult = aux;
    return 1; // Enfileirado
  } else {
    free(aux);
    return -2; // Não foi possível alocar o ponteiro auxiliar
  }
}

int enfileirar(tipoFila *l, int d) {
  tipoNo *aux = (tipoNo *) malloc(sizeof(tipoNo)*8);
  if (aux) {
    aux->dado = d;
    if (!l->prim) l->prim = aux;
    aux->prox = NULL;
    l->ult->prox = aux;
    l->ult = aux;
    return 1;
  } else {
    free(aux);
    return 0;
  }
}

int desenfileirar(tipoFila *l) {
  tipoNo *aux;
  int dado;
  if (l->prim) {
    dado = l->prim->dado;
    aux = l->prim;
    l->prim = aux->prox;
    free(aux);
    if (!l->prim) l->ult = NULL;
    return dado;
  }
  return -1; // Fila vazia
}

void mostrarFila(tipoFila l) {
  printf("Fila: ");
  while (l.prim != NULL) {
    printf("%d ", l.prim->dado);
    l.prim = l.prim->prox;
  }
}

void mostrarFilaInversa(tipoNo *l) {
  if (l) {
      mostrarFilaInversa(l->prox);
      printf("%d ", l->dado);
  }
}

void dropFila(tipoFila *l) {
  tipoNo *aux;
  while (l->prim != NULL) {
    aux = l->prim;
    l->prim = aux->prox;
    free(aux);
  }
  l->prim = NULL;
}
