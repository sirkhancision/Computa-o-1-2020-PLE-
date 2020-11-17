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
	CIRCUNFERENCIA c1, c2;
	float dist_c1_c2;
	printf("Insira o raio da primeira circunferencia\n");
	scanf("%f", &c1.raio);
	printf("Insira o ponto x e y da primeira circunferencia, separados por espaco\n");
	scanf("%f %f", &c1.centro.x, &c1.centro.y);

	printf("Insira o raio da segunda circunferencia\n");
	scanf("%f", &c2.raio);
	printf("Insira o ponto x e y da segunda circunferencia\n");
	scanf("%f %f", &c2.centro.x, &c2.centro.y);

	dist_c1_c2 = dist_pontos(c1.centro.x, c1.centro.y, c2.centro.x, c2.centro.y);

	if (dist_c1_c2 == c1.raio + c2.raio) printf("As circunferencias sao tangentes externas\n");		
	if ((dist_c1_c2 < c1.raio + c2.raio) && (dist_c1_c2 > c1.raio - c2.raio)) 
		printf("As circunferencias sao secantes\n");
	if (dist_c1_c2 > c1.raio + c2.raio) printf("As circunferencias sao externas\n");
	if (dist_c1_c2 < c1.raio - c2.raio) printf("As circunferencias sao internas\n");

	return 0;
}