#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[80];
    char num[30];
} LISTA;

int main () {
    int i, tam;
    FILE *ex12, *ex12_2;
    LISTA *l;

    if ((ex12 = fopen("pratica10_12.txt", "r")) == NULL) {
        printf("Erro ao abrir pratica10_12.txt\n");
        exit(1);
    }

    l = (LISTA *) malloc(1 * sizeof(LISTA));
    if (!l) exit(1);

    for (i=0; !feof(ex12); i++) {
        /* %[^0-9] = ler todos os caracteres até encontrar um algarismo
        *  %[^\n]*c = ler todos os caracteres até encontrar uma quebra de linha,
        *                                           e descartar o caractere \n */
        fscanf(ex12, "%[^0-9] %[^\n]%*c", ((l+i)->nome), ((l+i)->num));
        if (feof(ex12)) break;
        l = (LISTA *) realloc(l, (i+2) * sizeof(LISTA));
        if (!l) exit(1);
    }
    fclose(ex12);
    tam = i;

    if ((ex12_2 = fopen("pratica10_12(2).txt", "w")) == NULL) {
        printf("Erro ao abrir pratica10_12(2).txt\n");
        exit(1);
    }

    for (i=0; i < tam; i++)
        fprintf(ex12_2, "%s %s\n", ((l+i)->num), ((l+i)->nome));
    
    fclose(ex12_2);

    printf("Escrita bem-sucedida\n");

    return 0;
}