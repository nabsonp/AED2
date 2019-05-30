#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

#define vermelho "\x1b[31m"
#define verde "\x1b[32m"
#define reset   "\x1b[0m"

int main() {
    FILE* arquivo = (FILE*) fopen("alunos","wb+");
    int pesq = 30, tam = 10000, i, tamTH = tam + (tam/10);
    gerarAlunos(arquivo, tam);
    float media = 0, t;
    hash *indiceHash = (hash*) malloc(sizeof(hash)*tamTH);
    int colisoes = indexarHash(arquivo, tam, tamTH, indiceHash);
    noAVL *indiceAVL = indexarIdAVL(arquivo, 10000);
    clock_t t0;
    aluno a;

    // HASH
    printf("\t\t******** ÍNDICE COM HASH ********\n");
    printf("%d Colisões.\n",colisoes);
    printf("Tempos das buscas: ");
    for (i=0; i<pesq; i++){
      t0= clock();
      a = buscaIdHash(arquivo,tamTH,indiceHash,500 + i*100);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      media += t;
      if (a.id == -1) printf(vermelho "%fs " reset, t); // Não achou
      else printf(verde "%fs " reset, t); // Achou
    }
    printf("\nTempo médio de buscas: %fs\n", media/pesq);
    media = 0;

    // AVL
    printf("\n\t\t******** ÍNDICE COM AVL ********\n");
    printf("Tempos das buscas: ");
    for (i=0; i<pesq; i++){
      t0= clock();
      aluno a = buscaIdAVL(arquivo,indiceAVL,500 + i*100);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      media += t;
      if (a.id == -1) printf(vermelho "%fs " reset, t); // Não achou
      else printf(verde "%fs " reset, t); // Achou
    }
    printf("\nTempo médio de buscas: %fs\n", media/pesq);
    media = 0;

    // ARQUIVO
    printf("\n\t\t******** SEM ÍNDICE ********\n");
    printf("Tempos das buscas: ");
    for (i=0; i<pesq; i++){
      t0= clock();
      aluno a = buscaSequencial(arquivo,500 + i*100);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      media += t;
      if (a.id == -1) printf(vermelho "%fs " reset, t); // Não achou
      else printf(verde "%fs " reset, t); // Achou
    }
    printf("\nTempo médio de buscas: %fs\n", media/pesq);

    fclose(arquivo);
    return 0;
}
