#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double nota1, nota2;
} NOTAS;

int main () {
    int i;
    FILE *ex4;
    NOTAS n[10];
    char nome[35];

    printf("Entre com o nome do arquivo gerado no programa anterior (sem extensao)\n");
    fgets(nome, 30, stdin);
    nome[strlen(nome)-1] = '\0';
    strcat(nome, ".txt");

    /* Abrir o arquivo para leitura */

    if ((ex4 = fopen(nome, "r")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (i=0; i < 10; i++)
        fscanf(ex4, "%lf %lf", &n[i].nota1, &n[i].nota2);
    fclose(ex4);

    /* Abrir o arquivo para escrita */

    if ((ex4 = fopen(nome, "w")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (i=0; i < 10; i++)
        fprintf(ex4, "%.1f %.1f %.2f\n", n[i].nota1, n[i].nota2, (n[i].nota1 + n[i].nota2) / 2);
                                                                    /* Media */
    fclose(ex4);

    printf("Escrita bem-sucedida\n");

    return 0;
}