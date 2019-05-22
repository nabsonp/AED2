#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

int inserirAluno(FILE* arq, int id, char nome[50], int cr) {
    aluno a;
    a.id = id;
    strcpy(a.nome,nome);
    a.cr = cr;
    return fwrite(&a,sizeof(aluno),1,arq);
}

noAVL* gerarAlunosID(FILE* arq, int tam) {
    aluno a;
    noAVL *arv = criarAVL();
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<tam; i++) {
        a.id = 2019000 + i;
        a.cr = (rand() % 10);
        strcpy(a.nome,"NOME");
        fwrite(&a,sizeof(aluno),1,arq);
        arv = inserirEmAVL(arv, a.id, i);
    }
    return arv;
}

noAVL* gerarAlunosCR(FILE* arq, int tam) {
    aluno a;
    noAVL *arv = criarAVL();
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<tam; i++) {
        a.id = 2019000 + i;
        a.cr = (rand() % 10);
        strcpy(a.nome,"NOME");
        fwrite(&a,sizeof(aluno),1,arq);
        arv = inserirEmAVL(arv, a.cr, i);
    }
    return arv;
}

aluno pesqIndice(FILE *arq, int i) {
    fseek(arq,0,SEEK_SET);
    fseek(arq,i*sizeof(aluno),SEEK_SET);
    aluno a;
    fread(&a,sizeof(aluno),1,arq);
    return a;
}
