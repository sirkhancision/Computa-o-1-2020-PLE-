/*
 * Defs.h
 * 
 * Copyright 2016 Adriano Cruz <adriano@nce.ufrj.br>
 * 
 */

#ifndef DEFS_H
#define DEFS_H

#define MAX 100

typedef struct _TURMA {
    double notas[MAX];
    double media;
    double desvio;
    double maiorNota;
    double menorNota;
} TURMA;

#endif

