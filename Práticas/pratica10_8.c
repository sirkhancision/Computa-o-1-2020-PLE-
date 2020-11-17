#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *ex8;
    int num, i;

    if ((ex8 = fopen("pratica10_6.txt", "a")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (i=0; i < 10; i++) {
        printf("Entre com o numero %d para vir ao final do arquivo\n", i+1);
        scanf("%d", &num);
        while (getchar() != '\n');
        fprintf(ex8, "%d\n", num);
    }
    fclose(ex8);
    printf("Escrita bem-sucedida\n");

    return 0;
}