#include <stdio.h>

int *bin (int n, int n_bin[], int i) {
	if (i != 32) {
		n_bin[32-i] = n % 2;
		return bin(n/2, n_bin, i+1);
	}
	else return n_bin;
}

int main () {
	int n, i=1;
	int n_bin[32];
	printf("Insira um numero decimal positivo qualquer\n");
	scanf("%d", &n);
	if (n < 0) return 1;
	*n_bin = *bin(n, n_bin, i);
	printf("O numero %d na base binaria eh: ", n);
	for (i=0; i < 32; i++) printf("%d", n_bin[i]);
	putchar('\n');

	return 0;
}