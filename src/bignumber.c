#include <bignumber.h>

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
