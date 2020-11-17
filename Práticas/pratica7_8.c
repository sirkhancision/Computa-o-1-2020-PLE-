#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned long int i, *p, n=0;
  p = (unsigned long int *) malloc(sizeof(unsigned long int));

  for (i=0; ;i++) {
    if (!p) {
      printf("Maior segmento de memoria armazenado: 0X%X\n"
              "Memoria alocada %lu vezes\n"
                "Tamanho maximo alocado: %lu\n", &p, i, (n*sizeof(unsigned long int)));
      break;
      free(p);
      return 1;
    }
    free(p);
    n += 1048576; /* 1 MB */
    p = (unsigned long int *) malloc(n * sizeof(unsigned long int));
  }
  return 0;
}