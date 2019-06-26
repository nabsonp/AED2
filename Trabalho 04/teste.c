#include<stdio.h>
#include "grafo.h"

int main() {
  int tam = 6;
  float conec = 0.5;

  int grafo[tam][tam];
  int n = criarGrafo(tam,grafo,conec);
  mostrarGrafo(tam,grafo);
  printf("\t -> %d arestas setadas (%.1f%% de conectividade).\n\n", n, conec*100);
  printf("\t------------- DFS -------------");
  char ciclo = DFS(tam,grafo,0);
  printf("\n\t   -> Ciclo? %c",ciclo);
  printf("\n\n\t------------- BFS -------------");
  BFS(tam,grafo,0);
  return 0;
}
