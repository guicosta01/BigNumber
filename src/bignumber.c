#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct{
//     int *v_numbers;
//     int tam;
// } Bignumber;

Bignumber criar_bignumber(char *number){
    Bignumber bignumber;

    int len = strlen(number);
    bignumber.tam = len;
    
    bignumber.v_numbers = malloc(len * sizeof(int));
    if(bignumber.v_numbers == NULL){
        printf("Nao a memoria suficente\n");
        exit (1);
    }

    for (int i = 0; i < bignumber.tam; ++i) {
        bignumber.v_numbers[i] = number[bignumber.tam - i - 1] - '0'; //'0' convert na tabela asc
    }

    return bignumber;
}

void imprimir_bignumber(Bignumber *bignumber) {
    for (int i = bignumber->tam - 1; i >= 0; --i) {
        printf("%d", bignumber->v_numbers[i]);
    }
    printf("\n");
}

void free_bignumber(Bignumber *bignumber){
    free(bignumber->v_numbers);
}


//soma alterar um dos bignumbers -> A
void soma(Bignumber *a, Bignumber *b){
    //a menor 
    if(a->tam <= b->tam){
        int resto = 0;
        for(int i=0; i< a->tam; i++){
            int soma = a->v_numbers[i] + b->v_numbers[i] + resto;

            if(soma>=10){
                resto = soma/10;
                soma = soma%10;
            }
            else{
                resto = 0;
            }
            
            b->v_numbers[i] = soma;
        }
        imprimir_bignumber(b);
    }
    //b menor 
    else{
        int resto = 0;
        for(int i=0; i< b->tam; i++){
            int soma = a->v_numbers[i] + b->v_numbers[i] + resto;
            if(soma>=10){
                resto = soma/10;
                soma = soma%10;
            }
            else{
                resto = 0;
            }
            
            a->v_numbers[i] = soma;
        }
        imprimir_bignumber(a);        
    }
}
