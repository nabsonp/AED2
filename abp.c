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
        r = (no *) malloc(sizeof(no));
        r->d = d;
        r->esq = NULL;
        r->dir = NULL;
    }
    return r;
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
