#include "abp.h"
#include <stdio.h>

int main() {
    no *raiz;
    criarArvore(raiz);
    int d = 5;
    raiz = inserirEmABP(raiz, d);
    d = 0;
    inserirEmABP(raiz, d);
    d = 2;
    inserirEmABP(raiz, d);
    d = 88;
    inserirEmABP(raiz, d);
    printf("Caminhamento pré-fixado: ");
    caminhamentoPrefixado(raiz);
    printf("\nCaminhamento infixado: ");
    caminhamentoInfixado(raiz);
    printf("\nCaminhamento pós-fixado: ");
    caminhamentoPosfixado(raiz);
    printf("\n");
    return 0;
}
