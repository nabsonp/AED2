#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"
#include "avl.h"
#include "vetor.h"
int main() {
  int tam = 1000000, *vet, tamBusca = 30, *busca, arvores = 10, i, j;
  float aux, tempoMedioBuscaABP = 0, tempoMedioBuscaAVL = 0, tempoMedioCriacaoABP = 0, tempoMedioCriacaoAVL = 0;
  clock_t t0;
  vet = (int*) malloc(tam*sizeof(int));
  busca = (int*) malloc(tamBusca*sizeof(int));
  no *abp = criarArvore();
  noAVL *avl = criarAVL();

  for (i=0; i<arvores; i++) {
    gerarVetorDesordenadoSemRepeticoes(tam,vet);

    printf("***** %da LEVA DE ÁRVORES *****\n", (i+1));

    // Criação da ABP
    t0 = clock();
    abp = converterVetorABP(abp,tam,vet);
    aux = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    tempoMedioCriacaoABP += aux;
    printf("-> Tempo de criação da ABP: %fs\n", aux);
    printf("-> Altura da ABP: %d\n", alturaArvore(abp));

    // Criação da AVL
    t0 = clock();
    avl = converterVetorAVL(avl,tam,vet);
    aux = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    tempoMedioCriacaoAVL += aux;
    printf("-> Tempo de criação da AVL: %fs\n", aux);
    printf("-> Altura da AVL: %d\n", alturaAVL(avl));

    gerarVetPesquisa(tamBusca,busca,tam,vet);
    // Buscas na ABP
    printf("\n-> Tempos de busca na ABP: ");
    for (j=0; j<tamBusca; j++) {
      t0 = clock();
      buscaABP(abp,busca[j]);
      aux = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      tempoMedioBuscaABP += aux;
      printf("%fs ", aux);
    }
    printf("\n-> Tempo médio: %fs\n", tempoMedioBuscaABP);
    tempoMedioBuscaABP = 0;

    // Buscas na AVL
    printf("\n-> Tempos de busca na AVL: ");
    for (j=0; j<tamBusca; j++) {
      t0 = clock();
      buscaAVL(avl,busca[j]);
      aux = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      tempoMedioBuscaAVL += aux;
      printf("%fs ", aux);
    }
    printf("\n-> Tempo médio: %fs\n\n", tempoMedioBuscaAVL);
    tempoMedioBuscaAVL = 0;
    abp = dropABP(abp);
    avl = dropAVL(avl);
  }
  free(vet);
  free(busca);
  tempoMedioCriacaoABP /= arvores;
  tempoMedioCriacaoAVL /= arvores;
  printf("-> Tempo médio de criação das ABPs: %f\n",tempoMedioCriacaoABP);
  printf("-> Tempo médio de criação das AVLs: %f\n",tempoMedioCriacaoAVL);
  return 0;
}
