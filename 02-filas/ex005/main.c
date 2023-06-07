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

// Função para desenfileirar um elemento da fila
int desenfileirar(Fila* fila) {
    if (fila->tamanho == 0) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    int elemento = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_SIZE;
    fila->tamanho--;
    return elemento;
}

// Função para obter o tamanho atual da fila
int tamanhoFila(Fila* fila) {
    return fila->tamanho;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->tamanho == 0);
}

int main() {
    // Exemplo de uso da função criarFila()
    Fila* minhaFila = criarFila();
    
    // Exemplo de uso da função enfileirar()
    enfileirar(minhaFila, 10);
    
    // Exemplo de uso da função desenfileirar()
    int elementoRemovido = desenfileirar(minhaFila);
    printf("Elemento removido: %d\n", elementoRemovido);
    
    // Exemplo de uso da função tamanhoFila()
    int tamanho = tamanhoFila(minhaFila);
    printf("Tamanho da fila: %d\n", tamanho);
    
    // Exemplo de uso da função filaVazia()
    int vazia = filaVazia(minhaFila);
    if (vazia) {
        printf("A fila está vazia.\n");
    } else {
        printf("A fila não está vazia.\n");
    }

    // Resto do programa...
    return 0;
}
