#include "avl.h"

noAVL* indexarIdAVL(FILE* arq, int tam) {
    aluno a;
    noAVL *arv = criarAVL();
    fseek(arq,0,SEEK_SET);
    for (int i=0; fread(&a,sizeof(aluno),1,arq); i++)
        arv = inserirEmAVL(arv, a.id, i);
    return arv;
}

noAVL* indexarCrAVL(FILE* arq, int tam) {
  aluno a;
  noAVL *arv = criarAVL();
  fseek(arq,0,SEEK_SET);
  for (int i=0; fread(&a,sizeof(aluno),1,arq); i++)
      arv = inserirEmAVL(arv, a.cr, i);
  return arv;
}

aluno buscaIdAVL(FILE *arq, noAVL *indice, int id) {
    noAVL *n = buscaAVL(indice,id);
    aluno a;
    a.id = -1;
    if (n) {
      fseek(arq,0,SEEK_SET);
      fseek(arq,n->indice*sizeof(aluno),SEEK_SET);
      fread(&a,sizeof(aluno),1,arq);
    }
    return a;
}

void carregarArvore(FILE *arq,noAVL *n, int *qtd) {
  if (n) {
    carregarArvore(arq, n->esq, qtd);
    aluno a;
    int d = n->indice*sizeof(aluno) - ftell(arq);
    fseek(arq,d,SEEK_CUR);
    fread(&a,sizeof(aluno),1,arq);
    (*qtd)++;
    carregarArvore(arq, n->dir, qtd);
  }
}

void buscarMaioresAVL(FILE *arq, noAVL *n, float dado, int *qtd) {
  if (n) {
    if (n->d <= dado)
      buscarMaioresAVL(arq,n->dir,dado,qtd);
    else {
      if (n->d > dado) {
        buscarMaioresAVL(arq,n->esq,dado,qtd);
        aluno a;
        int d = n->indice*sizeof(aluno) - ftell(arq);
        fseek(arq,d,SEEK_CUR);
        fread(&a,sizeof(aluno),1,arq);
        (*qtd)++;
        buscarMaioresAVL(arq,n->dir,dado,qtd);
      }
    }
  }
}

void buscarMenoresAVL(FILE *arq, noAVL *n, float dado, int *qtd) {
  if (n) {
    if (n->d >= dado)
      buscarMenoresAVL(arq,n->esq,dado,qtd);
    else {
      if (n->d < dado) {
        buscarMenoresAVL(arq,n->dir,dado,qtd);
        aluno a;
        int d = n->indice*sizeof(aluno) - ftell(arq);
        fseek(arq,d,SEEK_CUR);
        fread(&a,sizeof(aluno),1,arq);
        (*qtd)++;
        buscarMenoresAVL(arq,n->esq,dado,qtd);
      }
    }
  }
}

void buscarMaioresOuIguaisAVL(FILE *arq, noAVL *n, float dado, int *qtd) {
  if (n) {
    if (n->d < dado)
      buscarMaioresOuIguaisAVL(arq,n->dir,dado,qtd);
    else {
      aluno a;
      int d = n->indice*sizeof(aluno) - ftell(arq);
      fseek(arq,d,SEEK_CUR);
      fread(&a,sizeof(aluno),1,arq);
      (*qtd)++;
      buscarMaioresOuIguaisAVL(arq,n->esq,dado,qtd);
      carregarArvore(arq,n->dir, qtd);
    }
  }
}

void buscarMenoresOuIguaisAVL(FILE *arq, noAVL *n, float dado, int *qtd) {
  if (n) {
    if (n->d > dado)
      buscarMenoresOuIguaisAVL(arq,n->esq,dado,qtd);
    else {
      aluno a;
      int d = n->indice*sizeof(aluno) - ftell(arq);
      fseek(arq,d,SEEK_CUR);
      fread(&a,sizeof(aluno),1,arq);
      (*qtd)++;
      buscarMenoresOuIguaisAVL(arq,n->dir,dado,qtd);
      carregarArvore(arq, n->esq, qtd);
    }
  }
}

noAVL* criarAVL() {
  return NULL;
}

noAVL* buscaAVL(noAVL *r, int v) {
  if (r != NULL) {
    if (v < r->d) return buscaAVL(r->esq,v);
    else if (v > r->d) return buscaAVL(r->dir,v);
    else return r;
  } else return NULL;
}

noAVL* dropAVL(noAVL *r) {
  if (r != NULL) {
    r->esq = dropAVL(r->esq);
    r->dir = dropAVL(r->dir);
    free(r);
  }
  return NULL;
}

void caminhamentoPrefixado(noAVL *r){
    if (r != NULL) {
        printf("%f ",r->d);
        caminhamentoInfixado(r->esq);
        caminhamentoInfixado(r->dir);
    }
}

void caminhamentoInfixado(noAVL *r){
    if (r != NULL) {
        caminhamentoInfixado(r->esq);
        printf("%f ",r->d);
        caminhamentoInfixado(r->dir);
    }
}

int alturaAVL(noAVL *r) {
  if (r == NULL) return 0;
  return r->altura;
}

int  fb(noAVL *n) {
    return n == NULL ? 0 : alturaAVL(n->dir) - alturaAVL(n->esq);
}

noAVL* rotacaoSimplesDir(noAVL* n) {
  noAVL *y = n->dir;
  noAVL *T2 = y->esq;
  y->esq = n;
  n->dir = T2;
  n->altura = (alturaAVL(n->esq) > alturaAVL(n->dir) ? alturaAVL(n->esq) : alturaAVL(n->esq)) + 1;
  y->altura = (alturaAVL(y->esq) > alturaAVL(y->dir) ? alturaAVL(y->esq) : alturaAVL(y->esq)) + 1;
  return y;
}

noAVL* rotacaoSimplesEsq(noAVL *y) {
  noAVL *x = y->esq;
  noAVL *T2 = x->dir;
  x->dir = y;
  y->esq = T2;
  x->altura = (alturaAVL(x->esq) > alturaAVL(x->dir) ? alturaAVL(x->esq) : alturaAVL(x->esq)) + 1;
  y->altura = (alturaAVL(y->esq) > alturaAVL(y->dir) ? alturaAVL(y->esq) : alturaAVL(y->esq)) + 1;
  return x;
}

noAVL* rotacaoDuplaDir( noAVL* n ) {
	n->dir = rotacaoSimplesEsq(n->dir);
	return rotacaoSimplesDir(n);

}

noAVL* rotacaoDuplaEsq( noAVL *n ) {
	n->esq = rotacaoSimplesDir(n->esq);
  return rotacaoSimplesEsq(n);
}

noAVL* inserirEmAVL(noAVL *n, int d, int ind){
    if (n != NULL) {
      if (d <= n->d) n->esq = inserirEmAVL(n->esq,d,ind);
      else n->dir = inserirEmAVL(n->dir,d,ind);
      n->altura = 1 + (alturaAVL(n->esq) > alturaAVL(n->dir) ? alturaAVL(n->esq) : alturaAVL(n->dir));
      noAVL *newroot = NULL;
      int f = fb(n);
    	if( f <= -2 ) {
    		if( fb(n->esq) <= -1 ) newroot = rotacaoSimplesEsq(n);
    		else newroot = rotacaoDuplaEsq(n);
    	} else if( f >= 2 ) {
    		if( fb(n->dir) >= 1 ) newroot = rotacaoSimplesDir(n);
    		else {
            newroot = rotacaoDuplaDir(n);}
    	} else {
    		newroot = n;
    	}
      return newroot;
    } else {
        n = (noAVL *) malloc(sizeof(noAVL));
        n->d = d;
        n->indice = ind;
        n->esq = NULL;
        n->dir = NULL;
        n->altura = 1;
        return n;
    }
}

noAVL* converterVetorAVL(noAVL* r, int tam, int vet[]) {
  r = inserirEmAVL(r,vet[0],0);
  for (int i=1; i < tam; i++) {
    r = inserirEmAVL(r,vet[i],i);
  }
  return r;
}
