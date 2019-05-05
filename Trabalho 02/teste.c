#include "avl.h"
#include <stdio.h>

int main() {
    no *raiz;
    raiz = criarArvore();
    raiz = inserirEmAVL(raiz, 5);
    raiz = inserirEmAVL(raiz, 8);
    raiz = inserirEmAVL(raiz, 55);
    raiz = inserirEmAVL(raiz, 555);
    printf("Caminhamento pré-fixado: ");
    caminhamentoPrefixado(raiz);
    printf("\nAltura: %d\n", alturaArvore(raiz));
    printf("Fator de Balanceamento: %d\n", fb(raiz));
    printf("\n");
    return 0;
}
