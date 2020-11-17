#include <stdio.h>
 
int main() {
    char NOME;
    double salario_fixo, montante;
    scanf("%s %lf %lf", &NOME, &salario_fixo, &montante);
    double TOTAL = salario_fixo + (montante * .15);
    printf("TOTAL = R$ %.2lf\n", TOTAL) ;
    return 0;
} 
