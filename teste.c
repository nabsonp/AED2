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
    caminhamentoInfixado(raiz);
    return 0;
}
