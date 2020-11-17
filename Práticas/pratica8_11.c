#define TAM 5

#include <stdio.h>
#include <string.h>

typedef struct _JOGADOR {
	int pontos;
	char nome[42];
} JOGADOR;

int main () {
	JOGADOR jog[TAM], tmp;
	int i, j;

	for (i=0; i < TAM; i++) {
		printf("Insira o nome do jogador numero %d\n", i+1);
		fgets(jog[i].nome, 41, stdin);
		jog[i].nome[strlen(jog[i].nome)-1] = '\0';
		printf("Agora, insira a quantidade de pontos desse jogador\n");
		scanf("%d", &jog[i].pontos);
		while (getchar() != '\n');
	}

	/* Sort */

	for (i=0; i < TAM-1; i++) {
		for (j=0; j < TAM-1-i; j++) {
			if (jog[j].pontos < jog[j+1].pontos) {
				tmp = jog[j];
				jog[j] = jog[j+1];
				jog[j+1] = tmp;
			}
		}
	}

	for (i=0; i < TAM; i++) {
		printf("Jogador %d - Nome: %s - Pontos: %d\n", i+1, jog[i].nome, jog[i].pontos);
	}

	return 0;
}