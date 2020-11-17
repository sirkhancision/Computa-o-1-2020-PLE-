#define PI 3.14159

#include <stdio.h>
 
int main() {
    double R;
    scanf("%lf", &R);
    double V = (4./3.) * PI * (R * R * R);
    printf("VOLUME = %.3lf\n", V);
    return 0;
} 
