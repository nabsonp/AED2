#include<stdio.h>
#include "grafo.h"

int main() {
  int tam = 6;
  float conec = 0.5;

  int grafo[tam][tam];
  int n = criarGrafo(tam,grafo,conec);
  mostrarGrafo(tam,grafo);
  printf("\tDFS: ");
  DFS(tam,grafo,0);
  printf("\n\tBFS: ");
  BFS(tam,grafo,0);
  printf("\n\t -> %d arestas setadas (%.1f%% de conectividade).\n", n, conec*100);
  return 0;
}
