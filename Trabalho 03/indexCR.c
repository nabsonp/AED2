#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef _ALUNO_H_
#include "aluno.h"
#define _ALUNO_H_
#endif
#ifndef _HASH_H_
#include "hash.h"
#define _HASH_H_
#endif
#ifndef _AVL_H_
#include "avl.h"
#define _AVL_H_
#endif
#ifndef _LISTA_H_
#include "lista.h"
#define _LISTA_H_
#endif

#define vermelho "\x1b[31m"
#define verde "\x1b[32m"
#define reset   "\x1b[0m"

int main() {
    int tam = 10000, buscas[30];
    FILE* arquivo = (FILE*) fopen("alunos","wb+");
    gerarAlunos(arquivo, tam, buscas);
    noAVL *indice = indexarCrAVL(arquivo, tam);
    tipoLista *lista = (tipoLista*) malloc(sizeof(tipoLista));
    criar(lista);
    float temposAVL[4] = {0,0,0,0}, temposArq[4]={0,0,0,0}, t;
    float valores[30] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0.5,1,1.5,2,2.5,3,3.5,
    4,4.5,5,5.5,6,6.5,7,7.5,8,8.5,9,9.5};
    clock_t t0;

    for (int j=0; j<30; j++) {
      printf("-> %dª busca, valor: %.2f",j+1,valores[j]);

      printf(verde "\n\t******* Busca por intervalos em AVL *******\n" reset);
      printf(verde "\tMenores que %.2f:" reset, valores[j]);
      t0= clock();
      buscarMenoresAVL(arquivo,indice,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n", qtdElementos(*lista),t);
      temposAVL[0] += t;
      dropLista(lista);
      printf(verde "\tMenores ou iguais a %.2f:" reset, valores[j]);
      t0= clock();
      buscarMenoresOuIguaisAVL(arquivo,indice,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n", qtdElementos(*lista),t);
      temposAVL[1] += t;
      dropLista(lista);
      printf(verde "\tMaiores que %.2f:" reset, valores[j]);
      t0= clock();
      buscarMaioresAVL(arquivo,indice,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n", qtdElementos(*lista),t);
      temposAVL[2] += t;
      dropLista(lista);
      printf(verde "\tMaiores ou iguais a %.2f:" reset, valores[j]);
      t0= clock();
      buscarMaioresOuIguaisAVL(arquivo,indice,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n", qtdElementos(*lista),t);
      temposAVL[3] += t;
      dropLista(lista);

      printf(vermelho "\n\t******* Busca por intervalos em Arquivo *******\n" reset);
      printf(vermelho "\tMenores que %.2f:" reset, valores[j]);
      t0= clock();
      buscarMenoresArq(arquivo,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n", qtdElementos(*lista),t);
      temposArq[0] += t;
      dropLista(lista);
      printf(vermelho "\tMenores ou iguais a %.2f:" reset, valores[j]);
      t0= clock();
      buscarMenoresOuIguaisArq(arquivo,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n", qtdElementos(*lista),t);
      temposArq[1] += t;
      dropLista(lista);
      printf(vermelho "\tMaiores que %.2f:" reset, valores[j]);
      t0= clock();
      buscarMaioresArq(arquivo,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n", qtdElementos(*lista),t);
      temposArq[2] += t;
      dropLista(lista);
      printf(vermelho "\tMaiores ou iguais a %.2f:" reset, valores[j]);
      t0= clock();
      buscarMaioresOuIguaisArq(arquivo,valores[j],lista);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      printf("%d em %fs\n\n", qtdElementos(*lista),t);
      temposArq[3] += t;
      dropLista(lista);
    }

    printf("--------------------------------------------------------");
    printf("\n\t-> Tempo médio de buscas por menores em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[0]/30);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[0]/30);
    printf("\t-> Tempo médio de buscas por menores ou iguais em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[1]/30);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[1]/30);
    printf("\t-> Tempo médio de buscas por maiores em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[2]/30);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[2]/30);
    printf("\t-> Tempo médio de buscas por maiores ou iguais em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[3]/30);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[3]/30);

    printf("\n");
    fclose(arquivo);
    return 0;
}
