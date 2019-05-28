#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

#define vermelho "\x1b[31m"
#define verde "\x1b[32m"
#define reset   "\x1b[0m"

int main() {
    FILE* arquivo = (FILE*) fopen("alunos","wb+");
    noAVL *indice = gerarAlunosCrAVL(arquivo, 10);
    tipoLista *lista = (tipoLista*) malloc(sizeof(tipoLista));
    criar(lista);

    caminhamentoInfixado(indice);
    buscarMaioresOuIguais(arquivo,indice,8,lista);
    mostrarLista(*lista);

    printf("\n");
    fclose(arquivo);
    return 0;
}