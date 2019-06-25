#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef _LISTA_H_
#include "lista.h"
#define _LISTA_H_
#endif

int criarGrafo(int t, int grafo[t][t], float conec);

void mostrarGrafo(int t, int grafo[t][t]);

void DFS(int t, int grafo[t][t], int inicio);
