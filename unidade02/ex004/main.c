#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack* myStack, int item) {
    if (myStack->top == MAX_SIZE - 1) {
        printf("Erro: a pilha est� cheia.\n"); // Verifica se a pilha est� cheia antes de adicionar um elemento
        return;
    }
    myStack->items[++myStack->top] = item; // Incrementa o topo e adiciona o elemento na posi��o correspondente do array
    
    printf("Elemento %d adicionado no topo da pilha.\n", item);
}

int main() {
    Stack myStack;
    myStack.top = -1; // Inicializa o topo da pilha com -1 para indicar que est� vazia
    
    push(&myStack, 10);
    
    return 0;
}
