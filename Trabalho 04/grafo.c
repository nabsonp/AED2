#include "grafo.h"
#ifndef _FILA_H_
#include "fila.h"
#define _FILA_H_
#endif

#define verde "\x1b[32m"
#define reset   "\x1b[0m"
#define azul    "\x1b[36m"

int criarGrafo(int t, int grafo[t][t], float conec) {
    int qtd = 0, i, j, cnt = 0;
    for (i=1; i<t; i++) qtd += i;
    qtd *= conec;
    for (i=0; i<t; i++) {
        for (j=0; j<t; j++) {
            grafo[i][j] = 0;
        }
    }
    time_t tmp;
    srand((unsigned) time(&tmp));
    for (int n=0; n<qtd; n++) {
        i = rand() % t;
        j = rand() % t;
        if (i != j && grafo[i][j] == 0) {
            grafo[i][j] = 1;
            grafo[j][i] = 1;
            cnt++;
        } else n--;
    }
    return cnt;
}

void mostrarGrafo(int t, int grafo[t][t]) {
    printf("-> Grafo com %d vértices:\n\t  ", t);
    for (int i=0; i<t; i++) printf(azul "%d " reset,i);
    for (int i=0; i<t; i++) {
        printf(azul "\n\t%d " reset,i);
        for (int j=0; j<t; j++) {
            if (grafo[i][j]) printf(verde "%d " reset, grafo[i][j]);
            else printf("%d ",  grafo[i][j]);
        }
    }
    printf("\n");
}

int alterarConectividade(int t, int grafo[t][t], float conec) {
  int qtd = 0, i, j, cnt = 0;
  for (i=1; i<t; i++) qtd += i;
  qtd *= conec;
  time_t tmp;
  srand((unsigned) time(&tmp));
  for (int n=0; n<qtd; n++) {
      i = rand() % t;
      j = rand() % t;
      if (i != j && grafo[i][j] == 0) {
          grafo[i][j] = 1;
          grafo[j][i] = 1;
          cnt++;
      } else n--;
  }
  return cnt;
}

int DFS_rec(int t, int grafo[t][t], int inicio, char cor[], char *ciclo) {
  int bt = 0, aux = 0;
  printf("%d ", inicio);
  for (int i=0; i<t; i++) {
    if (grafo[inicio][i] == 1 && cor[i] == 0) {
      cor[i] = 1; // Pinta de cinza
      if (bt) printf("\n\t\t... %d ", inicio); // Backtracking
      DFS_rec(t, grafo, i, cor, ciclo);
      cor[i] = 0;
      bt = 1;
    }
    if (grafo[inicio][i] == 1 && cor[i] != 0) if (aux == 1) *ciclo = 83; else aux = 1;
  }
  cor[inicio] = 2; // Já passou por todos os adjacentes, então pinta de preto
}

char DFS(int t, int grafo[t][t], int inicio) {
  int i;
  char cor[t], *ciclo = (char*) malloc(sizeof(char));
  *ciclo = 78;
  printf("\n\t\t");
  for (i=0; i<t; i++) cor[i] = 0; // Colore todos de branco
  cor[inicio] = 1;
  DFS_rec(t, grafo, inicio, cor, ciclo); // Realiza a DFS recursivamente
  i = *ciclo;
  free(ciclo);
  return i;
}

void BFS(int t, int grafo[t][t], int inicio) {
  tipoFila *fila = (tipoFila*) malloc(sizeof(tipoFila));
  int distancia[t], i, prox;
  for (i=0; i<t; i++) distancia[i] = -1;
  distancia[inicio] = 0;
  criar(fila);
  prox = inicio;
  while (prox != -1) { // Código  para fila vazia
    for (i=0; i<t; i++) {
        if (grafo[prox][i] == 1 && distancia[i] == -1) {
          enfileirarSemRepeticao(fila, i);
          distancia[i] = distancia[prox]+1;
        }
    }
    prox = desenfileirar(fila);
  }
  printf("\n\t\tVértices:   "azul);
  for (i=0; i<t; i++) printf("%d ",i);
  printf(reset "\n\t\tDistâncias: "verde);
  for (i=0; i<t; i++) printf("%d ",distancia[i]);
  printf(reset);
}
