/* Jorge Henrique Santiago Moreira Junior | DRE 120063312 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Questão 1 */

typedef struct {
    char poltrona[2];
    float valor;
} INGRESSO;

void eticket (short unsigned int sala, INGRESSO ing) {
    unsigned int cod_ing, ascii;
    char *cod_str; /* String contendo o código do ingresso */
    FILE *ticket;

    ascii = ing.poltrona[1];

    cod_ing = (sala * atoi(ing.poltrona[0]) * ascii * 7309) / ing.valor;
    cod_str = (char *) malloc(cod_ing * sizeof(char) + 4);
    sprintf(cod_str, "%d", cod_ing);
    strcat(".etk", cod_str);

    ticket = fopen(cod_str, "w");
    if (!ticket) exit(1);

    if (ing.valor == 20.)
        fprintf(ticket, "Sala %d\n%s\nR$%.2f\nInteira\n%u\n", sala, ing.poltrona, ing.valor, cod_ing);
    else if (ing.valor == (20.) * (50./100.))
        fprintf(ticket, "Sala %d\n%s\nR$%.2f\nMeia\n%u\n", sala, ing.poltrona, ing.valor, cod_ing);
    else if (ing.valor == (20.) * (30./100.))
        fprintf(ticket, "Sala %d\n%s\nR$%.2f\nBradau\n%u\n", sala, ing.poltrona, ing.valor, cod_ing);
    
    fclose(ticket);
}

/* Questão 2 */

void ler_ticket (FILE *arq) {
    char poltrona[2], lixo;
    unsigned int cod_ing;
    float valor;

    fscanf(arq, "%s %s %f %s %u", &lixo, &poltrona, &valor, &lixo, &cod_ing);

    printf("Poltrona: %s\nCodigo de validacao: %u\nValor pago: %.2f\n", poltrona, cod_ing, valor);
}

/* Questão 3 */

void validacao (short unsigned int sala, unsigned int cod_ing, INGRESSO ing) {
    int i;
    char valid;
    unsigned int ascii;
    unsigned int *track;

    ascii = ing.poltrona[1];
    track = (int *) malloc(sizeof(int));

    if (cod_ing == ((sala * atoi(ing.poltrona[0]) * ascii * 7309) / ing.valor))
        printf("%s %u - valido\n", ing.poltrona, cod_ing);
    
    for (i=0; i < track; i++) {
        if (cod_ing == track[i])
            printf("%s %u - remanejado\n", ing.poltrona, cod_ing);
    }
    
    else if (cod_ing != ((sala * atoi(ing.poltrona[0]) * ascii * 7309) / ing.valor))
        printf("%s %u - invalido\n", ing.poltrona, cod_ing);
}

/* Questão 4 */

void checa_lista (float num, float *lista, int i) {
    /* Considerando que i = 0 */

    if (num == lista[i])
        printf("O numero %g esta presente na lista\n", num);
    else if (i > lista)
        printf("O numero %g nao esta presente na lista\n", num);
    else return checa_lista (num, *lista, i+1);
}