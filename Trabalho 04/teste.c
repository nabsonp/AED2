#include<stdio.h>
#include "grafo.h"

int main() {
    int grafo[10][10];
    criarGrafo(10,grafo,0.5);
    mostrarGrafo(10,grafo);
    return 0;
}
