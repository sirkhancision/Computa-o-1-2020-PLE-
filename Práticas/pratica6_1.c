#include <stdio.h>

long int fat (long int n);

int main (void) {
  long int numero, fatorial;
  while (1)
  {
    scanf("%ld", &numero);
    fatorial = fat(numero);

    if (numero < 0) break;
    else if (numero > 20) {
      printf("Numero de bits excedido: overflow\n");
      continue;
    }
    printf("O fatorial de %ld vale %ld\n",
      numero, fatorial);
  }
  return 0;
}

long int fat (long int n) {
  int i, temp;
  temp = n;
  for (i=1; i < temp; i++){
    n = n * (temp-i);
  }
  return n;
}