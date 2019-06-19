#include<stdio.h>
#include "grafo.h"

int main() {
  int tam = 80;
  int grafo[tam][tam];
  int n = criarGrafo(tam,grafo,0.5);
  mostrarGrafo(tam,grafo);
  printf("\n\t -> %d vértices setados\n", n);
  return 0;
}
