typedef struct tipoNo{
  int id;
  char nome[20];
  float cr;
  char curso[30];
  int idade;
  struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
  tipoNo *prim;
} tipoLista;

void criar(tipoLista *l);

int inserirEmLista(tipoLista *l, int id, float cr, int idade, char *curso, char *nome);

tipoNo* buscaSequencialLista(tipoLista l, float valor);

void mostrarLista(tipoLista lista);

void dropLista(tipoLista *l);
