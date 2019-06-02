#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* gerarVetorOrdenado(int tam, int vet[]) {
  time_t t;
  srand((unsigned) time(&t));
  vet[0] = rand()%20;
  for (int i=1; i<tam; i++) {
    vet[i] = vet[i-1] + 1 + (int) (i/8000);
  }
}

void gerarVetPesquisa(int tamP, int pesq[], int tamV, int vet[]) {
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

int* gerarVetorDesordenado(int tam, int vet[]) {
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

void shuffleVet(int *array, size_t n){
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int* gerarVetorDesordenadoSemRepeticoes(int tam, int vet[]) {
  gerarVetorOrdenado(tam, vet);
  shuffleVet(vet,tam);
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

void gerarVetorParcialmenteOrdenado(int tam, int vet[]) {
  time_t t;
  srand((unsigned) time(&t));
  int aux = tam*0.2, i = 1;
  vet[0] = rand()%20;
  for (; i<aux; i++) {
    vet[i] =  i + rand()%aux;
  }
  aux = tam*0.4;
  for (; i <tam*0.2; i++){
    vet[i] = rand()%aux;
  }
  aux = tam*0.6;
  for (; i<tam*0.2; i++) {
    vet[i] =  i + rand()%aux;
  }
  aux = tam*0.8;
  for (; i <tam*0.2; i++){
    vet[i] = rand()%aux;
  }
  for (; i<tam; i++) {
    vet[i] =  i + rand()%tam;
  }
}

void percorrerVetor(int tam, int vet[]) {
  for (int i=0; i<tam; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
}
