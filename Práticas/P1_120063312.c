/* Jorge Henrique Santiago Moreira Junior | DRE 120063312 */

#define FIL 41 /* FIL = Fileiras */
#define P_FIL 11 /* P = Poltronas */

#include <stdio.h>
    int main() {
    /* int poltronas[P_FIL], fileiras[FIL]; */ /* Vetor bidimensional */
    int sala, quant_ing, quant_ing_meia/*, quant_ing_bra, i=0, j=0 */;
    /* unsigned int cart_est_id, cart_est_ver, soma_cart_est, cod_cli_bra;*/
    /* double ing = 20. , ing_meia, ing_bradau ; */
    /* ing_meia = ing * (50./100.);
    ing_bradau = ing * (80./100.); 100% - 30% = 80% */

    printf("Ola, por favor selecione o numero da sala correspondente"
    " ao filme que deseja assistir:\n 1 (Star Trek) - 2 (Star Wars) - 3 (Tron)\n");
    scanf("%d", &sala);

    switch (sala) {
        case 1:
        printf("Insira a quantidade de ingressos que deseja"
        " comprar para este filme (Star Trek)\n");
        scanf("%d", &quant_ing);
        if (quant_ing > 400 || quant_ing <= 0) {
            printf("A quantidade desejada nao esta disponivel\n");
            return 0;
        }

        printf("Insira a quantidade dos ingressos que"
        " serao aplicaveis a meia-entrada\n");
        scanf("%d", &quant_ing_meia);
        if (quant_ing_meia > quant_ing || quant_ing_meia < 0) {
            printf("Quantidade invalida\n");
            return 0;
        }

        /* for (i=0; i < quant_ing_meia; i++){
            printf("Digite o codigo da carteira de estudante"
            " para a meia-entrada numero %d\n"
            "Formato: [4 PRIMEIROS DIGITOS] [ESPACO] [ULTIMO DIGITO]\n", i+1);
            scanf("%u %u", cart_est_id, cart_est_ver);
            if (cart_est_id != 0) {
                for (j=0; j < 4; j++) {
                    soma_cart_est = (cart_est_id % 10);
                    soma_cart_est += (/10)
                }
            }
            
            if (cart_est_id[j] % 10 != cart_est_ver){
                printf("Insira uma carteira valida ou digite 0 para"
                " cancelar o desconto nesse ingresso\n");
            }
        } */
        break;

        case 2:
        printf("Insira a quantidade de ingressos que deseja"
        " comprar para este filme (Star Wars)\n");
        scanf("%d", &quant_ing);
        if (quant_ing > 400 || quant_ing <= 0) {
            printf("A quantidade desejada nao esta disponivel\n");
            return 0;
        }

        printf("Insira a quantidade dos ingressos que"
        " serao aplicaveis a meia-entrada\n");
        scanf("%d", &quant_ing_meia);
        if (quant_ing_meia > quant_ing || quant_ing_meia < 0) {
            printf("Quantidade invalida\n");
            return 0;
        }
        break;

        case 3:
        printf("Insira a quantidade de ingressos que deseja"
        " comprar para este filme (Tron)\n");
        scanf("%d", &quant_ing);
        if (quant_ing > 400 || quant_ing <= 0) {
            printf("A quantidade desejada nao esta disponivel\n");
            return 0;
        }

        printf("Insira a quantidade dos ingressos que"
        " serao aplicaveis a meia-entrada\n");
        scanf("%d", &quant_ing_meia);
        if (quant_ing_meia > quant_ing || quant_ing_meia < 0) {
            printf("Quantidade invalida\n");
            return 0;
        }
        break;

        case 0:
        printf("Tchau!\n");
        return 0;
        break;

        default:
        printf("Insira uma sala valida\n");
    }
    return 0;
}