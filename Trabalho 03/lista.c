#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "lista.h"

void criar(tipoLista *l){
  l->prim = NULL;
}

int inserirEmLista(tipoLista *l, int id, float cr, int idade, char *curso, char *nome) {
  tipoNo *aux = (tipoNo *) malloc(sizeof(tipoNo)*8);
  if (aux) {
    aux->id = id;
    aux->cr = cr;
    aux->idade = idade;
    strcpy(aux->curso,curso);
    strcpy(aux->nome,nome);
    aux->prox = l->prim;
    l->prim = aux;
    return 1;
  } else {
    free(aux);
    return 0;
  }
}

tipoNo* buscaSequencialLista(tipoLista l, float valor) {
  while (l.prim != NULL && l.prim->id != valor ) {
    l.prim = l.prim->prox;
  }
  return l.prim;
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

void mostrarLista(tipoLista lista) {
  while (lista.prim) {
    printf("\nID: %d", lista.prim->id);
    printf("\nNome: %s", (lista.prim->nome));
    printf("\nCR: %f", lista.prim->cr);
    printf("\nCurso: %s", (lista.prim->curso));
    printf("\nIdade: %d\n", lista.prim->idade);
    lista.prim = lista.prim->prox;
  }
}

int qtdElementos(tipoLista lista) {
  int i=0;
  while (lista.prim) {
    i++;
    lista.prim = lista.prim->prox;
  }
  return i;
}
