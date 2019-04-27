#include "abp.h"
#include <stdio.h>

int main() {
    no *raiz = criarArvoreAleatoria(raiz,50);
    printf("Caminhamento pré-fixado: ");
    caminhamentoPrefixado(raiz);
    printf("\nCaminhamento infixado: ");
    caminhamentoInfixado(raiz);
    printf("\nCaminhamento pós-fixado: ");
    caminhamentoPosfixado(raiz);
    printf("\n");
    return 0;
}
