#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *ex9;
    char c;

    if ((ex9 = fopen("pratica10_9.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    c = fgetc(ex9);
    while (!feof(ex9)) {
        putchar(c);
        c = fgetc(ex9);
    }

    return 0;
}