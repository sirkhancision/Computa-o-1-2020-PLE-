#include <stdio.h>

typedef struct {
    char nome[40];
    int recorde;
} JOGADOR;

int main () {
    FILE *pFile;
    JOGADOR recordistas[3];
    int i;

    pFile = fopen("estruturas.bin", "rb");
    if (!pFile) return 1;

    fread(recordistas, sizeof(JOGADOR), 3, pFile);
    fclose(pFile);

    for (i=0; i < 3; i++)
        printf("%s %d\n", recordistas[i].nome, recordistas[i].recorde);

    return 0;
}