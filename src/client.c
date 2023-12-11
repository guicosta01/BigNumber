#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {

    char* x = argv[1];
    char* y = argv[2];
    char operacao = argv[3][0]; // Obtém o primeiro caractere da terceira string

    Bignumber bigNum = criar_bignumber(x);
    Bignumber bigNum2 = criar_bignumber(y);
    int maior = maior_num(&bigNum, &bigNum2);



    //printf("A: \n");
    //imprimir_bignumber(&bigNum);
    //printf("B: \n");
    //imprimir_bignumber(&bigNum2);

    if(operacao == '+'){
        if(bigNum.sinal==1 && bigNum2.sinal==0){
            if((bigNum.tam > bigNum2.tam) || ((bigNum.tam == bigNum2.tam) && maior == 1)){
                subtracao(&bigNum, &bigNum2, maior, operacao);
            }
            else if((bigNum.tam > bigNum2.tam) || ((bigNum.tam == bigNum2.tam) && maior == 2)){
                subtracao(&bigNum, &bigNum2, maior, operacao);
            }
            else{
                subtracao(&bigNum2, &bigNum, maior, operacao);
            }
            
        }
        else if(bigNum.sinal==0 && bigNum2.sinal==1){
            subtracao(&bigNum, &bigNum2, maior, operacao);
        }
        else{
            soma(&bigNum, &bigNum2);
        }
        
    } else if(operacao == '-'){
        if(bigNum.sinal==1 && bigNum2.sinal==0){
            //printf("DEGUB1\n");
            if((bigNum.tam > bigNum2.tam) || ((bigNum.tam == bigNum2.tam) && maior == 1)){
                subtracao(&bigNum2, &bigNum, maior, operacao);
            }
            else if((bigNum.tam < bigNum2.tam) || ((bigNum.tam == bigNum2.tam) && maior == 2)){
                subtracao(&bigNum2, &bigNum, maior, operacao);
            }
            else{
                subtracao(&bigNum, &bigNum2, maior, operacao);
            }
        }
        else if(bigNum.sinal==0 && bigNum2.sinal==1){
            soma(&bigNum, &bigNum2);
        }
        else{
            //printf("DEGUB3\n");
            // - - - tam - maior 1 ou maior2
            if((bigNum.tam > bigNum2.tam) || ((bigNum.tam == bigNum2.tam) && maior == 1)){
                subtracao(&bigNum, &bigNum2, maior, operacao);
            }
            else{
                subtracao(&bigNum, &bigNum2, maior, operacao);
            }
        }            
    }
    else{
        printf("Feature will be implemented\n");
    }

    free_bignumber(&bigNum);
    free_bignumber(&bigNum2);

    return 0;
}
