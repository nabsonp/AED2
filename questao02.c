#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"
#include "lista.h"

int main() {
  int  pesq = 30, tam = 1000000, val[pesq], i;

  printf("Alocar vetor de 1M.\n");
  scanf("%d", &i);
  int *v = (int*) malloc(sizeof(int)*tam);
  float mediaVet = 0, mediaLista = 0, tempo;
  tipoLista l;
  time_t t;
  clock_t t0;
  srand((unsigned) time(&t));

  printf("Preencher vetor de 1M.\n");
  scanf("%d", &i);
  getVetorDesordenado(tam, v);

  printf("Converter vetor em lista de 1M.\n");
  scanf("%d", &i);
  converteVetor(&l, tam, v);

  printf("Preencher pesquisas\n");
  for (i=0; i<10; i++) {
    val[i] = v[i+100000];
  }
  for (i=10; i<pesq; i++) {
    val[i] = rand()%tam;
  }

  printf("\nTempos de busca no vetor: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaSequencialVetor(tam, v, val[i]);
    tempo = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    printf("%f ", tempo);
    mediaVet += tempo;
  }
  printf("\n\nTempos das buscas na lista: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaSequencialLista(l, val[i]);
    tempo = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    printf("%f ", tempo);
    mediaLista += tempo;
  }

  printf("\n\nFinalizar buscas.\n");
  scanf("%d", &i);
  mediaVet /= pesq;
  mediaLista /= pesq;
  printf("Tempo médio das buscas no vetor: %lf\n", mediaVet);
  printf("Tempo médio das buscas na lista: %lf\n", mediaLista);

  printf("Liberar vetor de 1M.\n");
  scanf("%d", &i);
  free(v);

  printf("Dropar lista.\n");
  scanf("%d", &i);
  dropLista(&l);

  printf("Finalizar processo.\n");
  scanf("%d", &i);
  return 0;
}
