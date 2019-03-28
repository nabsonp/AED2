#include <stdlib.h>
#include <time.h>
#include "lista.h"

void criar(tipoLista *l){
  l->prim = NULL;
}

int inserir(tipoLista *l, tipoDados d) {
  tipoNo *aux = (tipoNo *) malloc(sizeof(tipoNo)*8);
  if (aux) {
    aux->d = d;
    aux->prox = l->prim;
    l->prim = aux;
    free(aux);
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
    if (aux->d.valor == valor){
      l->prim = l->prim->prox;
      free(aux);
      return 1;
    }
    while(aux->prox){
      if (aux->prox->d.valor == valor) {
        aux1 = aux->prox;
        aux->prox = aux->prox->prox;
        free(aux1);
        return 1;
      }
    }
  }
  return 0;
}

void listaDesordenada(tipoLista *l, int tam){
  tipoNo *ant, *aux = (tipoNo*) malloc(sizeof(tipoNo));
  tipoDados d;
  time_t t;
  srand((unsigned) time(&t));
  d.valor = rand()%tam;
  aux->d = d;
  l->prim = aux;
  ant = aux;
  for (int i=0; i<tam-1; i++){
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    d.valor = rand()%tam;
    aux->d = d;
    ant->prox = aux;
    ant = aux;
  }
  aux->prox = NULL;
  free(aux);
  free(ant);
}

void converteVetor(tipoLista *l, int tam, int vet[]){
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo)), *ant;
  tipoDados d;
  d.valor = vet[0];
  aux->d = d;
  l->prim = aux;
  ant = aux;
  for (int i=1; i<tam; i++) {
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    d.valor = vet[0];
    aux->d = d;
    ant->prox = aux;
    ant = aux;
  }
  aux->prox = NULL;
  free(aux);
}

tipoNo* buscaSequencialLista(tipoLista l, int valor) {
  while (l.prim != NULL && l.prim->d.valor != valor ) {
    l.prim = l.prim->prox;
  }
  return l.prim;
}
