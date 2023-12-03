#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct{
//     int *v_numbers;
//     int tam;
//     int sinal;
// } Bignumber;

char* remove_sinal(char *str) {
    int tam = strlen(str);
    char *modified_str = malloc(tam * sizeof(char));

    if(tam>0){

        for (int i = 0; i < tam-1; i++) {
            modified_str[i] = str[i + 1];
        }
        modified_str[tam - 1] = '\0';      
    }

    return modified_str;

}

Bignumber criar_bignumber(char *number){
    Bignumber bignumber;
    int len = strlen(number);
    char *modified_number;

    if (number[0] == '-') {
        bignumber.sinal = 1; 
        bignumber.tam = len-1;
        modified_number = remove_sinal(number);
    } 

    else {
        bignumber.sinal = 0; 
        bignumber.tam = len;
        modified_number = malloc(len * sizeof(char));
        modified_number = number;
    }
    
    bignumber.v_numbers = malloc(bignumber.tam * sizeof(int));

    if(bignumber.v_numbers == NULL){
        printf("Nao a memoria suficente\n");
        exit (1);
    }

    for (int i = 0; i < bignumber.tam; ++i) {
        bignumber.v_numbers[i] = modified_number[bignumber.tam - i - 1] - '0'; //'0' convert na tabela asc
    }


    free(modified_number);    

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
