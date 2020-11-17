#include <stdio.h>

int main () {
    FILE *ex4;
    double io[3];
    int i;

    printf("Numeros gravados no arquivo:\n");

    ex4 = fopen("reais.bin", "rb");
    if (!ex4) return 1;
    fread(io, sizeof(double), 3, ex4);
    fclose(ex4);
    
    for (i=0; i < 3; i++)
        printf("%g ", io[i]);
    putchar('\n');

    return 0;
}