#include <stdio.h>
#include <stdlib.h>

int main () {
    double num1, num2;
    FILE *ex2;

    if ((ex2 = fopen("ex2.txt", "a")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    printf("Entre com o primeiro numero real:\n");
    scanf("%lf", &num1);

    printf("Entre com o segundo numero real:\n");
    scanf("%lf", &num2);

    fprintf(ex2, "%f %f", num1, num2);
    fclose(ex2);

    printf("Escrita bem-sucedida\n");

    return 0;
}