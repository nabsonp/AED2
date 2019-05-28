// #include "aluno.h"

typedef struct tipoNo{
  aluno a;
  struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
  tipoNo *prim;
} tipoLista;

void criar(tipoLista *l);

int inserirEmLista(tipoLista *l, aluno a);

tipoNo* buscaSequencialLista(tipoLista l, float valor);

void mostrarLista(tipoLista lista);

void dropLista(tipoLista *l);
