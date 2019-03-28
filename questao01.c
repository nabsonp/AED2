#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"

int main() {
  int  pesq = 30, tam = 1000000, val[pesq], i;
  printf("Alocar vetor de 1M.\n");
  scanf("%d", &i);
  int *v = (int*) malloc(sizeof(int)*tam);
  float mediaSeq = 0, mediaBin = 0, tempoSeq[pesq], tempoBin[pesq];
  printf("Abrir arquivo.\n");
  scanf("%d", &i);
  FILE *arq = fopen("questao01.txt","w");
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
  printf("Finalizar buscas.\n");
  scanf("%d", &i);
  mediaSeq /= pesq;
  mediaBin /= pesq;
  printf("Tempo médio das Buscas Sequenciais: %lf\n", mediaSeq);
  printf("Tempo médio das Buscas Binárias: %lf\n", mediaBin);
  fprintf(arq, "\n\nTempo médio das Buscas Sequenciais: %f", mediaSeq);
  fprintf(arq, "\nTempo médio das Buscas Binárias: %f", mediaBin);
  printf("Fechar arquivo.\n");
  scanf("%d", &i);
  fclose(arq);
  printf("Liberar vetor de 1M.\n");
  scanf("%d", &i);
  free(v);
  printf("Finalizar processo.\n");
  scanf("%d", &i);
  return 0;
}
