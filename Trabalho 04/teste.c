#include<stdio.h>
#include "grafo.h"

int main() {
  int tam = 4;
  int grafo[tam][tam];
  int n = criarGrafo(tam,grafo,0.5);
  mostrarGrafo(tam,grafo);
  printf("\n\t -> %d arestas setados\n", n);
  return 0;
}
