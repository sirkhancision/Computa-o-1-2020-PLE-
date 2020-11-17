#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
    FILE *ex6_2;

    if ((ex6_2 = fopen("pratica10_6.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    while (!feof(ex6_2)) {
        fscanf(ex6_2, "%d", &num);
        if (feof(ex6_2)) break;
        printf("%d\n", num);
    }
    fclose(ex6_2);

    return 0;
}