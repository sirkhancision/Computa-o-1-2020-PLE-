#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double nota1, nota2;
} NOTAS;

int main () {
    int i;
    char nome[35];
    NOTAS n[10];
    FILE *ex3;

    printf("Entre com o nome do arquivo a ser escrito (sem extensao)\n");
    fgets(nome, 30, stdin);
    nome[strlen(nome)-1] = '\0';
    strcat(nome, ".txt");

    if ((ex3 = fopen(nome, "a")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (i=0; i < 10; i++) {
        printf("Entre com as notas do aluno %d:\n", i+1);
        scanf("%lf %lf", &n[i].nota1, &n[i].nota2);
    }

    for (i=0; i < 10; i++)
        fprintf(ex3, "%.1f %.1f\n", n[i].nota1, n[i].nota2);

    printf("Escrita bem-sucedida\n");

    return 0;
}