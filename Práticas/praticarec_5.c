#define TAM 100

#include <stdio.h>

double *inv (double v[], double tmp[], int i) {
	int fim = TAM/2;
	
	if (i != fim) {
		v[TAM-(i+1)] = tmp[i];
		v[i] = tmp[TAM-(i+1)];
		return inv(v, tmp, i+1);
	}
	else return v;
}

int main () {
	double vetor[TAM], tmp[TAM];
    int i;

    for (i=0; i < TAM; i++) {
        printf("Insira o elemento %d do vetor\n", i);
        scanf("%lf", &vetor[i]);
    }

	for (i=0; i < TAM; i++) tmp[i] = vetor[i];

	i = 0;

	*vetor = *inv(vetor, tmp, i);
    printf("Vetor invertido:\n");

    for (i=0; i < TAM; i++) {
        printf("%f\n", vetor[i]);
	}
	
	return 0;
}