#include <stdio.h>

typedef struct _FRACAO {
	int numerador, denominador;
} FRACAO;

FRACAO simp (FRACAO som);

int main () {
	FRACAO f1, f2, soma, sub, prod, div;

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

	/* Soma */

	if (f1.denominador != f2.denominador) {
		soma.numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador);
		soma.denominador = f1.denominador * f2.denominador;
	}
	else {
		soma.numerador = f1.numerador + f2.numerador;
		soma.denominador = f1.denominador;
	}

	/* Subtracao */

	if (f1.denominador != f2.denominador) {
		sub.numerador = (f1.numerador * f2.denominador) - (f2.numerador * f1.denominador);
		sub.denominador = f1.denominador * f2.denominador;
	}
	else {
		sub.numerador = f1.numerador - f2.numerador;
		sub.denominador = f1.denominador;
	}

	/* Multiplicacao */

	prod.numerador = f1.numerador * f2.numerador;
	prod.denominador = f1.denominador * f2.denominador;
	if ((prod.numerador < 0) && (prod.denominador < 0)) {
		prod.numerador *= -1;
		prod.denominador *= -1;
	}

	/* Divisao */

	div.numerador = f1.numerador * f2.denominador;
	div.denominador = f2.numerador * f1.denominador;

	soma = simp(soma);
	sub = simp(sub);
	prod = simp(prod);
	div = simp(div);

	printf("Soma das fracoes: %d/%d\n", soma.numerador, soma.denominador);
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