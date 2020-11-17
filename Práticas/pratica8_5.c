#include <stdio.h>

typedef struct _TEMPO {
	int hora, minuto, segundo;
} TEMPO;

int main () {
	TEMPO t1, t2;
	printf("Entre com o tempo gasto em uma primeira tarefa\nExemplo: 00:00:00 (hora:minuto:segundo)\n");
	scanf("%d:%d:%d", &t1.hora, &t1.minuto, &t1.segundo);
	if (t1.hora < 0 || t1.minuto < 0 || t1.segundo < 0) return 1;
	if (t1.minuto >= 60 || t1.segundo >= 60) return 2;
	printf("Agora, entre com o tempo gasto em uma segunda tarefa\n");
	scanf("%d:%d:%d", &t2.hora, &t2.minuto, &t2.segundo);
	if (t2.hora < 0 || t2.minuto < 0 || t2.segundo < 0) return 1;
	if (t2.minuto >= 60 || t2.segundo >= 60) return 2;

	if ((t1.hora * 3600) + (t1.minuto * 60) + t1.segundo > 
		(t2.hora * 3600) + (t2.minuto * 60) + t2.segundo)
			printf("O primeiro tempo eh o maior:\n%02d:%02d:%02d > %02d:%02d:%02d\n",
				t1.hora, t1.minuto, t1.segundo, t2.hora, t2.minuto, t2.segundo);
	
	if ((t1.hora * 3600) + (t1.minuto * 60) + t1.segundo < 
		(t2.hora * 3600) + (t2.minuto * 60) + t2.segundo)
			printf("O segundo tempo eh o maior:\n%02d:%02d:%02d > %02d:%02d:%02d\n",
				t2.hora, t2.minuto, t2.segundo, t1.hora, t1.minuto, t1.segundo);

	if ((t1.hora * 3600) + (t1.minuto * 60) + t1.segundo == 
		(t2.hora * 3600) + (t2.minuto * 60) + t2.segundo)
			printf("Os dois tempos sao iguais:\n%02d:%02d:%02d = %02d:%02d:%02d\n",
				t1.hora, t1.minuto, t1.segundo, t2.hora, t2.minuto, t2.segundo);
	
	return 0;
}