#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

void criarArvore(no *r) {
    r = NULL;
}

no* inserirAVL(no *raiz, no *n, int d){
    if (n != NULL) {
        if (d < n->d) n->esq = inserirAVL(raiz,n->esq,d);
        else n->dir = inserirAVL(raiz,n->dir,d);
    } else {
        n = (no *) malloc(sizeof(no));
        n->d = d;
        n->esq = NULL;
        n->dir = NULL;
        raiz = balanceiaNo(raiz);
    }
    return n;
}

no* inserirEmAVL(no *r, int d){
    return inserirAVL(r, r, d);
}

void caminhamentoPrefixado(no *r){
    if (r != NULL) {
        printf("%d ",r->d);
        caminhamentoPrefixado(r->esq);
        caminhamentoPrefixado(r->dir);
    }
}

void caminhamentoInfixado(no *r){
    if (r != NULL) {
        caminhamentoInfixado(r->esq);
        printf("%d ",r->d);
        caminhamentoInfixado(r->dir);
    }
}

void caminhamentoPosfixado(no *r){
    if (r != NULL) {
        caminhamentoPosfixado(r->esq);
        caminhamentoPosfixado(r->dir);
        printf("%d ",r->d);
    }
}

int alturaArvore(no* n) {
    if (n) {
        int e = 1 + alturaArvore(n->esq), d = 1 + alturaArvore(n->dir);
        if (e > d) return e;
        else return d;
    } else
        return 0;
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
	if( n->esq ) n->esq  = balanceiaNo(n->esq);
	if( n->dir ) n->dir = balanceiaNo(n->dir);
	int bf = fb(n);
	if( bf <= -2 ) {
		if( fb( n->esq ) <= -1 ) newroot = rotacaoSimplesEsq(n);
		else newroot = rotacaoDuplaEsq(n);
	} else if( bf >= 2 ) {
		if( fb( n->dir ) >= 1 ) newroot = rotacaoSimplesDir(n);
		else newroot = rotacaoDuplaDir(n);
	} else {
		newroot = n;
	}
	return newroot;
}
