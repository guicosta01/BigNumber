#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    
    int size_x = tamanho(x);
    int size_y = tamanho(y);
    
    // Convertendo int para string
    char* numberString = malloc(size_x*sizeof(int));
    char* numberString2 = malloc(size_y*sizeof(int));

    sprintf(numberString, "%d", x);
    sprintf(numberString2, "%d", y);

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

