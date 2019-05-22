#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
int main() {
    FILE* arquivo = (FILE*) fopen("alunos","wb+");
    noAVL *indice = gerarAlunosCR(arquivo, 20);
    aluno a = pesqIndice(arquivo,3);
    printf("%d\n", a.id);
    printf("Altura: %d\n", indice->altura);
    caminhamentoInfixado(indice);
    printf("\n");
    fclose(arquivo);
    return 0;
}
