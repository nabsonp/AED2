#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"

int main() {
  int  pesq = 30, tam = 100000, val[pesq], i;
  int *v = (int*) malloc(sizeof(int)*tam), *aux = (int*) malloc(sizeof(int)*tam);
  float mediaInsertion = 0, mediaBubble = 0, mediaQuick = 0, tempoInsertion[pesq], tempoBubble[pesq], tempoQuick[pesq];
  FILE *arq = fopen("questao03.txt","w");
  clock_t t0;
  for (i=0; i<pesq; i++){
    getVetorDesordenado(tam, v);
    // Insertion Sort
    duplica(tam, v, aux);
    t0 = clock();
    insertionSort(tam, aux);
    tempoInsertion[i] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaInsertion += tempoInsertion[i];
    printf("Insertion %d OK\n", i);
    // Bubble Sort
    duplica(tam, v, aux);
    t0 = clock();
    bubbleSort(tam, aux);
    tempoBubble[i] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaBubble += tempoBubble[i];
    printf("Bubble %d OK\n", i);
    // Quick Sort
    duplica(tam, v, aux);
    t0 = clock();
    quickSort(tam, aux);
    tempoQuick[i] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    mediaQuick += tempoQuick[i];
    printf("Quick %d OK\n", i);
  }
  fprintf(arq, "Tempo do Insertion Sort para cada vetor: ");
  for (i=0; i<pesq; i++){
    fprintf(arq, "%f ", tempoInsertion[i]);
  }
  fprintf(arq, "\n\nTempo do Bubble Sort para cada vetor: ");
  for (i=0; i<pesq; i++){
    fprintf(arq, "%f ", tempoBubble[i]);
  }
  fprintf(arq, "\n\nTempo do Quick Sort para cada vetor: ");
  for (i=0; i<pesq; i++){
    fprintf(arq, "%f ", tempoQuick[i]);
  }
  mediaInsertion /= pesq;
  mediaBubble /= pesq;
  mediaQuick /= pesq;
  printf("Tempo médio das ordenações com Inserção: %lf\n", mediaInsertion);
  printf("Tempo médio das ordenações com Bolha: %lf\n", mediaBubble);
  printf("Tempo médio das ordenações com Quick: %lf\n", mediaQuick);
  fprintf(arq, "\n\nTempo médio das ordenações com Inserção: %lf", mediaInsertion);
  fprintf(arq, "\n\nTempo médio das ordenações com Bolha: %f", mediaBubble);
  fprintf(arq, "\nTempo médio das ordenações com Quick: %f", mediaQuick);
  fclose(arq);
  free(aux);
  free(v);
  return 0;
}
