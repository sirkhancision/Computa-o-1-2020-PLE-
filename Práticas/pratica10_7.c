#include <stdio.h>
#include <stdlib.h>

int main () {
    int num, i, tam, fim, *num_v, tmp;
    FILE *ex7;

    if ((ex7 = fopen("pratica10_6.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (i=1; !feof(ex7); i++) {
        fscanf(ex7, "%d", &num);
        if (feof(ex7)) break;
    }

    tam = i;
    num_v = (int *) malloc(tam * sizeof(int));
    if (!num_v) exit(2);

    rewind(ex7);

    for (i=0; !feof(ex7); i++) {
        fscanf(ex7, "%d", &num);
        if (feof(ex7)) break;
        num_v[i] = num;
    }
    fclose(ex7);

    fim = tam / 2;
    for (i=0; i < fim; i++) {
        tmp = num_v[tam-(i+1)];
        num_v[tam-(i+1)] = num_v[i];
        num_v[i] = tmp;
    }

    for (i=1; i < tam; i++) /* i = 1 para que o caracter '\n' seja ignorado */
        printf("%d\n", num_v[i]);

    return 0;
}