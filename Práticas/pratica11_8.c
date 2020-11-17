#include <stdio.h>

typedef struct _JOGADOR {
    char nome[40];
    int recorde;
} JOGADOR;

int main () {
    FILE *pFile;
    JOGADOR recordistas[3];
    int i;

    pFile = fopen("estruturas.bin", "wb");
    if (!pFile) return 1;

    for (i=0; i < 3; i++) {
        printf("Nome Jogador (so um nome!!!)%d: ", i);
        scanf("%s", recordistas[i].nome);
        while (getchar() != '\n');
        printf("Recorde Jogador %d: ", i);
        scanf("%d", &recordistas[i].recorde);
    }
    fwrite(recordistas, sizeof(JOGADOR), 3, pFile);
    fclose(pFile);

    return 0;
}