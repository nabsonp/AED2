#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

no* inserirEmAVL(no *r, int d){
  r = inserirEmABP(r, d);
  if (r != NULL) return balanceiaNo(r);
  else return r;
}

int  fb(no *n) {
    return alturaArvore(n->dir) - alturaArvore(n->esq);
}

no* rotacaoSimplesEsq(no* n) {
 	no *a = n;
	no *b = a->esq;
	a->esq = b->dir;
	b->dir = a;
	return b;
}

no* rotacaoSimplesDir(no *n) {
	no *a = n;
	no *b = a->dir;
	a->dir = b->esq;
	b->esq = a;
	return b;
}

no* rotacaoDuplaEsq( no* n ) {
	no *a = n;
	no *b = a->esq;
	no *c = b->dir;
	a->esq = c->dir;
	b->dir = c->esq;
	c->esq = b;
	c->dir = a;
	return c;
}

no* rotacaoDuplaDir( no *n ) {
	no *a = n;
	no *b = a->dir;
	no *c = b->esq;
	a->dir = c->esq;
	b->esq = c->dir;
	c->dir = b;
	c->esq = a;
	return c;
}

no* balanceiaNo( no *n ) {
  no *newroot = NULL;
  if (n) {
  	if( n->esq ) n->esq  = balanceiaNo(n->esq);
  	if( n->dir ) n->dir = balanceiaNo(n->dir);
  	int bf = fb(n);
  	if( bf <= -2 ) {
  		if( fb( n->esq ) == -1 ) newroot = rotacaoSimplesEsq(n);
  		else newroot = rotacaoDuplaEsq(n);
  	} else if( bf >= 2 ) {
  		if( fb( n->dir ) == 1 ) newroot = rotacaoSimplesDir(n);
  		else newroot = rotacaoDuplaDir(n);
  	} else {
  		newroot = n;
  	}
  }
	return newroot;
}

no* converterVetorAVL(no* r, int tam, int vet[]) {
  r = inserirEmAVL(r,vet[0]);
  for (int i=1; i < tam; i++) {
    r = inserirEmAVL(r,vet[i]);
  }
  return r;
}
