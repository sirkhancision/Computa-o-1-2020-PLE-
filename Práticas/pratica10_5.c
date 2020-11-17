#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[81];
    double nota;
} ALUNOS;

int main () {
    int i;
    ALUNOS a[10];
    FILE *ex6;

    if ((ex6 = fopen("ex6.txt", "w")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (i=0; i < 10; i++) {
        printf("Nome do aluno %d:\n", i+1);
        fgets(a[i].nome, 80, stdin);
        a[i].nome[strlen(a[i].nome)-1] = '\0';
        printf("Entre com a nota de %s:\n", a[i].nome);
        scanf("%lf", &a[i].nota);
        while (getchar() != '\n');
    }

    for (i=0; i < 10; i++)
        fprintf(ex6, "%s %.1f\n", a[i].nome, a[i].nota);
    fclose(ex6);

    printf("Escrita bem-sucedida\n");

    return 0;
}