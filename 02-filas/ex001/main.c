#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Estrutura da fila
typedef struct {
    int elementos[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
} Fila;

// Função para criar uma nova fila vazia
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
    return fila;
}

int main() {
    // Exemplo de uso da função criarFila()
    Fila* minhaFila = criarFila();

    // Resto do programa...
    return 0;
}
