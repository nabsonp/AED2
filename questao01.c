#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"

int main() {
  int  pesq = 30, tam = 1000000, val[pesq], i;
  int *v = (int*) malloc(sizeof(int)*tam);
  float mediaSeq = 0, mediaBin = 0, tempoSeq[pesq], tempoBin[pesq];
  FILE *arq = fopen("questao01.txt","w");
  time_t t;
  clock_t t0;
  srand((unsigned) time(&t));
  getVetorOrdenado(tam, v);
  for (i=0; i<10; i++) {
    val[i] = v[i+100000];
  }
  for (i=10; i<pesq; i++) {
    val[i] = rand()%tam;
  }
  fprintf(arq, "Tempo das Buscas Sequenciais: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaSequencialVetor(tam, v, val[i]);
    tempoSeq[i] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    fprintf(arq, "%f ", tempoSeq[i]);
    mediaSeq += tempoSeq[i];
  }
  fprintf(arq, "\n\nTempo das Buscas Binárias: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaBinaria(tam, v, val[i]);
    tempoBin[i] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    fprintf(arq, "%f ", tempoBin[i]);
    mediaBin += tempoBin[i];
  }
  mediaSeq /= pesq;
  mediaBin /= pesq;
  printf("Tempo médio das Buscas Sequenciais: %lf\n", mediaSeq);
  printf("Tempo médio das Buscas Binárias: %lf\n", mediaBin);
  fprintf(arq, "\n\nTempo médio das Buscas Sequenciais: %f", mediaSeq);
  fprintf(arq, "\nTempo médio das Buscas Binárias: %f", mediaBin);
  fclose(arq);
  free(v);
  return 0;
}
