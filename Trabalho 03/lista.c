#include <stdlib.h>
#include <time.h>
#include "lista.h"

void criar(tipoLista *l){
  l->prim = NULL;
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

tipoNo* buscaSequencialLista(tipoLista l, float valor) {
  while (l.prim != NULL && l.prim->d.valor != valor ) {
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
    print("ID: %d", lista.prim->id);
    print("Nome: %s", &(lista.prim->nome));
    print("CR: %f", lista.prim->cr);
    print("Curso: %s", &(lista.prim->curso));
    print("Idade: %d", lista.prim->idade);
    lista.prim = lista.prim->prox;
  }
}
