#include <stdio.h>

int main() {
  int i = 10, j = 20;
  int temp;
  int *p1, *p2;

  p1 = &i;
  p2 = &j;
  temp = *p1;
  *p1 = *p2;

  /* em p2 = &j, estamos associando o endereço de memoria à p2, para que este
    passe a apontar a esse endereço de memória, já em *p2 = temp, estamos
      associando o elemento armazenado no endereço de memória apontado por p2
        ao elemento em temp, que nesse caso é o elemento de i, que está sendo
          apontado por p1. */

  *p2 = temp;

  /* Será impresso a troca dos valores de i e j */

  printf("%d %d\n", i, j);

  return 0;
}