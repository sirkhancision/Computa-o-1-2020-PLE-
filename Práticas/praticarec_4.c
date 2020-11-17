#include <stdio.h>

int fat (int n) {
	if (n != 1)
		return n * fat(n-1);
	else return n;
}

int main () {
	int n, result;
	printf("Insira um numero inteiro\n");
	scanf("%d", &n);
	result = fat(n);
	printf("Fatorial de %d: %d\n", n, result);

	return 0;
}