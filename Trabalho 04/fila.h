typedef struct tipoNo{
  int dado;
  struct tipoNo *prox;
} tipoNo;

typedef struct {
  tipoNo *prim;
  tipoNo *ult;
} tipoFila;

void criar(tipoFila *l);

int enfileirar(tipoFila *l, int d);

int enfileirarSemRepeticao(tipoFila *l, int d);

int desenfileirar(tipoFila *l);

void dropFila(tipoFila *l);

void mostrarFila(tipoFila l);

void mostrarFilaInversa(tipoNo *l);
