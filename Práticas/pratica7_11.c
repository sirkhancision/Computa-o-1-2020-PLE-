#include <stdio.h>

void misterio (char *n);

int main() {
  char nome[41];
  fgets(nome, 41, stdin);

  misterio(nome);

  return 0;
}

/* A função abaixo imprime o sobrenome digitado após o nome, assim como no programa 5.
    Ela checa todo caracter até encontrar um espaço,
      e então pula uma posição para pular o espaço, e imprimir corretamente
        o sobrenome adjacente */

void misterio (char *n) {
  while (*n != ' ') n++;
  n++;
  puts(n);
}