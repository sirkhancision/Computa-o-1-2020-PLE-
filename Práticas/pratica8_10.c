#define TAM 5

#include <stdio.h>
#include <string.h>

typedef struct _JOGADOR {
	int pontos;
	char nome[42];
} JOGADOR;

int main () {
	JOGADOR j[TAM];
	int i;

	for (i=0; i < TAM; i++) {
		printf("Insira o nome do jogador numero %d\n", i+1);
		fgets(j[i].nome, 41, stdin);
		j[i].nome[strlen(j[i].nome)-1] = '\0';
		printf("Agora, insira a quantidade de pontos desse jogador\n");
		scanf("%d", &j[i].pontos);
		while (getchar() != '\n');
	}

	for (i=0; i < TAM; i++) {
		printf("Jogador %d - Nome: %s - Pontos: %d\n", i+1, j[i].nome, j[i].pontos);
	}

	return 0;
}