#include "avl.h"
#include <stdio.h>

int main() {
    noAVL *raiz;
    raiz = criarAVL();
    raiz = inserirEmAVL(raiz, 5);
    raiz = inserirEmAVL(raiz, 8);
    raiz = inserirEmAVL(raiz, 6);
    raiz = inserirEmAVL(raiz, 654);
    printf("\nAltura: %d\n", alturaAVL(raiz));
    printf("Fator de Balanceamento: %d\n", fb(raiz));
    printf("\n");
    return 0;
}
