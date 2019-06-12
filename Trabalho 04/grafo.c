#include "grafo.h"

#define verde "\x1b[32m"
#define reset   "\x1b[0m"

void criarGrafo(int t, int grafo[t][t], float conec) {
    int v = t*t*conec/2 + t/2, i, j;
    for (i=0; i<t; i++) {
        for (j=0; j<t; j++) {
            grafo[i][j] = 0;
        }
    }
    time_t tmp;
    srand((unsigned) time(&tmp));
    for (int n=0; n<v; n++) {
        i = rand() % 10;
        j = rand() % 10;
        if (grafo[i][j] == 0) {
            grafo[i][j] = 1;
            grafo[j][i] = 1;
        } else
            n--;
    }
}

void mostrarGrafo(int t, int grafo[t][t]) {
    printf("-> %d vértices", t*t);
    for (int i=0; i<t; i++) {
        printf("\n\t");
        for (int j=0; j<t; j++) {
            if (grafo[i][j]) printf(verde "%d " reset, grafo[i][j]);
            else printf("%d ",  grafo[i][j]);
        }
    }
    printf("\n");
}
