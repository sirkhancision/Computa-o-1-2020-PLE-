#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int i = 0;
    FILE *pa, *pa2;
    char *nome = "pratica10_10_texto2.txt";
    char nome2[35], *texto;
    char c;

    /* Programa original */

    pa = fopen(nome, "r");
    if (!pa)
    {
        printf("Erro ao abrir %s\n", nome);
        return 1;
    }
    
    while (1)
    {
        c = fgetc(pa);
        if (c == EOF) break;
        putchar(c);
        /* Programa do exerc. 10 */
        ++i;
    }

    texto = (char *) malloc(i * sizeof(char));
    rewind(pa);
    fgets(texto, (i-1), pa);
    fclose(pa);

    printf("Agora, entre com o nome do arquivo de copia (sem extensao):\n");
    fgets(nome2, 30, stdin);
    nome2[strlen(nome2)-1] = '\0';
    strcat(nome2, ".txt");

    if ((pa2 = fopen(nome2, "w")) == NULL) {
        printf("Erro ao abrir %s\n", nome2);
        return 1;
    }

    fputs(texto, pa2);
    fclose(pa2);
    printf("Copia feita com sucesso\n");

    return 0;
}
