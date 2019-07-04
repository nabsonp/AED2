#include<stdio.h>
#include "grafo.h"

int main() {
  float conec;
  int n, i;
  char ciclo;

  // Grafo 1
  int tam = 4;
  int grafo1[tam][tam];
  printf("************************ GRAFO 1 **************************\n");
  for (i=1; i<5; i++) {
    conec = 0.25*i;
    n = criarGrafo(tam,grafo1,conec);
    mostrarGrafo(tam,grafo1);
    printf("\t -> %d arestas setadas (%.1f%% de conectividade).\n\n", n, conec*100);
    printf("\t------------- DFS -------------");
    ciclo = DFS(tam,grafo1,0,1);
    printf("\n\t   -> Ciclo? %c",ciclo);
    printf("\n\n\t------------- BFS -------------");
    BFS(tam,grafo1,0,1);
    printf("\n\n");
  }

  // Grafo 2
  tam = 5;
  int grafo2[tam][tam];
  printf("************************ GRAFO 2 **************************\n");
  for (i=1; i<5; i++) {
    conec = 0.25*i;
    n = criarGrafo(tam,grafo2,conec);
    mostrarGrafo(tam,grafo2);
    printf("\t -> %d arestas setadas (%.1f%% de conectividade).\n\n", n, conec*100);
    printf("\t------------- DFS -------------");
    ciclo = DFS(tam,grafo2,0,1);
    printf("\n\t   -> Ciclo? %c",ciclo);
    printf("\n\n\t------------- BFS -------------");
    BFS(tam,grafo2,0,1);
    printf("\n\n");
  }

  // Grafo 3
  tam = 6;
  int grafo3[tam][tam];
  printf("************************ GRAFO 3 **************************\n");
  for (i=1; i<5; i++) {
    conec = 0.25*i;
    n = criarGrafo(tam,grafo3,conec);
    mostrarGrafo(tam,grafo3);
    printf("\t -> %d arestas setadas (%.1f%% de conectividade).\n\n", n, conec*100);
    printf("\t------------- DFS -------------");
    ciclo = DFS(tam,grafo3,0,1);
    printf("\n\t   -> Ciclo? %c",ciclo);
    printf("\n\n\t------------- BFS -------------");
    BFS(tam,grafo3,0,1);
    printf("\n\n");
  }
  return 0;
}
