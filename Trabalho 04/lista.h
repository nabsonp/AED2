typedef struct tipoNo{
  int dado;
  struct tipoNo *prox;
} tipoNo;

typedef struct {
  tipoNo *prim;
} tipoLista;

void criar(tipoLista *l);

int inserirEmLista(tipoLista *l, int d);

int remover(tipoLista *l, int id);

tipoNo* buscaSequencialLista(tipoLista l, int valor);

void dropLista(tipoLista *l);

void mostrarLista(tipoLista l);

void mostrarListaInversa(tipoNo *l);
