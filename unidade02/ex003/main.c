#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

int isFull(Stack* myStack) {
    return myStack->top == MAX_SIZE - 1; // Verifica se o topo � igual ao tamanho m�ximo da pilha menos 1, indicando que est� cheia
}

int main() {
    Stack myStack;
    myStack.top = MAX_SIZE -1; // Inicializa o topo da pilha com o valor m�ximo menos 1 para indicar que est� cheia
    
    if (isFull(&myStack)) {
        printf("A pilha est� cheia.\n");
    } else {
        printf("A pilha n�o est� cheia.\n");
    }
    
    return 0;
}
