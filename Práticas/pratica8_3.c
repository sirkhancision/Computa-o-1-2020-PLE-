#include <stdio.h>
#include <math.h>

typedef struct {
	float x, y;
} PONTO;

int main () {
	PONTO p1;

	printf("Entre com o valor da coordenada x e y de um ponto, respectivamente, "
		"separados por espaco\n");
	scanf("%f %f", &p1.x, &p1.y);

	printf("Distancia entre os pontos (%f, %f): %f\n", p1.x, p1.y, fabs(p1.x - p1.y));
	
	return 0;
}