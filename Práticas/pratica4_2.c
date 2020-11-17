#define DF_BRA 61
#define BA_SAL 71
#define SP_SAO 11
#define RJ_RIO 21
#define MG_JUZ 32
#define SP_CAM 19
#define ES_VIT 27
#define MG_BEL 31

#include <stdio.h>

int main(){
    int ddd;
    scanf("%d", &ddd);

    if (ddd == DF_BRA){
        printf("Brasilia\n");
    }
    else if (ddd == BA_SAL){
        printf("Salvador\n");
    }
    else if (ddd == SP_SAO){
        printf("Sao Paulo\n");
    }
    else if (ddd == RJ_RIO){
        printf("Rio de Janeiro\n");
    }
    else if (ddd == MG_JUZ){
        printf("Juiz de Fora\n");
    }
    else if (ddd == SP_CAM){
        printf("Campinas\n");
    }
    else if (ddd == ES_VIT){
        printf("Vitoria\n");
    }
    else if (ddd == MG_BEL){
        printf("Belo Horizonte\n");
    }
    else{
        printf("DDD nao cadastrado\n");
    }
    
    return 0;
}