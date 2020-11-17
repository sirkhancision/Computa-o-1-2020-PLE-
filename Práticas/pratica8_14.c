#include <stdio.h>

typedef struct _FRACAO {
	int numerador, denominador;
} FRACAO;

FRACAO simp (FRACAO som);
FRACAO soma (FRACAO a, FRACAO b);
FRACAO subtracao (FRACAO a, FRACAO b);
FRACAO multiplicacao (FRACAO a, FRACAO b);
FRACAO divisao (FRACAO a, FRACAO b);

int main () {
	FRACAO f1, f2, som, sub, prod, div;

	printf("Insira a primeira fracao\nExemplo: x/y\n");
	scanf("%d/%d", &f1.numerador, &f1.denominador);
	if (f1.denominador == 0) {
		printf("Impossivel realizar divisao por 0\n");
		return 1;
	}

	printf("Insira a segunda fracao\n");
	scanf("%d/%d", &f2.numerador, &f2.denominador);
	if (f2.denominador == 0) {
		printf("Impossivel realizar divisao por 0\n");
		return 1;
	}

	som = soma(f1, f2);
	sub = subtracao(f1, f2);
	prod = multiplicacao(f1, f2);
	div = divisao(f1, f2);

	som = simp(som);
	sub = simp(sub);
	prod = simp(prod);
	div = simp(div);

	printf("Soma das fracoes: %d/%d\n", som.numerador, som.denominador);
	printf("Subtracao das fracoes: %d/%d\n", sub.numerador, sub.denominador);
	printf("Produto das fracoes: %d/%d\n", prod.numerador, prod.denominador);
	printf("Divisao das fracoes: %d/%d\n", div.numerador, div.denominador);

	return 0;
}

/* Simplificao de fracoes */

FRACAO simp (FRACAO som) {
	int i;

	for (i=2; i <= 9; i++) {
		if ((som.numerador % i == 0) && (som.denominador % i == 0)) {
			for (; ((som.numerador % i == 0) && (som.denominador % i == 0)); ) {
				som.numerador /= i;
				som.denominador /= i;
			}
		}
	}
	return som;
}

FRACAO soma (FRACAO a, FRACAO b) {
	FRACAO result;
	if (a.denominador != b.denominador) {
		result.numerador = (a.numerador * b.denominador) + (b.numerador * a.denominador);
		result.denominador = a.denominador * b.denominador;
	}
	else {
		result.numerador = a.numerador + b.numerador;
		result.denominador = a.denominador;
	}

	return result;
}

FRACAO subtracao (FRACAO a, FRACAO b) {
	FRACAO result;
	if (a.denominador != b.denominador) {
		result.numerador = (a.numerador * b.denominador) - (b.numerador * a.denominador);
		result.denominador = a.denominador * b.denominador;
	}
	else {
		result.numerador = a.numerador - b.numerador;
		result.denominador = a.denominador;
	}

	return result;
}

FRACAO multiplicacao (FRACAO a, FRACAO b) {
	FRACAO result;
	result.numerador = a.numerador * b.numerador;
	result.denominador = a.denominador * b.denominador;
	if ((result.numerador < 0) && (result.denominador < 0)) {
		result.numerador *= -1;
		result.denominador *= -1;
	}
	
	return result;
}

FRACAO divisao (FRACAO a, FRACAO b) {
	FRACAO result;
	result.numerador = a.numerador * b.denominador;
	result.denominador = b.numerador * a.denominador;

	return result;
}