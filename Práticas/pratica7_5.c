#include <stdio.h>

char *acheSobrenome (char nome[]) {
  char *pnome;
  int i = 0;

  while (nome[i] != ' ') {
    i++;
  }
  i++;
  pnome = &nome[i];
  return pnome;
}

/* A função acima irá selecionar os caracteres pertencentes ao sobrenome
 e imprimi-lo na main, e para isso ele seleciona todos os caracteres
  que vierem após o espaço do primeiro nome */

int main() {
  char nomeCompleto[80];
  char *p;

  puts("Entre com o seu nome e um sobrenome.");
  fgets(nomeCompleto, 80, stdin);

  p = acheSobrenome(nomeCompleto);

  puts(p);

  return 0;
}