#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000

int main() {
    char* x = malloc(MAX * sizeof(char));
    char* y = malloc(MAX * sizeof(char));
    char operacao;

    scanf("%s", x);
    getchar();
    scanf("%s", y);
    getchar();
    scanf("%c", &operacao);
    
    Bignumber bigNum = criar_bignumber(x);
    Bignumber bigNum2 = criar_bignumber(y);
    int maior = maior_num(&bigNum, &bigNum2);


    //printf("A: \n");
    //imprimir_bignumber(&bigNum);
    //printf("B: \n");
    //imprimir_bignumber(&bigNum2);

    if(operacao == '+'){
        //printf("Soma: \n");
        soma(&bigNum, &bigNum2);
    } else if(operacao == '-'){
        //printf("Subtracao: \n");
        subtracao(&bigNum, &bigNum2, maior);
        //printf("%d", bigNum2.sinal);
    }

    free_bignumber(&bigNum);
    free_bignumber(&bigNum2);

    return 0;
}
