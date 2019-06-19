#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vertice {
  int dado;
  char cor;
  int distancia;
} vertice;

int criarGrafo(int t, vertice **grafo, float conec);

void mostrarGrafo(int t, vertice **grafo);
