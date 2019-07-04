#include<stdio.h>
#include "grafo.h"
#include <time.h>

int main() {
  float conec, media = 0.0, t;
  int n, i;
  char a;
  clock_t t0;

  // Grafo 1
  int tam = 10000;
  int **grafo1 = (int**) malloc(sizeof(int*)*tam);
  for (i=0; i<tam; i++) grafo1[i] = (int*) malloc(sizeof(int)*tam);
  for (i=1; i<5; i++) {
    printf("************************ GRAFO %d **************************\n",i);
    conec = 0.25*i;
    printf("Criar grafo %d? \n",i); // 64 KB
    scanf("%c", &a);
    n = criarGrafo(tam,grafo1,conec);
    // mostrarGrafo(tam,grafo1);
    printf("\t -> %d arestas setadas (%.1f%% de conectividade).\n\n", n, conec*100);
    printf("Iniciar BFS? \n");
    scanf("%c", &a);
    t0 = clock();
    BFS(tam,grafo1,0,0);
    t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    printf("Tempo de BFS no grafo %d: %fs\n", i, t);
    media += t;
    printf("Fim do grafo %d.\n",i);
    scanf("%c", &a);
    printf("\n\n");
  }
  printf("Média dos tempos: %f\n", media/4.0);
  return 0;
}
