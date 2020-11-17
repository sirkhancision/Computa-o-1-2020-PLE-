#include <stdio.h>

int mdc (int x, int y) {
	int tmp;
	if (x % y != 0) {
		tmp = x;
		x = y;
		y = (tmp % y);
		return mdc(x, y);
	}
	else return y;
}

int main () {
	int x, y, tmp, result;
	printf("Insira os valores dos inteiros x e y, respectivamente\n");
	scanf("%d %d", &x, &y);
	if (y > x) {
		tmp = x;
		x = y;
		y = tmp;
	}
	result = mdc(x, y);
	printf("MDC: %d\n", result);

	return 0;
}