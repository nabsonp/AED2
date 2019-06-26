#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef _FILA_H_
#include "fila.h"
#define _FILA_H_
#endif

int criarGrafo(int t, int grafo[t][t], float conec);

void mostrarGrafo(int t, int grafo[t][t]);

int alterarConectividade(int t, int grafo[t][t], float conec);

char DFS(int t, int grafo[t][t], int inicio);

void BFS(int t, int grafo[t][t], int inicio);
