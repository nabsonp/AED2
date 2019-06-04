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
    FILE* arquivo = (FILE*) fopen("alunos","wb+");
    int pesq = 30, buscas[pesq], tam = 100000, i, tamTH = 200000;
    gerarAlunos(arquivo, tam, buscas);
    float media = 0, t;
    hash *indiceHash = (hash*) malloc(sizeof(hash)*tamTH);
    int colisoes = indexarHash(arquivo, tam, tamTH, indiceHash);
    noAVL *indiceAVL = indexarIdAVL(arquivo, tam);
    clock_t t0;
    aluno a;

    // HASH
    printf("\t\t******** ÍNDICE COM HASH ********\n");
    printf("Colisões: %d.\n",colisoes);
    printf("Tempos das buscas: ");
    for (i=0; i<pesq; i++){
      t0= clock();
      a = buscaIdHash(arquivo,tamTH,indiceHash, buscas[i]);
      t = (clock() - t0);
      if (a.id == -1) printf(vermelho "%.2fms " reset, t); // Não achou
      else {
         printf(verde "%.2fms " reset, t); // Achou
         media += t;
       }
    }
    printf("\nTempo médio de buscas: %.2fms\n", media/pesq);
    media = 0;

    // AVL
    printf("\n\t\t******** ÍNDICE COM AVL ********\n");
    printf("Altura: %d.\n", alturaAVL(indiceAVL));
    printf("Tempos das buscas: ");
    for (i=0; i<pesq; i++){
      t0= clock();
      a = buscaIdAVL(arquivo,indiceAVL, buscas[i]);
      t = (clock() - t0);
      if (a.id == -1) printf(vermelho "%.2fms " reset, t); // Não achou
      else {
         printf(verde "%.2fms " reset, t); // Achou
         media += t;
       }
    }
    printf("\nTempo médio de buscas: %.2fms\n", media/pesq);
    media = 0;

    // ARQUIVO
    printf("\n\t\t******** SEM ÍNDICE ********\n");
    printf("Registros: %d.\n", tam);
    printf("Tempos das buscas: ");
    for (i=0; i<pesq; i++){
      t0= clock();
      a = buscaSequencial(arquivo, buscas[i]);
      t = (clock() - t0);
      if (a.id == -1) printf(vermelho "%.2fms " reset, t); // Não achou
      else {
         printf(verde "%.2fms " reset, t); // Achou
         media += t;
       }
    }
    printf("\nTempo médio de buscas: %.2fms\n", media/pesq);

    fclose(arquivo);
    return 0;
}
