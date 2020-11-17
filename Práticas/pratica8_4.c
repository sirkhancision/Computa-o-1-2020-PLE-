#include <stdio.h>
#include <math.h>

typedef struct {
	float x, y;
} PONTO;

typedef struct {
	float raio;
	PONTO centro;
} CIRCUNFERENCIA;

float dist_pontos (float xa, float ya, float xb, float yb) {
	return sqrt(pow((xb - xa), 2) + pow((yb - ya), 2));
}

int main () {
	PONTO p1;
	CIRCUNFERENCIA c1;
	float dist_p1_c1;

	printf("Entre com o valor da coordenada x e y de um ponto, respectivamente, "
		"separados por espaco\n");
	scanf("%f %f", &p1.x, &p1.y);

	printf("Entre com o raio de uma circunferencia\n");
	scanf("%f", &c1.raio);
	printf("Agora, entre com os pontos x e y que correspondem ao centro dessa circunferencia\n");
	scanf("%f %f", &c1.centro.x, &c1.centro.y);

	dist_p1_c1 = dist_pontos(p1.x, p1.y, c1.centro.x, c1.centro.y);

	if (dist_p1_c1 < c1.raio) printf("O ponto esta contido na circunferencia\n");
	else printf("O ponto nao esta contido na circunferencia\n");
	
	return 0;
}