#include "aluno.h"

// ARQUIVO
void gerarAlunos(FILE* arq, int tam, int buscas[]) {
    aluno a;
    time_t t;
    srand((unsigned) time(&t));
    int ids[tam],i;
    gerarVetorDesordenadoSemRepeticoes(tam, ids);
    for (i=0; i<10; i++) {
      buscas[i] = -1;
    }
    for (i=10; i < 30; i++) {
      buscas[i] = ids[i*3300];
    }
    for(i=0; i<tam; i++) {
        // printf("Id: %d\n", ids[i]);
        a.id = ids[i];
        a.cr = (rand() % 10);// + (i/2 - i/2.0);
        a.idade = 18 + (rand() % 10);
        strcpy(a.curso,"Ciência da Computação");
        strcpy(a.nome,"Aluno");
        fwrite(&a,sizeof(aluno),1,arq);
    }
}

void mostrarArquivo(FILE* arq) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  while (fread(&a,sizeof(aluno),1,arq)) {
    printf("\nID: %d", a.id);
    printf("\nNome: %s", (a.nome));
    printf("\nCR: %f", a.cr);
    printf("\nCurso: %s", (a.curso));
    printf("\nIdade: %d\n", a.idade);
  }
}

aluno buscaSequencial(FILE *arq, int id) {
  aluno a;
  fseek(arq,0,SEEK_SET);
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.id == id) return a;
  }
  a.id = -1;
  return a;
}

int buscarMaioresArq(FILE *arq, float dado) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  int i = 0;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr > dado) i++;
  }
  return i;
}

int buscarMenoresArq(FILE *arq, float dado) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  int i = 0;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr < dado) i++;
  }
  return i;
}

int buscarMaioresOuIguaisArq(FILE *arq, float dado) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  int i = 0;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr >= dado) i++;
  }
  return i;
}

int buscarMenoresOuIguaisArq(FILE *arq, float dado) {
  fseek(arq,0,SEEK_SET);
  aluno a;
  int i = 0;
  while (fread(&a,sizeof(aluno),1,arq)) {
    if (a.cr <= dado) i++;
  }
  return i;
}
