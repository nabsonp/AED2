#include <stdio.h>
#include <stdlib.h>
#include "abp.h"
#include "vetor.h"
int main() {
    int tam = 200, *pacotes;
    pacotes = (int*) malloc(sizeof(int)*tam);
    gerarVetorParcialmenteOrdenado(tam, pacotes);
    no *raiz = recebimentoDePacotes(raiz,tam,pacotes);
    printf("Pacotes: ");
    percorrerVetor(tam,pacotes);
    printf("\nArquivo montado: ");
    caminhamentoInfixado(raiz);
    printf("\n");
    return 0;
}
