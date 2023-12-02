#include "bignumber.h"
int tamanho_numero(long long int n){
    if (n < 10){
        return 1;
    } else {
        return tamanho_numero(n/10) + 1;
    }
}

void numero_em_vetor(long long int n, int tamanho, int* vetor){
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

int* maior_numero(int vetor[], int tamanho, int vetor2[], int tamanho2){
    if(tamanho>tamanho2){
        return vetor;
    } else if (tamanho<tamanho2) {
        return vetor2;
    } else {
        for (int i=tamanho-1; i>=0; i--){
            if (vetor[i] > vetor2[i]){
                return vetor;
            } else if (vetor[i] < vetor2[i]){
                return vetor2;
            }
        }
    }    
}

void subtracao(int vetor[], int tamanho, int vetor2[], int tamanho2, int maior[]) {
    if (maior == vetor) {
        for (int i = 0; i < tamanho; i++) {
            if (vetor[i] >= vetor2[i]) {
                vetor[i] = vetor[i] - vetor2[i];
            } else {
                vetor[i] = 10 + vetor[i] - vetor2[i];
                vetor[i + 1] -= 1;
            }
        }
    } else {
        for (int i = 0; i < tamanho2; i++) {
            if (vetor2[i] >= vetor[i]) {
                vetor2[i] = vetor2[i] - vetor[i];
            } else {
                vetor2[i] = 10 + vetor2[i] - vetor[i];
                vetor2[i + 1] -= 1;
            }
        }
    }
}

void resultado(int vetor[], int tamanho, int vetor2[], int tamanho2, int maior[], char operacao){
    printf("Resultado: ");
    if(operacao == '+'){
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
    } else if (operacao == '-'){
        if(maior == vetor){
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
                printf("-");
                for(int i = tamanho2; i >= 0; i--){
                    printf("%d", vetor2[i]);
                }
            } else {
                printf("-");
                for(int i = tamanho2-1; i >= 0; i--){
                    printf("%d", vetor2[i]);
                }
            }
        }
    }
}
