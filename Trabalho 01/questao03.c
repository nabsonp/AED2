#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"

int main() {
  int  pesq = 30, tam = 100000, val[pesq], i;

  printf("Alocar 2 vetores de 100K.\n");
  scanf("%d", &i);
  int *v = (int*) malloc(sizeof(int)*tam), *aux = (int*) malloc(sizeof(int)*tam);
  float mediaInsertion = 0, mediaBubble = 0, mediaQuick = 0, tempo;
  clock_t t0;

  printf("Início das ordenações.\n");
  scanf("%d", &i);
  for (i=0; i<pesq; i++){
    getVetorDesordenado(tam, v);

    // Insertion Sort
    duplica(tam, v, aux);
    t0 = clock();
    insertionSort(tam, aux);
    tempo = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaInsertion += tempo;
    printf("\nTempo do Insertionsort %d: %f\n", i+1, tempo);

    // Bubble Sort
    duplica(tam, v, aux);
    t0 = clock();
    bubbleSort(tam, aux);
    tempo = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaBubble += tempo;
    printf("Tempo do Bubblesort %d:    %f\n", i+1, tempo);

    // Quick Sort
    duplica(tam, v, aux);
    t0 = clock();
    quickSort(tam, aux);
    tempo = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaQuick += tempo;
    printf("Tempo do Quicksort %d:     %f\n", i+1, tempo);
  }

  mediaInsertion /= pesq;
  mediaBubble /= pesq;
  mediaQuick /= pesq;
  printf("\n\nTempo médio das ordenações com Inserção: %lf\n", mediaInsertion);
  printf("Tempo médio das ordenações com Bolha: %lf\n", mediaBubble);
  printf("Tempo médio das ordenações com Quick: %lf\n", mediaQuick);

  printf("Libera um vetor de 100K.\n");
  scanf("%d", &i);
  free(aux);

  printf("Libera outro vetor de 100K.\n");
  scanf("%d", &i);
  free(v);

  printf("Finalizar processo.\n");
  scanf("%d", &i);
  return 0;
}
