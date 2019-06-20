#include<stdio.h>
#include "grafo.h"
#ifndef _LISTA_H_
#include "lista.h"
#define _LISTA_H_
#endif

int main() {
  int tam = 5;
  float conec = 0.5;

  int grafo[tam][tam];
  int n = criarGrafo(tam,grafo,conec);
  mostrarGrafo(tam,grafo);
  tipoLista *lista = (tipoLista*) malloc(sizeof(tipoLista));
  criar(lista);
  printf("\tDFS: ");
  DFS(tam,grafo,lista,0);
  // mostrarListaInversa(lista->prim);
  printf("\n\t -> %d arestas setadas (%.1f%% de conectividade).\n", n, conec*100);
  return 0;
}
