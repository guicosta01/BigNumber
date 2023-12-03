#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    char* numberString = "-21";
    char* numberString2 = "10";

    Bignumber bigNum = criar_bignumber(numberString);
    Bignumber bigNum2 = criar_bignumber(numberString2);

    printf("A: \n");
    printf("Sinal: %d\n", bigNum.sinal);
    imprimir_bignumber(&bigNum);
    printf("B: \n");
    printf("Sinal: %d\n", bigNum2.sinal);
    imprimir_bignumber(&bigNum2);

    printf("Soma: \n");
    soma(&bigNum, &bigNum2);
    

    free_bignumber(&bigNum);
    free_bignumber(&bigNum2);

    return 0;
}

