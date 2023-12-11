# BigNumber

Um arquivo pdf chamado README com no máximo 2 páginas contendo um pequeno re-
latório. Este relatório deve conter o nome de ra de todos os membros do grupo. Além
disso, deve conter:

– Uma explicação de como foi representado o BigNumber.
– Qual a interface pública do seu tipo BigNumber (basta as assinaturas).
– Mencione qualquer algoritmo ou estrutura de dados avançada que tenha sido empre-
gada para melhorar o tempo de execução do seu código. Além disso, diga como/onde
usou.
– Diga, de forma geral, como foi a divisão de trabalho dentro da equipe, i.e., quem fez
o quê?


11201921774 Guilherme Ferreira Costa
11202020632 Henrique Allucci Gonçalves

– Uma explicação de como foi representado o BigNumber.
typedef struct {
    int *v_numbers;
    int tam;
    int sinal; // 1-pos | 0-neg
} Bignumber;

Nosso BigNumber foi representado com uma Struct em C, onde seus parâmetros são um vetor de inteiros(int *v_numbers) que é convertido a partir de uma string 