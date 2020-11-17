#include <stdio.h>

int x, y;

int prod (int x) {
	if (y != 1) {
		--y;
		return x + prod(x);
	}
	else return x;
}

int main () {
	int result;
	printf("Insira os valores dos inteiros x e y, respectivamente\n");
	scanf("%d %d", &x, &y);
	result = prod(x);
	printf("Produto: %d\n", result);

	return 0;
}