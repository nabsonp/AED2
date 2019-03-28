typedef struct {
  int valor;
} tipoDados;

typedef struct tipoNo{
  tipoDados d;
  struct tipoNo *prox;
} tipoNo;

typedef struct {
  tipoNo *prim;
} tipoLista;

void criar(tipoLista *l);

int inserir(tipoLista *l, tipoDados d);

int remover(tipoLista *l, int id);

void listaDesordenada(tipoLista *l, int tam);

void converteVetor(tipoLista *l, int tam, int vet[]);

tipoNo* buscaSequencialLista(tipoLista l, int valor);

void dropLista(tipoLista *l);
