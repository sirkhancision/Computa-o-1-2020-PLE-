#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, n, *pvetor, vezes=0, *temp;
  float media;

  scanf("%d", &n);

  pvetor = (int *) malloc(n * sizeof(int));
  if (!pvetor) {
    puts("Sem memoria.");
    return 1;
  }

  for (i=0; i<n; i++) {
    scanf("%d", pvetor + i);
  }

  media = 0.0;
  for (i=0; i<n; i++) {
    media += *(pvetor + i);
  }

  /* Exercicio 10 */

  temp = (int *) malloc(n * sizeof(int));
  if (!temp) {
    puts("Sem memoria.");
    return 1;
  }

  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (*(pvetor + j) > *(pvetor + (j+1))) {
        *(temp + j) = *(pvetor + (j+1));
        *(pvetor + (j+1)) = *(pvetor + j);
        *(pvetor + j) = *(temp + j);
      }
    }
  }

  /* Exercicio 9 */

  media /= n;

  printf("Media: %.2f\n", media);
  for (i=0; i<n; i++) {
    if (*(pvetor + i) > media) {
      printf("Maior que a media: %d\n", *(pvetor + i));
      vezes++;
    }
  }
  printf("Vezes que um numero maior que a media apareceu: %d\n", vezes);

  /* Para imprimir o vetor em ordem crescente */

  putchar('\n');
  for (i=0; i < n; i++) printf("Valor na posicao %d: %d\n", i, *(pvetor + i));

  free(pvetor);
  free(temp);

  return 0;
}