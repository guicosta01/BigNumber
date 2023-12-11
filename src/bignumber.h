typedef struct {
    int *v_numbers;
    int tam;
    int sinal; // 1-pos | 0-neg
} Bignumber;

Bignumber criar_bignumber(char *number);

void imprimir_bignumber(Bignumber* bigNum);

void free_bignumber(Bignumber *bignumber);

void soma(Bignumber *a, Bignumber *b);

void subtracao(Bignumber *a, Bignumber *b, int maior);

int maior_num(Bignumber *a, Bignumber *b);

