#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    char operacao;
    scanf("%d", &x);
    scanf("%d", &y);
    getchar();
    scanf("%c", &operacao);
    
    // Convertendo int para string
    char* numberString = malloc(tamanho(x)*sizeof(int));
    char* numberString2 = malloc(tamanho(y)*sizeof(int));

    sprintf(numberString, "%d", x);
    sprintf(numberString2, "%d", y);

    Bignumber bigNum = criar_bignumber(numberString);
    Bignumber bigNum2 = criar_bignumber(numberString2);

    printf("A: \n");
    imprimir_bignumber(&bigNum);
    printf("B: \n");
    imprimir_bignumber(&bigNum2);

    if(operacao == '+'){
        printf("Soma: \n");
        soma(&bigNum, &bigNum2);
    } else if(operacao == '-'){
        printf("Subtracao: \n");
        subtracao(&bigNum, &bigNum2);
    }

    free_bignumber(&bigNum);
    free_bignumber(&bigNum2);

    return 0;
}
