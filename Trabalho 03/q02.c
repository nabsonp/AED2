#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

#define vermelho "\x1b[31m"
#define verde "\x1b[32m"
#define reset   "\x1b[0m"

int main() {
    FILE* arquivo = (FILE*) fopen("alunos","wb+");
    int pesq = 30, tamTH = 11000, nReg = 10000;
    hash *indice = (hash*) malloc(sizeof(hash)*tamTH);
    gerarAlunosIdHash(arquivo, nReg, tamTH, indice);
    float media = 0, t;
    clock_t t0;

    printf("Tempos das buscas com indexação por Hash: ");
    for (int i=0; i<pesq; i++){
      t0= clock();
      aluno a = buscaIdHash(arquivo,tamTH,indice,105 + i*100);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      media += t;
      if (a.id == -1) printf(vermelho "%fs " reset, t); // Não achou
      else printf(verde "%fs " reset, t); // Achou
    }
    printf("\nTempo médio de buscas (HASH): %fs\n", media/pesq);
    fclose(arquivo);
    return 0;
}
