#include <stdio.h>

int main(){
    int numero, fatorial = 1;
    scanf("%d", &numero);

    for (numero; numero > 1; numero--)
     fatorial = fatorial * numero;
    
    printf("%d", fatorial);

    return 0;
}