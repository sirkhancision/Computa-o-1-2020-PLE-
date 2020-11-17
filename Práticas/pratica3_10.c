#include <stdio.h>
 
int main() {
    unsigned int tempo_segundos;
    scanf("%d", &tempo_segundos);
    unsigned int saida_hor, saida_min, saida_seg;
    saida_hor = tempo_segundos / 3600;
    saida_min = (tempo_segundos - saida_hor * 3600) / 60;
    saida_seg = (tempo_segundos - (saida_hor * 3600 + saida_min * 60));
    printf("%u:%u:%u\n", saida_hor, saida_min, saida_seg);
    return 0;
} 
