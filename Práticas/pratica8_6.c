#include <stdio.h>

typedef struct _TEMPO {
	int hora, minuto, segundo;
} TEMPO;

TEMPO soma_t (TEMPO t1, TEMPO t2);

int main () {
	TEMPO t1, t2, t3;
	printf("Entre com o tempo gasto em uma primeira tarefa\nExemplo: 00:00:00 (hora:minuto:segundo)\n");
	scanf("%d:%d:%d", &t1.hora, &t1.minuto, &t1.segundo);
	if (t1.hora < 0 || t1.minuto < 0 || t1.segundo < 0) return 1;
	if (t1.minuto >= 60 || t1.segundo >= 60) return 2;
	printf("Agora, entre com o tempo gasto em uma segunda tarefa\n");
	scanf("%d:%d:%d", &t2.hora, &t2.minuto, &t2.segundo);
	if (t2.hora < 0 || t2.minuto < 0 || t2.segundo < 0) return 1;
	if (t2.minuto >= 60 || t2.segundo >= 60) return 2;

	t3 = soma_t(t1, t2);
	printf("Soma entre %02d:%02d:%02d e %02d:%02d:%d:\n%02d:%02d:%02d\n",
		t1.hora, t1.minuto, t1.segundo, t2.hora, t2.minuto, t2.segundo,
			t3.hora, t3.minuto, t3.segundo);
	
	return 0;
}

TEMPO soma_t (TEMPO t1, TEMPO t2) {
	int i;
	TEMPO t3;
	t3.segundo = t1.segundo + t2.segundo;
	t3.minuto = t1.minuto + t2.minuto;
	t3.hora = t1.hora + t2.hora;

	if (t3.segundo >= 60) {
		for (i=0; t3.segundo >= 60; i++) {
			t3.segundo -= 60;
			++t3.minuto;
		}
	}

	if (t3.minuto >= 60) {
		for (i=0; t3.minuto >= 60; i++) {
			t3.minuto -= 60;
			++t3.hora;
		}
	}

	return t3;
}