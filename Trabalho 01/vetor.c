#include <stdlib.h>
#include <time.h>

int* getVetorOrdenado(int tam, int vet[]) {
  time_t t;
  srand((unsigned) time(&t));
  vet[0] = rand()%20;
  for (int i=1; i<tam; i++) {
    vet[i] = vet[i-1] + (int) rand()%20;
  }
}

void getVetPesquisa(int tamP, int pesq[], int tamV, int vet[]) {
  int i;
  time_t t;
  srand((unsigned) time(&t));
  for (i=0; i<10; i++) {
    pesq[i] = vet[i*(tamV/10)];
  }
  for (i=10; i<tamP; i++) {
    pesq[i] = rand()%tamV;
  }
}

int* getVetorDesordenado(int tam, int vet[]) {
  time_t t;
  srand((unsigned) time(&t));
  for (int i=1; i<tam; i++) {
    vet[i] = rand()%tam;
  }
}

int buscaSequencialVetor(int tam, int vet[], int valor) {
  for (int i=0; i<tam; i++) {
    if (vet[i] == valor)
      return i;
  }
  return -1;
}

int buscaBinaria(int tam, int vet[], int valor) {
  int in = 0, fim = tam-1, meio;
  while (in <= fim) {
    meio = (in+fim)/2;
    if (valor > vet[meio]) {
      in = meio+1;
    } else {
      if (valor < vet[meio]) {
        fim = meio-1;
      } else {
        return meio;
      }
    }
  }
  return -1;
}

void duplica(int tam, int vet[], int cpy[]) {
  for (int i=0; i< tam; i++)
    cpy[i] = vet[i];
}

void insertionSort(int tam, int vet[]) {
  int pivo, aux;
  int i, j;
  for (i=1; i<tam; i++) {
    pivo = vet[i];
    j = i - 1;
    if (vet[j] > pivo) {
      for (; j>=0 && vet[j] > pivo; j--)
        vet[j+1] = vet[j];
      vet[j+1] = pivo;
    }
  }
}

void bubbleSort(int tam, int vet[]) {
  int k, j, aux;
  tam--;
  for (k=1; k<=tam; k++) {
      for (j=0; j<tam; j++) {
          if (vet[j] > vet[j+1]) {
              aux = vet[j];
              vet[j] = vet[j+1];
              vet[j+1] = aux;
          }
      }
  }
}

void quickInterno(int vet[], int in, int fim) {
  int pivo, aux;
  int i, j;
  if (in < fim) {
    pivo = vet[(in+fim)/2];
    i = in;
    j = fim;
    do {
      for (; vet[i] < pivo; i++);
      for (; vet[j] > pivo; j--);
      if (i <= j) {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        i++;
        j--;
      }
    } while (i <= j);
    quickInterno(vet, in, j);
    quickInterno(vet, i, fim);
  }
}

void quickSort(int tam, int vet[]) {
  quickInterno(vet, 0, tam-1);
}
