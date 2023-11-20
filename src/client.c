#include <bignumber.h>

int main(){
    int n;
    scanf("%d",&n);
    int tamanho = tamanho_numero(n);
    int* vetor = malloc(tamanho*sizeof(int));
    numero_em_vetor(n, tamanho, vetor);
    
    return 0;
}
