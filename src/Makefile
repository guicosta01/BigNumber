# Makefile para compilar um programa

# Compilador a ser usado
CC = gcc

# Opções de compilação
CFLAGS = -std=c99 -Wall -Wextra -Wvla -g

# Nome do seu programa
TARGET = client_bignumber

# Arquivos fonte (.c)
SOURCES = bignumber.c client.c

# Comando para compilar o programa
$(TARGET): $(SOURCES)
    $(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Comando para limpar arquivos temporários
clean:
    rm -f $(TARGET)

