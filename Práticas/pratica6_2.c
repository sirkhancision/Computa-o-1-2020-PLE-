#include <stdio.h>

long int fat (long int n);
long int c (long int n, long int p);

int main (void) {
  long int n, p, comb;
  while (1)
  {
    scanf("%ld %ld", &n, &p);
    if (n < p || n == p) break;
    comb = c(n, p);
    if (n >= 13) { /* 13! é maior que o tamanho do long int (2,147,483,647) */
      printf("%ld! excede 32 bits: overflow\n", n);
      continue;
    }
    printf("O valor da combinacao de %ld %ld a %ld vale %ld\n",
      n, p, p, comb);
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

long int c (long int n, long int p) {
    long int comb;

    comb = fat(n) / ( (fat(n-p) ) * fat(p) );

    return comb;
}