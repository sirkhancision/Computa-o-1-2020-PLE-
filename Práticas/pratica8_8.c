#define TAM 50

#include <stdio.h>

typedef struct _TEMPO {
	int hora, minuto, segundo;
} TEMPO;

int main () {
	int i, tmp;
	TEMPO t[TAM];

	for (i=0; i < TAM; i++) {
		printf("Entre com o tempo gasto na tarefa numero %d\nExemplo: 00:00:00 (hora:minuto:segundo)\n", i+1);
		scanf("%d:%d:%d", &t[i].hora, &t[i].minuto, &t[i].segundo);
		if (t[i].hora < 0 || t[i].minuto < 0 || t[i].segundo < 0) return 1;
		if (t[i].minuto >= 60 || t[i].segundo >= 60) return 2;		
	}
	
	for (i=0; i < TAM-1; i++) {
		if (t[i].segundo > t[i+1].segundo) {
			tmp = t[i+1].segundo;
			t[i+1].segundo = t[i].segundo;
			t[i].segundo = tmp;
		}

		if (t[i].minuto > t[i+1].minuto) {
			tmp = t[i+1].minuto;
			t[i+1].minuto = t[i].minuto;
			t[i].minuto = tmp;
		}

		if (t[i].hora > t[i+1].hora) {
			tmp = t[i+1].hora;
			t[i+1].hora = t[i].hora;
			t[i].hora = tmp;
		}
	}

	for (i=0; i < TAM; i++) {
		printf("Tempo %d: %02d:%02d:%02d\n", i+1, t[i].hora, t[i].minuto, t[i].segundo);
	}

	return 0;
}