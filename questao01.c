#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"

int main() {
  int  pesq = 30, tam = 1000000, val[pesq], i;

  printf("Alocar vetor de 1M.\n");
  scanf("%d", &i);
  int *v = (int*) malloc(sizeof(int)*tam);
  float mediaSeq = 0, mediaBin = 0, tempo;
  time_t t;
  clock_t t0;
  srand((unsigned) time(&t));

  printf("Preencher vetor.\n");
  scanf("%d", &i);
  getVetorOrdenado(tam, v);

  printf("Preencher pesquisas.\n");
  for (i=0; i<10; i++) {
    val[i] = v[i+100000];
  }
  for (i=10; i<pesq; i++) {
    val[i] = rand()%tam;
  }

  printf("Tempos de pesquisas Sequenciais: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaSequencialVetor(tam, v, val[i]);
    tempo = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaSeq += tempo;
    printf("%f ", tempo);
  }

  printf("\n\nTempo de pesquisas Binárias: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaBinaria(tam, v, val[i]);
    tempo = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaBin += tempo;
    printf("%f ", tempo);
  }

  printf("\n\nFinalizar buscas.\n");
  scanf("%d", &i);
  mediaSeq /= pesq;
  mediaBin /= pesq;
  printf("Tempo médio das Buscas Sequenciais: %lf\n", mediaSeq);
  printf("Tempo médio das Buscas Binárias: %lf\n", mediaBin);

  printf("Liberar vetor de 1M.\n");
  scanf("%d", &i);
  free(v);

  printf("Finalizar processo.\n");
  scanf("%d", &i);
  return 0;
}
