#include <stdio.h>

int main() {
  int var;
  int *varPtr;

  var = 7;
  varPtr = &var;

  /* O printf abaixo imprime o endereço de memória da variável var,
    e depois o endereço de memória apontado pelo ponteiro varPtr,
      que são equivalentes, já que essa atribuição foi feita em
        varPtr = &var. */

  printf("O endereco de var e %p\n"
            "O valor de varPtr e %p\n", &var, varPtr);

  /* O printf abaixo imprime o valor armazenado na variável var,
    e depois o valor contido no endereço de memória apontado pelo
      ponteiro varPtr, que são equivalentes, por eles compartilharem
        o mesmo endereço de memória. */

  printf("O valor de var e %d\n"
            "O valor que varPtr aponta e %d\n",
            var, *varPtr);

  /* O printf abaixo imprime primeiro o endereço de memória do elemento
    contido no endereço de memória apontado pelo ponteiro varPtr, e depois
      realiza a mesma operação, denotando a complementabilidade dos dois
        operadores & e *. */

  printf("Mostrando que * e & sao complementares\n"
            "&*varPtr = %p\n"
            "*&varPtr = %p\n",
            &*varPtr, *&varPtr);

  return 0;
}