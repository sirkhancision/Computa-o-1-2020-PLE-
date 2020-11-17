#include <stdio.h>
 
int main() {
    double notaA, notaB;
    scanf("%lf %lf", &notaA, &notaB);
    double MEDIA = (notaA * 3.5 + notaB * 7.5) / 11;
    printf("MEDIA = %.5lf\n", MEDIA);
    return 0;
} 
