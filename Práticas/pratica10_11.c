#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char num[30];
} LISTA;

int main () {
    int i, tam;
    FILE *ex11, *ex11_2;
    LISTA *l;

    if ((ex11 = fopen("pratica10_11.txt", "r")) == NULL) {
        printf("Erro ao abrir pratica10_11.txt\n");
        exit(1);
    }

    l = (LISTA *) malloc(1 * sizeof(LISTA));
    if (!l) exit(1);

    for (i=0; !feof(ex11); i++) {
        fscanf(ex11, "%s %s", ((l+i)->nome), ((l+i)->num));
        if (feof(ex11)) break;
        l = (LISTA *) realloc(l, (i+2) * sizeof(LISTA));
        if (!l) exit(1);
    }
    fclose(ex11);
    tam = i;

    if ((ex11_2 = fopen("pratica10_11(2).txt", "w")) == NULL) {
        printf("Erro ao abrir pratica10_11(2).txt\n");
        exit(1);
    }

    for (i=0; i < tam; i++)
        fprintf(ex11_2, "%s %s\n", ((l+i)->num), ((l+i)->nome));
    
    fclose(ex11_2);

    printf("Escrita bem-sucedida\n");

    return 0;
}