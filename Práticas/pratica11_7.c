/* Como nenhum arquivo ex1.bin foi dado, criei o meu próprio */

#include <stdio.h>

int main () {
    FILE *ex1;
    long tam;

    ex1 = fopen("ex1.bin", "rb");
    if (!ex1) return 1;

    fseek(ex1, 0, SEEK_END);
    tam = ftell(ex1);
    fclose(ex1);
    printf("Tamanho de ex1.bin: %ld bytes\n", tam);

    return 0;
}