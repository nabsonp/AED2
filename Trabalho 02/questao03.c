#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"
#include "vetor.h"
int main() {
    int tam = 1000000, vet[tam], tamBusca = 30, busca[tamBusca], j;
    float tempoVet[tamBusca], tempoABP[tamBusca], tempoMedioVet = 0, tempoMedioABP = 0;
    clock_t t0;

    gerarVetorDesordenado(tam, vet);
    gerarVetPesquisa(tamBusca,busca,tam,vet);
    no *r = criarArvore();
    r = converterVetorABP(r,tam,vet);
    printf("a\n");
    quickSort(tam,vet);
    for (j=0; j<tamBusca; j++) {
      // Busca no vetor
      t0 = clock();
      buscaBinaria(tam,vet,busca[j]);
      tempoVet[j] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      tempoMedioVet += tempoVet[j];

      // Busca na ABP
      t0 = clock();
      buscaABP(r,busca[j]);
      tempoABP[j] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      tempoMedioABP += tempoABP[j];
    }

    tempoMedioVet /= tamBusca;
    printf("Tempos de busca no vetor: ");
    for (j=0; j<tamBusca; j++) {
      printf("%fs ", tempoVet[j]);
    }
    printf("\nTempo médio: %fs\n", tempoMedioVet);

    tempoMedioABP /= tamBusca;
    printf("\nTempos de busca na ABP: ");
    for (j=0; j<tamBusca; j++) {
      printf("%fs ", tempoABP[j]);
    }
    printf("\nTempo médio: %fs\n", tempoMedioABP);
    return 0;
}
