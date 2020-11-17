#include <stdio.h>

int main () {
    FILE *ex3;
    double io[3];

    printf("Entre com 3 numeros reais\n");
    scanf("%lf %lf %lf", &io[0], &io[1], &io[2]);

    ex3 = fopen("reais.bin", "wb");
    if (!ex3) return 1;
    fwrite(io, sizeof(double), 3, ex3);
    fclose(ex3);

    return 0;
}