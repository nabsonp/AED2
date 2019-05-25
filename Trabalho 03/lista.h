#include "aluno.h"

typedef struct tipoNo{
  aluno a;
  struct tipoNo *prox;
} tipoNo;

typedef struct {
  tipoNo *prim;
} tipoLista;

void criar(tipoLista *l);

int inserirEmLista(tipoLista *l, aluno a);

tipoNo* buscaSequencialLista(tipoLista l, float valor);

void mostrarLista(tipoLista lista) {
  while (lista.prim) {
    print("ID: %d", lista.prim->id);
    print("Nome: %s", &(lista.prim->nome));
    print("CR: %f", lista.prim->cr);
    print("Curso: %s", &(lista.prim->curso));
    print("Idade: %d", lista.prim->idade);
    lista.prim = lista.prim->prox;
  }
}

void dropLista(tipoLista *l);
