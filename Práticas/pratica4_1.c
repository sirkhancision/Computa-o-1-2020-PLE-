#define COD1 4.
#define COD2 4.5
#define COD3 5.
#define COD4 2.
#define COD5 1.5

#include <stdio.h>

int main(){
    int codigo, quant;
    float total;
    scanf("%d %d", &codigo, &quant);

    if  (codigo == 1){
        total = COD1 * quant;
    }
    else if (codigo == 2){
        total = COD2 * quant;
    }
    else if (codigo == 3){
        total = COD3 * quant;
    }
    else if (codigo == 4){
        total = COD4 * quant;
    }
    else if (codigo == 5){
        total = COD5 * quant;
    }
    
    printf("Total: R$ %.2f\n", total);
    return 0;
}