#define NULO '2'
#define FALSE '0'
#define TRUE '1'
#define LIN 40
#define COL 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    short unsigned int sala, ingressos, ing_meia, ing_bra,
                       cart_est[5], soma = 0, ing_fil;
    unsigned int cod_bra, track[400],
    track_lug1[400], track_lug2[400], track_lug3[400];
    int i, j, tmp = 0;
    double valor;
    char cond = NULO, cart_est_str[6], pol_let = 0, ing_pol, 
    mapa1[LIN][COL], mapa2[LIN][COL], mapa3[LIN][COL];

    /* Dar um valor inicial para cada posição das matrizes */
        for (i=0; i < LIN; i++) {
            for (j=0; j < COL; j++) {
                mapa1[i][j] = '0';
                mapa2[i][j] = '0';
                mapa3[i][j] = '0';
            }
        }

    while (1) {
        printf("Seja bem-vindo ao Cinema Mariano Pinheiro\n"
            "Entre com o numero da sala correspondente ao filme que deseja assistir (ou 0 para sair):\n"
            "1 - Star Trek | 2 - Star Wars | 3 - Tron\n");

        /* Escolha de sala */
        while (1) {
            scanf("%hu", &sala);

            if (sala == 0) {
                printf("Adeus!\n");
                return 0;
            }

            else if (sala < 1 || sala > 3) {
                printf("Insira uma sala valida\n");
                continue;
            }

            else break;
        }

        /* Escolha da quantidade de ingressos */
        printf("Entre com a quantidade de ingressos que deseja comprar para esse filme:\n");
        while (1) {
            scanf("%hu", &ingressos);

            if (ingressos > 400 || ingressos <= 0) {
                printf("A sala não comporta esta quantidade, insira uma quantidade valida\n");
                continue;
            }

            else break;
        }

        /* Escolha de quantidade de ingressos de meia-entrada/carteira de estudante */
        printf("Quantos ingressos serao aplicaveis a meia-entrada da carteira de estudante?\n");
        while (1) {
            scanf("%hu", &ing_meia);

            if (ing_meia > ingressos || ing_meia < 0) {
                printf("Insira um numero valido de ingressos\n");
                continue;
            }

            else break;
        }

        /* Validação de carteiras de estudante: meia-entrada */
        if (ing_meia > 0) {
            for (i=0; i < ing_meia; ) {
                printf("Digite o numero da carteira de estudante numero %d:\n", i+1);
                for (j=0; j < 5; j++)
                    scanf("%1hu", &cart_est[j]);
                while (getchar() != '\n');

                for (j=0; j < 5; j++)
                        sprintf(&cart_est_str[j], "%hu", cart_est[j]);

                for (j=0; j < ing_meia; j++)
                    if (atoi(cart_est_str) == track[j] && atoi(cart_est_str) != 0) cond = FALSE;

                for (j=0; j < 5; j++) {
                    if (j <= 3) soma += cart_est[j];
                    else if (soma % 10 == cart_est[4] && cond != FALSE) cond = TRUE;
                }

                if (cond == TRUE) {
                    track[i] = atoi(cart_est_str);
                    ++tmp;
                    i++;
                    cond = NULO;
                }

                else if (cond == FALSE) {
                    printf("Carteira ja validada, digite 0 para cancelar o desconto nesse ingresso, "
                    "ou outro numero para tentar novamente\n");
                    scanf("%c", &cond);
                    while (getchar() != '\n');

                    if (cond == FALSE) i++;                    
                    cond = NULO;
                }

                else {
                    printf("Numero invalido: digite 0 para cancelar o desconto para esse ingresso, "
                        "ou outro numero para tentar novamente\n");
                    scanf("%c", &cond);
                    while (getchar() != '\n');

                    if (cond == FALSE) i++;                   
                    cond = NULO;
                }
            }
            ing_meia = tmp;
            tmp = 0;
        }

        /* Escolha de quantidade de ingressos de com desconto de cliente Bradau */
        printf("Quantos ingressos serao aplicaveis ao desconto de cliente Bradau?\n");
        while (1) {
            scanf("%hu", &ing_bra);

            if (ing_bra > ingressos || ing_bra < 0) {
                printf("Insira um numero valido de ingressos\n");
                continue;
            }

            else break;
        }

        /* Validação dos ingressos de clientes Bradau */
        if (ing_bra > 0) {
            for (i=0; i < ing_bra; ) {
                printf("Digite o codigo do cliente Bradau numero %d:\n", i+1);
                scanf("%u", &cod_bra);
                while (getchar() != '\n');

                for (j=0; j < ing_bra; j++)
                    if (cod_bra == track[j] && cod_bra != 0) cond = FALSE;
                
                if (cod_bra % 237 == 0 && cod_bra % 341 == 0 && cond != FALSE) cond = TRUE;

                if (cond == TRUE) {
                    track[i] = cod_bra;
                    ++tmp;
                    i++;
                    cond = NULO;
                }

                else if (cond == FALSE) {
                    printf("Codigo ja validado, digite 0 para cancelar o desconto nesse ingresso, "
                    "ou outro numero para tentar novamente\n");
                    scanf("%c", &cond);
                    while (getchar() != '\n');
                    if (cond == FALSE) i++;
                    cond = NULO;
                }

                else {
                    printf("Codigo invalido, digite 0 para cancelar o desconto nesse ingresso, "
                    "ou outro numero para tentar novamente\n");
                    scanf("%c", &cond);
                    while (getchar() != '\n');
                    if (cond == FALSE) i++;
                    cond = NULO;
                }
            }
            ing_bra = tmp;
            tmp = 0;
        }

        /* Exibir o mapa da sala de cinema */
        printf("\nMapa da sala de cinema:\n");
        printf("%5c", pol_let+32); /* Espaçar as letras das poltronas */

        /* Imprimir as letras das poltronas */
        for (j=0; j < COL; j++) {
            if (j == 9) printf("%c\n", pol_let+65+j);
            else printf("%c ", pol_let+65+j);
        }

        /* Imprimir as fileiras */
        for (i=0; i < LIN; i++) {
            printf("%2d | ", i+1);
            for (j=0; j < COL; j++) {
                if (sala == 1) printf("%c ", mapa1[i][j]);
                else if (sala == 2) printf("%c ", mapa2[i][j]);
                else if (sala == 3) printf("%c ", mapa3[i][j]);
                if (j == 9) putchar('\n');
            }
        }

        /* Solicitar a escolha dos lugares */
        for (i=0; i < ingressos; ) {
            printf("\nSelecione a poltrona para o ingresso %d/%d\n"
                "Exemplo: 2 E (case sensitive)\n", i+1, ingressos);
            scanf("%2hu %1c", &ing_fil, &ing_pol);
            while (getchar() != '\n');

            for (j=0; j < ingressos; j++) {
                switch (sala) {
                    case 1:
                    if (((ing_fil-65) + ing_pol) == track_lug1[j]) cond = FALSE;
                    break;

                    case 2:
                    if (((ing_fil-65) + ing_pol) == track_lug2[j]) cond = FALSE;
                    break;

                    case 3:
                    if (((ing_fil-65) + ing_pol) == track_lug3[j]) cond = FALSE;
                    break;
                }
            }

            if ((ing_fil >= 1 && ing_fil <= 40) && (ing_pol >= 'A' && ing_pol <= 'J') 
                && cond != FALSE) {
                switch (sala) {
                    case 1:
                    track_lug1[i] = (ing_fil-65) + ing_pol;
                    mapa1[ing_fil-1][ing_pol-65] = 'X';
                    break;

                    case 2:
                    track_lug2[i] = (ing_fil-65) + ing_pol;
                    mapa2[ing_fil-1][ing_pol-65] = 'X';
                    break;

                    case 3:
                    track_lug3[i] = (ing_fil-65) + ing_pol;
                    mapa3[ing_fil-1][ing_pol-65] = 'X';
                    break;
                }
                i++;
            }

            else if (cond == FALSE) {
                printf("Esse lugar ja esta ocupado\n");
                cond = NULO;
            }
            
            else printf("Insira um lugar valido\n");
        }

        /* Exibir o valor total */
        ingressos -= (ing_meia + ing_bra);
        valor = (ingressos*20) + ((ing_meia*20) * (50./100.)) + ((ing_bra*20) * (30./100.));

        printf("O valor total a ser pago eh de: R$ %02.2f\n"
            "Obrigado por comprar no Cinema Mariano Pinheiro!\n\n", valor);
    }

    return 0;
}