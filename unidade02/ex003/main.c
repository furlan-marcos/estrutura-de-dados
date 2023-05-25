#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

int isFull(Stack* myStack) {
    return myStack->top == MAX_SIZE - 1; // Verifica se o topo é igual ao tamanho máximo da pilha menos 1, indicando que está cheia
}

int main() {
    Stack myStack;
    myStack.top = MAX_SIZE -1; // Inicializa o topo da pilha com o valor máximo menos 1 para indicar que está cheia
    
    if (isFull(&myStack)) {
        printf("A pilha está cheia.\n");
    } else {
        printf("A pilha não está cheia.\n");
    }
    
    return 0;
}
