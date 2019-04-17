#include "abp.h"
#include <stdio.h>
#include <stdlib.h>

void criarArvore(no *r) {
    r = NULL;
}

no* inserirEmABP(no *r, int d){
    if (r != NULL) {
        if (d < r->d) r->esq = inserirEmABP(r->esq,d);
        else r->dir = inserirEmABP(r->dir,d);
    } else {
        no *n = (no *) malloc(sizeof(no));
        n->d = d;
        n->esq = NULL;
        n->dir = NULL;
        return n;
    }
}

void caminhamentoPrefixado(no *r){
    if (r != NULL) {
        printf("%d ",r->d);
        caminhamentoPrefixado(r->esq);
        caminhamentoPrefixado(r->dir);
    }
}


{
    if (r != NULL) {
        caminhamentoPrefixado(r->esq);
        printf("%d ",r->d);
        caminhamentoPrefixado(r->dir);
    }
}

void caminhamentoPosfixado(no *r){
    if (r != NULL) {
        caminhamentoPrefixado(r->esq);
        caminhamentoPrefixado(r->dir);
        printf("%d ",r->d);
    }
}
