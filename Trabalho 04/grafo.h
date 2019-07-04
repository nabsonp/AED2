#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef _FILA_H_
#include "fila.h"
#define _FILA_H_
#endif

int criarGrafo(int t, int **grafo, float conec);

void mostrarGrafo(int t, int **grafo);

int alterarConectividade(int t, int **grafo, float conec);

char acharTodosCaminhos(int t, int **grafo, int inicio, char printar);

void DFS(int t, int **grafo, int inicio, char printar);

void BFS(int t, int **grafo, int inicio, char printar);
