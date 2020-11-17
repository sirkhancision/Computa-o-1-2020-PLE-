/*
 * main.c
 * 
 * Copyright 2016 Adriano Cruz <adriano@nce.ufrj.br>
 * 
 */


#include <stdio.h>
#include "Defs.h"
#include "Globais.h"
#include "funcoes.h"

int main(int argc, char **argv) {
    TURMA t;
    
    leTamanhoTurma();
    leNotas(&t);
    imprimeNotas(t);
    calculaMedia(&t);
    calculaDesvio(&t);
    calculaMaiorNota(&t);
    calculaMenorNota(&t);
    imprimeDados(t);
    
    return 0;
}