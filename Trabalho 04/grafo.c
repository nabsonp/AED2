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
  int bt = 0;
  printf("%d ", inicio);
  for (int i=0; i<t; i++) {
    if (grafo[inicio][i] == 1 && cor[i] == 0) {
      cor[i] = 1; // Pinta de cinza
      if (bt) printf("\n\t\t... %d ", inicio); // Backtracking
      DFS_rec(t, grafo, i, cor, ciclo);
      bt = 1;
    } else if (cor[i] != 0) *ciclo = 1;
  }
  cor[inicio] = 2; // Já passou por todos os adjacentes, então pinta de preto
}

char DFS(int t, int grafo[t][t], int inicio) {
  int i;
  char cor[t], *ciclo = (char*) malloc(sizeof(char));
  *ciclo = 0;
  printf("\n\t\t");
  for (i=0; i<t; i++) cor[i] = 0; // Colore todos de branco
  cor[inicio] = 1;
  DFS_rec(t, grafo, inicio, cor, ciclo); // Realiza a DFS recursivamente
  // Verifica se tem algum vértice desconexo que não foi visitado
  for (i=0; i<t; i++) {
    if (cor[i] == 0) {
      printf("\n\t\t-\n\t\t");
      cor[i] = 1;
      DFS_rec(t, grafo, i, cor, ciclo);
    }
  }
  return *ciclo;
}

void BFS(int t, int grafo[t][t], int inicio) {
  tipoFila *fila = (tipoFila*) malloc(sizeof(tipoFila));
  int distancia[t], i, prox;
  for (i=0; i<t; i++) distancia[i] = -1;
  distancia[inicio] = 0;
  criar(fila);
  prox = inicio;
  // printf("\n\t %d\n\t",inicio);
  while (prox != -1) { // Código  para fila vazia
    for (i=0; i<t; i++) {
        if (grafo[prox][i] == 1 && distancia[i] == -1) {
          enfileirarSemRepeticao(fila, i);
          distancia[i] = distancia[prox]+1;
          // printf("%d ", i);
        }
    }
    // printf("\n\t");
    prox = desenfileirar(fila);
  }
  for (i=0; i<t; i++) printf("%d ",distancia[i]);
}
