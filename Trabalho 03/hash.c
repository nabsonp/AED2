#include "hash.h"

int primo = 10007;

int h(int id) {
  return id % primo; // Primo para 100K registros
}

int buscaHash(int id, int tam, hash ht[]) {
  int i = h(id);
  if (ht[i].id == -1)
    return -1; // Código de registro não encontrado
  else {
    if (id == ht[i].id)
      return ht[i].indice; // Retorna o índice do registro no arquivo
    else {
      // Busca sequencial na área de overflow
      for (i=100001; i<tam; i++) {
        if (id == ht[i].id)
          return ht[i].indice;
        else if (ht[i].id == -1)
          break;
      }
    }
  }
  return -1;
}

int inserirHash(int id, int indice, int tam, hash th[]) {
  hash hs;
  hs.id = id;
  hs.indice = indice;
  int i = h(id);
  if (th[i].id == -1) {
    th[i] = hs;
    return 1;
  } else {
    // Deu colisão, então manda para a área de overflow
    for (i=primo; i<tam; i++) {
      if (th[i].id == -1)
        th[i] = hs;
        return -1;
    }
  }
  return 0; // Código de tabela cheia, impossível inserir
}

void tabelaHash(int tam, hash th[]){
  for (int i=0; i<tam; i++) {
    th[i].id = -1;
  }
}
