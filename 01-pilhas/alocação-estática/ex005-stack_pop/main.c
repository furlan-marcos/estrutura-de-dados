#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

int pop(Stack* myStack) {
    if (myStack->top == -1) {
        printf("Erro: a pilha está vazia.\n"); // Verifica se a pilha está vazia antes de remover um elemento
        return -1;
    }
    int item = myStack->items[myStack->top]; // Armazena o elemento do topo que será removido
    myStack->top--; // Decrementa o topo para remover o elemento
    
    printf("Elemento %d removido do topo da pilha.\n", item);
    return item;
}

int main() {
    Stack myStack;
    myStack.top = 0;
    myStack.items[0] = 10; // Inicializa a pilha com um elemento
    
    int poppedItem = pop(&myStack);
    
    return 0;
}

