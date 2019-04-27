#include "avl.h"
#include <stdio.h>

int main() {
    no *raiz;
    criarArvore(raiz);
    raiz = inserirEmAVL(raiz, 5);
    inserirEmAVL(raiz, 4);
    inserirEmAVL(raiz, 2);
    printf("Caminhamento pré-fixado: ");
    caminhamentoPrefixado(raiz);
    printf("\nAltura: %d\n", alturaArvore(raiz));
    printf("Fator de Balanceamento: %d\n", fb(raiz));
    printf("\n");
    return 0;
}
