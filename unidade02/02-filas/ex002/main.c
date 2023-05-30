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

// Função para enfileirar um elemento na fila
void enfileirar(Fila* fila, int elemento) {
    if (fila->tamanho == MAX_SIZE) {
        printf("Erro: Fila cheia.\n");
        return;
    }
    fila->fim = (fila->fim + 1) % MAX_SIZE;
    fila->elementos[fila->fim] = elemento;
    fila->tamanho++;
}

int main() {
    // Exemplo de uso da função criarFila()
    Fila* minhaFila = criarFila();
    
    // Exemplo de uso da função enfileirar()
    enfileirar(minhaFila, 10);

    // Resto do programa...
    return 0;
}
