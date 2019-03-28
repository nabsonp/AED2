#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"
#include "lista.h"

int main() {
  int  pesq = 30, tam = 1000000, val[pesq], i;
  int *v = (int*) malloc(sizeof(int)*tam);
  float mediaVet = 0, mediaLista = 0, tempoVet[pesq], tempoLista[pesq];
  tipoLista l;
  FILE *arq = fopen("questao02.txt","w");
  time_t t;
  clock_t t0;
  srand((unsigned) time(&t));
  getVetorDesordenado(tam, v);
  converteVetor(&l, tam, v);
  for (i=0; i<10; i++) {
    val[i] = v[i+100000];
  }
  for (i=10; i<pesq; i++) {
    val[i] = rand()%tam;
  }
  fprintf(arq, "Tempo das buscas no vetor: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaSequencialVetor(tam, v, val[i]);
    tempoVet[i] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    fprintf(arq, "%f ", tempoVet[i]);
    mediaVet += tempoVet[i];
  }
  fprintf(arq, "\n\nTempo das buscas na lista: ");
  for (i=0; i<pesq; i++) {
    t0 = clock();
    buscaSequencialLista(l, val[i]);
    tempoLista[i] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    fprintf(arq, "%f ", tempoLista[i]);
    mediaLista += tempoLista[i];
  }
  mediaVet /= pesq;
  vediaLista /= pesq;
  printf("Tempo médio das buscas no vetor: %lf\n", mediaVet);
  printf("Tempo médio das buscas na lista: %lf\n", mediaLista);
  fprintf(arq, "\n\nTempo médio das buscas no vetor: %f", mediaVet);
  fprintf(arq, "\nTempo médio das buscas na lista: %f", mediaLista);
  fclose(arq);
  fclose(arq);
  free(v);
  return 0;
}
