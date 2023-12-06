typedef struct {
    int *v_numbers;
    int tam;
    int sinal; // 1-pos | 0-neg
} Bignumber;

int tamanho(int number);

Bignumber criar_bignumber(char *number);

void imprimir_bignumber(Bignumber* bigNum);

void free_bignumber(Bignumber *bignumber);

void soma(Bignumber *a, Bignumber *b);
