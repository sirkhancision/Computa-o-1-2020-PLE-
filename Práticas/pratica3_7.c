#include <stdio.h>
 
int main() {
    int NUMBER, horas_trabalho;
    float valor_hora;
    scanf("%d %d %f", &NUMBER, &horas_trabalho,
        &valor_hora);
    float SALARY = horas_trabalho * valor_hora;
    printf("NUMBER = %d\n"
    "SALARY = U$ %.2f\n", NUMBER, SALARY);
    return 0;
} 
