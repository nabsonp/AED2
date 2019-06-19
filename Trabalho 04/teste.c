#include<stdio.h>
#include "grafo.h"

int main() {
  int tam = 80;
  vertice **grafo = (vertice**) malloc(tam*sizeof(vertice*));
  for (int i=0; i<tam; i++) grafo[i] = (vertice*) malloc(tam*sizeof(vertice));

  int n = criarGrafo(tam,grafo,0.5);
  mostrarGrafo(tam,grafo);
  printf("\n\t -> %d vértices setados\n", n);
  return 0;
}
