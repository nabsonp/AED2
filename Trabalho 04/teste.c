#include<stdio.h>
#include "grafo.h"
#ifndef _LISTA_H_
#include "lista.h"
#define _LISTA_H_
#endif

int main() {
  int tam = 6;
  float conec = 0.5;

  int grafo[tam][tam];
  int n = criarGrafo(tam,grafo,conec);
  mostrarGrafo(tam,grafo);
  printf("\tDFS: ");
  DFS(tam,grafo,0);
  // mostrarListaInversa(lista->prim);
  printf("\n\t -> %d arestas setadas (%.1f%% de conectividade).\n", n, conec*100);
  return 0;
}
