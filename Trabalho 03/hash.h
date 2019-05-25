typedef struct hash {
  int id;
  int indice;
} hash;

int h(int id);

int buscaHash(int id, int tam, hash ht[]);

int inserirHash(int id, int indice, int tam, hash th[]);

void tabelaHash(int tam, hash th[]);
