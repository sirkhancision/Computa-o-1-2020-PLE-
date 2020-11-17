#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *ex10;
    int *num, i, tam;

    ex10 = fopen("myfile.bin", "rb");
    if (!ex10) return 1;

    num = (int *) malloc(1*sizeof(int));

    for (i=0; !feof(ex10); i++) {
        fread(&num[i], sizeof(int), 1, ex10);
        num = (int *) realloc(num, (i+2)*sizeof(int));
    }
    fclose(ex10);
    tam = i;

    for (i=0; i < tam-1; i++) /* tam-1 para evitar que leia o caractere \0 */ {
        if (num[i] >= 0 && num[i] <= 25) /* A até Z no código */ {
            printf("%c", (num[i])+65); /* A até Z em ASCII */
        }
        else if (num[i] == 26) /* Valor do espaço no código */
            printf(" ");
        else break;
    }
    putchar('\n');

    return 0;
}