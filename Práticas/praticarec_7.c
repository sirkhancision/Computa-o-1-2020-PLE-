#include <stdio.h>
#include <stdlib.h>

int tam;

int maior_num (int n[], int maior, int i) {
	if (i != tam) {
		if ((n[i] > n[i+1]) && (n[i] > maior))
			maior = n[i];
		return maior_num(n, maior, i+1);
	}
	else return maior;
}

int main () {
	int *n, i, maior = 0;
	printf("Insira o tamanho do vetor\n");
	scanf("%d", &tam);
	
	n = (int *) malloc(tam * sizeof(int));
	if (!n) return 1;

	for (i=0; i < tam; i++) {
		printf("Insira o elemento %d do vetor\n", i);
		scanf("%d", &n[i]);
	}

	i = 0;
	maior = maior_num(n, maior, i);
	printf("Maior numero: %d\n", maior);

	return 0;
}