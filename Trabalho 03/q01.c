#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "aluno.h"

#define vermelho "\x1b[31m"
#define verde "\x1b[32m"
#define reset   "\x1b[0m"

int main() {
    FILE* arquivo = (FILE*) fopen("alunos","wb+");
    noAVL *indice = gerarAlunosIdAVL(arquivo, 100000);
    float media = 0, t;
    int pesq = 30;
    clock_t t0;

    printf("Tempos das buscas com indexação por AVL: ");
    for (int i=0; i<pesq; i++){
      t0= clock();
      aluno a = buscaIdAVL(arquivo,indice,2018000 + i*100);
      t = (clock() - t0)/ (double) CLOCKS_PER_SEC;
      media += t;
      if (a.id == -1) printf(vermelho "%fs " reset, t); // Não achou
      else printf(verde "%fs " reset, t); // Achou
    }
    printf("\nTempo médio de buscas (AVL): %fs\n", media/pesq);
    fclose(arquivo);
    return 0;
}
