#include <bignumber.h>


int main(){
    long long int n;
    printf("Digite um número:\n");
    scanf("%lld",&n);
    int tamanho = tamanho_numero(n);
    int* vetor = malloc(tamanho*sizeof(int));
    numero_em_vetor(n, tamanho, vetor);
    
    long long int n2;
    printf("Digite um segundo número:\n");
    scanf("%lld",&n2);
    int tamanho2 = tamanho_numero(n2);
    int* vetor2 = malloc(tamanho2*sizeof(int));
    numero_em_vetor(n2, tamanho2, vetor2);
    
    char operacao;
    printf("Digite a operação:\n");
    getchar();
    scanf("%c", &operacao);

    int* maior = maior_numero(vetor, tamanho, vetor2, tamanho2);

    if (operacao == '+'){
        soma(vetor, tamanho, vetor2, tamanho2);
    }
    
    if (operacao == '-'){
        subtracao(vetor, tamanho, vetor2, tamanho2, maior);
    }
    
    resultado(vetor, tamanho, vetor2, tamanho2, maior, operacao);

    return 0;
}
