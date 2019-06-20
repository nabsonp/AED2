#include<stdio.h>
#include "grafo.h"
#ifndef _LISTA_H_
#include "lista.h"
#define _LISTA_H_
#endif

int main() {
  int tam = 4;
  int grafo[tam][tam];
  int n = criarGrafo(tam,grafo,0.5);
  mostrarGrafo(tam,grafo);
  tipoLista *lista = (tipoLista*) malloc(sizeof(tipoLista));
  criar(lista);
  DFS(tam,grafo,lista,0);
  printf("\tDFS: ");
  mostrarListaInversa(lista->prim);
  printf("\n\t -> %d arestas setados\n", n);
  return 0;
}
