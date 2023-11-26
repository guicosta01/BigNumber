#include <bignumber.h>
#include <stdio.h>
#include <stdlib.h>

int tamanho_numero(int n){
    if (n < 10){
        return 1;
    } else {
        return tamanho_numero(n/10) + 1;
    }
}

void numero_em_vetor(int n, int tamanho, int* vetor){
    for (int i=0; i<tamanho; i++){
        vetor[i] = n % 10;
        n = n / 10;
    }
}

int soma(int vetor[], int tamanho, int vetor2[], int tamanho2){
    if(tamanho >= tamanho2){
        for(int i=0; i<tamanho; i++){
            int adicao = vetor[i] + vetor2[i];
            if(adicao < 10){
                vetor[i] = adicao;
            } else{
                vetor[i] = adicao - 10;
                vetor[i+1] += 1;
            }
        }
    } else {
        for(int i=0; i<tamanho; i++){
            int adicao = vetor[i] + vetor2[i];
            if(adicao < 10){
                vetor2[i] = adicao;
            } else {
                vetor2[i] = adicao - 10;
                vetor2[i+1] += 1;
            }
        }        
    }
}

void resultado(int vetor[], int tamanho, int vetor2[], int tamanho2){
    printf("Resultado: ");
    if(tamanho >= tamanho2){
        if(vetor[tamanho] != 0){
            for(int i = tamanho; i >= 0; i--){
                printf("%d", vetor[i]);
            }    
        } else {
            for(int i = tamanho-1; i >= 0; i--){
                printf("%d", vetor[i]);
            }
        }
    } else {
        if(vetor2[tamanho2] != 0){
            for(int i = tamanho2; i >= 0; i--){
                printf("%d", vetor2[i]);
            }
        } else {
            for(int i = tamanho2-1; i >= 0; i--){
                printf("%d", vetor2[i]);
            }
        }
    }
}
