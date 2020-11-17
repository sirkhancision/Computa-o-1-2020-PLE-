#include <stdio.h>

int mod (int x, int y, int i) {
	int d = x/y;
	if (x != (d * y) + i) {
		++i;
		return mod(x, y, i);
	}
	else return i;
}

int main () {
	int x, y, result;
	int i = 0;
	printf("Insira os valores dos inteiros x e y, respectivamente\n");
	scanf("%d %d", &x, &y);
	result = mod(x, y, i);
	printf("Resto da divisão entre %d e %d: %d\n", x, y, result);

	return 0;
}