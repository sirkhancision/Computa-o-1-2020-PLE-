#include <stdio.h>

void troca (int *a, int *b) {
  int temp;
 
  temp = *a; *a = *b; *b = temp;
}

int main() {
  int x, y;
  int *px, *py;

  px = &x;
  py = &y;

  scanf("%d %d", px, py);
  troca(px, py);
  printf("Troquei ----> %d %d\n", *px, *py);
  return 0;
}