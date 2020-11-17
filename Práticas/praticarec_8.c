#include <stdio.h>
#include <string.h>

short unsigned palin (char pala[], char tmp[], int tam, int i, int res) {	
	int fim = tam/2;
	if (i != fim) {
		pala[tam-(i+1)] = tmp[i];
		pala[i] = tmp[tam-(i+1)];
		if (strcmp(pala, tmp) == 0) res = 1;
		return palin(pala, tmp, tam, i+1, res);
	}
	else return res;
}

int main () {
	char pala[100], tmp[100];
	short unsigned int result;
	int tam, i, res;
	tam = i = res = 0;

	printf("Escreva uma palavra para ser analisada\n");
	fgets(pala, 99, stdin);
	pala[strlen(pala)-1] = '\0';
	strcpy(tmp, pala);
	tam = strlen(pala);

	result = palin(pala, tmp, tam, i, res);

	switch (result) {
		case 0:
		printf("%s nao eh um palindromo\n", tmp);
		break;

		case 1:
		printf("%s eh um palindromo\n", tmp);
		break;
	}

	return 0;
}