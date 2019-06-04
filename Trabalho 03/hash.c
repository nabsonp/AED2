#include "hash.h"

int primo = 100003;

int h(int id) {
  return id % primo; // Primo para 100K registros
}

int indexarHash(FILE* arq, int tam, int tamTH, hash th[]) {
    aluno a;
    tabelaHash(tamTH, th);
    int colisoes = 0;
    fseek(arq,0,SEEK_SET);
    for (int i=0; fread(&a,sizeof(aluno),1,arq); i++) {
        if (inserirHash(a.id, i, tamTH, th) == -1)
            colisoes++;
    }
    return colisoes;
}

aluno buscaIdHash(FILE *arq, int tamTH, hash th[], int id) {
    int indice = -1, i = id % primo;
    aluno a;
    a.id = -1;
    if (th[i].id != -1) {
      if (id == th[i].id)
        indice = th[i].indice; // Retorna o índice do registro no arquivo
      else {
        // Busca sequencial na área de overflow
        for (i=primo;i<tamTH && th[i].id != -1; i++) {
          if (id == th[i].id) {
            indice = th[i].indice;
            printf("colidiu->");
            break;
          }
        }
      }
      if (indice != -1) {
        fseek(arq,indice*sizeof(aluno),SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
      }
    }
    return a;
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
      if (th[i].id == -1) {
        th[i] = hs;
        return -1;
      }
    }
  }
  return 0; // Código de tabela cheia, impossível inserir
}

void tabelaHash(int tam, hash th[]){
  for (int i=0; i<tam; i++) {
    // Coloca o marcador na tabela de hash vazio
    th[i].id = -1;
  }
}
