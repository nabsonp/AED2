#include "abp.h"
#include <stdio.h>

int main() {
    no *raiz;
    criarArvore(raiz);
    raiz = inserirEmABP(raiz, 5);
    inserirEmABP(raiz, 4);
    inserirEmABP(raiz, 2);
    inserirEmABP(raiz, 6);
    printf("Caminhamento pré-fixado: ");
    caminhamentoPrefixado(raiz);
    printf("\nCaminhamento infixado: ");
    caminhamentoInfixado(raiz);
    printf("\nCaminhamento pós-fixado: ");
    caminhamentoPosfixado(raiz);
    printf("\n");
    return 0;
}
