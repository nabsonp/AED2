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
  float mediaVet = 0, mediaLista = 0, tempoVet[pesq], tempoLista[pesq];
  tipoLista l;
  FILE *arq = fopen("questao02.txt","w");
  time_t t;
  clock_t t0;
  srand((unsigned) time(&t));
  printf("Preencher vetor de 1M.\n");
  scanf("%d", &i);
  getVetorDesordenado(tam, v);
  printf("Converter vetor em lista de 1M.\n");
  scanf("%d", &i);
  converteVetor(&l, tam, v);
  for (i=0; i<10; i++) {
    val[i] = v[i+100000];
  }
  for (i=10; i<pesq; i++) {
    val[i] = rand()%tam;
  }
  printf("Iniciar buscas.\n");
  scanf("%d", &i);
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
  printf("Finalizar buscas.\n");
  scanf("%d", &i);
  mediaVet /= pesq;
  mediaLista /= pesq;
  printf("Tempo médio das buscas no vetor: %lf\n", mediaVet);
  printf("Tempo médio das buscas na lista: %lf\n", mediaLista);
  fprintf(arq, "\n\nTempo médio das buscas no vetor: %f", mediaVet);
  fprintf(arq, "\nTempo médio das buscas na lista: %f", mediaLista);
  fclose(arq);
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
