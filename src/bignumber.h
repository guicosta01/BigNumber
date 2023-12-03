typedef struct {
    int *v_numbers;
    int tam;
} Bignumber;

Bignumber criar_bignumber(char *number);

void imprimir_bignumber(Bignumber* bigNum);

void free_bignumber(Bignumber *bignumber);

void soma(Bignumber *a, Bignumber *b);