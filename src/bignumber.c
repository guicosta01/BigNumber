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


    return bignumber;
}

void imprimir_bignumber(Bignumber *bignumber) {
    if (bignumber->sinal == 1){
        printf("-");
    }
    int ultimo_dig = bignumber->tam - 1;

    while(bignumber->v_numbers[ultimo_dig]==0){
        ultimo_dig--;
    }
    for (int i = ultimo_dig; i >= 0; --i) {
        printf("%d", bignumber->v_numbers[i]);
    }
    printf("\n");
}

void free_bignumber(Bignumber *bignumber){
    free(bignumber->v_numbers);
}


int* aumentarTamanho(int *vetor, int tamanhoAtual, int novoTamanho) {
    int *novoVetor = (int *)malloc(sizeof(int) * novoTamanho);

    if (novoVetor == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }
    for (int i = 0; i < tamanhoAtual; i++) {
        novoVetor[i] = vetor[i];
    }

    free(vetor); 
    return novoVetor; 
}

//soma alterar um dos bignumbers -> A
void soma(Bignumber *a, Bignumber *b){
    //a menor 
    if(a->tam <= b->tam){

        a->v_numbers = realloc(a->v_numbers, (b->tam)* sizeof(int));
        for(int j=a->tam; j<b->tam; j++){
            a->v_numbers[j] = 0;
        }
        a->tam = b->tam;

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

            if((i==(a->tam-1)) && (a->v_numbers[i] + b->v_numbers[i] + resto>=10)){
                b->v_numbers = realloc(b->v_numbers, (b->tam+1)* sizeof(int));
                b->tam++;
            }

            b->v_numbers[i] = soma;

        }
        b->v_numbers[a->tam] = b->v_numbers[a->tam] + resto;
        
        imprimir_bignumber(b);
    }

    //b menor 
    else{
        b->v_numbers = realloc(b->v_numbers, (a->tam)* sizeof(int));
        for(int j=b->tam; j<a->tam; j++){
            b->v_numbers[j] = 0;
        }
        b->tam = a->tam;
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

            if((i==(b->tam-1)) && (a->v_numbers[i] + b->v_numbers[i] + resto>=10)){
                a->v_numbers = realloc(a->v_numbers, (a->tam+1)* sizeof(int));
                a->tam++;
            }            
            
            a->v_numbers[i] = soma;
            }
            
        a->v_numbers[b->tam] = a->v_numbers[b->tam] + resto;
        imprimir_bignumber(a);  
    }      
}
    

void subtracao(Bignumber *a, Bignumber *b, int maior, char op){
    //a menor
    if(a->tam < b->tam){

        a->v_numbers = realloc(a->v_numbers, (b->tam)* sizeof(int));
        for(int j=a->tam; j<b->tam; j++){
            a->v_numbers[j] = 0;
        }
        a->tam = b->tam;


        for(int i=0; i<b->tam; i++){
            if(b->v_numbers[i] >= a->v_numbers[i]){
                if(i <= a->tam){
                    b->v_numbers[i] = b->v_numbers[i] - a->v_numbers[i];
                }
            } else {
                if(i <= a->tam){
                    b->v_numbers[i+1] = b->v_numbers[i+1] - 1;
                    b->v_numbers[i] = 10 + b->v_numbers[i] - a->v_numbers[i];
                }
            }
        }
        if(op == '+'){
            if(b->sinal == 0){
                b->sinal = 0;
            }
            else{
                b->sinal = 1;
            }
        }
        if(op == '-'){
            if(b->sinal == 0){
                b->sinal = 1;
            }
            else{
                b->sinal = 0;
            }                
        }
        imprimir_bignumber(b);
    }
    //b menor
    else if(b->tam < a->tam){

        b->v_numbers = realloc(b->v_numbers, (a->tam)* sizeof(int));
        for(int j=b->tam; j<a->tam; j++){
            b->v_numbers[j] = 0;
        }
        b->tam = a->tam;

        for(int i=0; i<a->tam; i++){
            if(a->v_numbers[i] >= b->v_numbers[i]){
                if(i <= b->tam){
                    a->v_numbers[i] = a->v_numbers[i] - b->v_numbers[i];
                }
            } else {
                if(i <= b->tam){
                    a->v_numbers[i+1] = a->v_numbers[i+1] - 1;
                    a->v_numbers[i] = 10 + a->v_numbers[i] - b->v_numbers[i];
                }    
            }
        }        
        imprimir_bignumber(a);        
    }
    //mesmo tamanho
    else{
        //se b é maior
        if (maior == 2){
            for(int i=0; i<b->tam; i++){
                if(b->v_numbers[i] >= a->v_numbers[i]){
                    if(i <= a->tam){
                        b->v_numbers[i] = b->v_numbers[i] - a->v_numbers[i];
                    }
                } else {
                    if(i <= a->tam){
                        b->v_numbers[i+1] = b->v_numbers[i+1] - 1;
                        b->v_numbers[i] = 10 + b->v_numbers[i] - a->v_numbers[i];
                    }
                }
            }

            //tratamento de sinal
            if(op == '+'){
                if(b->sinal == 0){
                    b->sinal = 0;
                }
                else{
                    b->sinal = 1;
                }
            }
            if(op == '-'){
                if(b->sinal == 0){
                    b->sinal = 1;
                }
                else{
                    b->sinal = 0;
                }                
            }

            
            imprimir_bignumber(b);
        } else {

            for(int i=0; i<a->tam; i++){
                if(a->v_numbers[i] >= b->v_numbers[i]){
                    if(i <= b->tam){
                        a->v_numbers[i] = a->v_numbers[i] - b->v_numbers[i];
                    }
                } else {
                    if(i <= b->tam){
                        a->v_numbers[i+1] = a->v_numbers[i+1] - 1;                    
                        a->v_numbers[i] = 10 + a->v_numbers[i] - b->v_numbers[i];
                    }
                }
            }
            imprimir_bignumber(a);
        }
    }
}

//func para indicar o maior num em modulo 
int maior_num(Bignumber *a, Bignumber *b){
    for (int i = a->tam-1; i>=0; i--){
        if(a->v_numbers[i] > b->v_numbers[i]){
            return 1;
        }
        else if(b->v_numbers[i] > a->v_numbers[i]){
            return 2;
        }
    }
}