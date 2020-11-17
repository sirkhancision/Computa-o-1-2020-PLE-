#include <stdio.h>
#include <stdlib.h>

int main () {
    double num;
    FILE *ex1;

    if((ex1 = fopen("ex1.txt", "w")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    printf("Entre com um numero real:\n");

    scanf("%lf", &num);
    fprintf(ex1, "%f", num);
    fclose(ex1);

    printf("Escrita bem-sucedida\n");

    return 0;
}