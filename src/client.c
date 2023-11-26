#include <bignumber.h>

int main(){
    int n;
    printf("Digite um número:\n");
    scanf("%d",&n);
    int tamanho = tamanho_numero(n);
    int* vetor = malloc(tamanho*sizeof(int));
    numero_em_vetor(n, tamanho, vetor);
    
    int n2;
    printf("Digite um segundo número:\n");
    scanf("%d",&n2);
    int tamanho2 = tamanho_numero(n2);
    int* vetor2 = malloc(tamanho2*sizeof(int));
    numero_em_vetor(n2, tamanho2, vetor2);
    
    char operacao;
    printf("Digite a operação:\n");
    getchar();
    scanf("%c", &operacao);

    if (operacao == '+'){
        soma(vetor, tamanho, vetor2, tamanho2);
        resultado(vetor, tamanho, vetor2, tamanho2);
    }
    
    return 0;
}
