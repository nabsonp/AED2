#include<stdio.h>
#include "grafo.h"

int main() {
  int tam = 5;
  float conec;

  int grafo[tam][tam];
  int n, i;
  for (i=1; i<5; i++) {
    conec = 0.25*i;
    n = criarGrafo(tam,grafo,conec);
    mostrarGrafo(tam,grafo);
    printf("\t -> %d arestas setadas (%.1f%% de conectividade).\n\n", n, conec*100);
    printf("\t------------- DFS -------------");
    char ciclo = DFS(tam,grafo,0);
    printf("\n\t   -> Ciclo? %c",ciclo);
    printf("\n\n\t------------- BFS -------------");
    BFS(tam,grafo,0);
    printf("\n\n");
  }
  return 0;
}
