#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

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
    float valor, temposAVL[4], temposArq[4];
    clock_t t0;

    printf("Insira um valor para buscar: ");
    scanf("%f", &valor);
    // caminhamentoPrefixado(indice);

    // printf(verde "\n******* Busca por intervalos em AVL *******\n" reset);
    // printf(verde "Menores que %.2f:" reset, valor);
    t0= clock();
    buscarMenoresAVL(arquivo,indice,valor,lista);
    temposAVL[0] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);
    // printf(verde "Menores ou iguais a %.2f:" reset, valor);
    t0= clock();
    buscarMenoresOuIguaisAVL(arquivo,indice,valor,lista);
    temposAVL[1] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);
    // printf(verde "Maiores que %.2f:" reset, valor);
    t0= clock();
    buscarMaioresAVL(arquivo,indice,valor,lista);
    temposAVL[2] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);
    // printf(verde "Maiores ou iguais a %.2f:" reset, valor);
    t0= clock();
    buscarMaioresOuIguaisAVL(arquivo,indice,valor,lista);
    temposAVL[3] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);

    // printf(vermelho "\n******* Busca por intervalos em Arquivo *******\n" reset);
    // printf(vermelho "Menores que %.2f:" reset, valor);
    t0= clock();
    buscarMenoresArq(arquivo,valor,lista);
    temposArq[0] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);
    // printf(vermelho "Menores ou iguais a %.2f:" reset, valor);
    t0= clock();
    buscarMenoresOuIguaisArq(arquivo,valor,lista);
    temposArq[1] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);
    // printf(vermelho "Maiores que %.2f:" reset, valor);
    t0= clock();
    buscarMaioresArq(arquivo,valor,lista);
    temposArq[2] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);
    // printf(vermelho "Maiores ou iguais a %.2f:" reset, valor);
    t0= clock();
    buscarMaioresOuIguaisArq(arquivo,valor,lista);
    temposArq[3] = (clock() - t0)/ (double) CLOCKS_PER_SEC;
    // mostrarLista(*lista);
    dropLista(lista);

    printf("\n\tTempo médio de buscas por menores em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[0]);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[0]);
    printf("\tTempo médio de buscas por menores ou iguais em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[1]);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[1]);
    printf("\tTempo médio de buscas por maiores em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[2]);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[2]);
    printf("\tTempo médio de buscas por maiores ou iguais em:\n");
    printf(verde "\t\tAVL: %fs\n" reset, temposAVL[3]);
    printf(vermelho "\t\tArq: %fs\n" reset, temposArq[3]);

    printf("\n");
    fclose(arquivo);
    return 0;
}
