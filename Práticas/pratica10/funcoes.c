/*
 * funcoes.c
 * 
 * Copyright 2016 Adriano Cruz <adriano@nce.ufrj.br>
 * 
 */


#include <stdio.h>
#include <math.h>
#include "funcoes.h"
#include "Defs.h"
#include "Globais.h"

/* Le um valor para gTamanhoTurma */
void leTamanhoTurma() {
    int valid = 0;
    printf("Entre com o tamanho da turma (em quantidade de alunos):\n");
    while (valid == 0) {
    scanf("%d", &gTamanhoTurma);
    if (gTamanhoTurma <= 0 || gTamanhoTurma > MAX) {
        printf("Entre com um tamanho valido (não-nulo, positivo e menor que 100):\n");
        continue;
    }
    else ++valid;
    }
}

void leNotas(TURMA *t) {
    int i;
    for (i=0; i < gTamanhoTurma; i++) {
        printf("Entre com a nota do aluno %d:\n", i+1);
        scanf("%lf", &t->notas[i]);
        while (getchar() != '\n');
    }
}

void imprimeNotas(TURMA t) {
    int i;
    for (i=0; i < gTamanhoTurma; i++)
        printf("Nota do aluno %d: %g\n", i+1, t.notas[i]);
}

/* Calcula a media e armazena na estrutura t */
void calculaMedia(TURMA *t) {
    int i;
    for (i=0; i < gTamanhoTurma; i++)
        t->media += t->notas[i];
    t->media /= gTamanhoTurma;
}

void calculaDesvio(TURMA *t) {
    int i;
    for (i=0; i < gTamanhoTurma; i++) {
        t->desvio += pow((t->notas[i] - t->media), 2);
    }
    t->desvio = sqrt(t->desvio / gTamanhoTurma);
}

/* Calcula o maior nota e armazena na estrutura t */
void calculaMaiorNota(TURMA *t) {
    int i;
    t->maiorNota = t->notas[0];
    for (i=0; i < gTamanhoTurma; i++) {
        if (t->notas[i] > t->maiorNota)
            t->maiorNota = t->notas[i];
    }
}

/* Calcula o menor nota e armazena na estrutura t */
void calculaMenorNota(TURMA *t) {
    int i;
    t->menorNota = t->notas[0];
    for (i=0; i < gTamanhoTurma; i++) {
        if (t->notas[i] < t->maiorNota)
            t->menorNota = t->notas[i];
    }
}

/* Imprime media, desvio padrao, maior e menor nota da turma */
void imprimeDados(TURMA t) {
    printf("Media: %.1f\nDesvio: %.2f\nMaior nota: %g\nMenor nota: %g\n",
        t.media, t.desvio, t.maiorNota, t.menorNota);
}