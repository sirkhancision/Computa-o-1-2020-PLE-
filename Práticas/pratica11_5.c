#include <stdio.h>

int main () {
    FILE *pFile;
    int respos[3], i, novoValor, pos;

    printf("Entre com a posição (entre 0 e 2) do numero a ser substituido\n");
    scanf("%d", &pos);
    if (pos < 0 || pos > 2) return 1;
    printf("Agora, entre com o numero a entrar nessa posição\n");
    scanf("%d", &novoValor);

    pFile = fopen("myfile.bin", "r+");
    if (!pFile) return 1;

    fread(respos, sizeof(int), 3, pFile);
    for (i=0; i < 3; i++)
        printf("%d ", respos[i]);
    putchar('\n');

    fseek(pFile, pos*sizeof(int), SEEK_SET);

    fwrite(&novoValor, sizeof(int), 1, pFile);
    printf("novo %d\n", novoValor);

    fseek(pFile, 0, SEEK_SET);

    fread(respos, sizeof(int), 3, pFile);
    for (i=0; i <3; i++)
        printf("%d ", respos[i]);
    putchar('\n');
    fclose(pFile);

    return 0;
}