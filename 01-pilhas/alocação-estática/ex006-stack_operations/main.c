#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* myStack) {
    myStack->top = -1;
}

int isEmpty(Stack* myStack) {
    return myStack->top == -1;
}

int isFull(Stack* myStack) {
    return myStack->top == MAX_SIZE - 1;
}

void push(Stack* myStack, int item) {
    if (isFull(myStack)) {
        printf("Erro: a pilha est� cheia.\n");
        return;
    }
    myStack->items[++myStack->top] = item;
    
    printf("Elemento %d adicionado no topo da pilha.\n", item);
}

int pop(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Erro: a pilha est� vazia.\n");
        return -1;
    }
    int item = myStack->items[myStack->top];
    myStack->top--;
    
    printf("Elemento %d removido do topo da pilha.\n", item);
    return item;
}

int main() {
    Stack myStack;
    initialize(&myStack);
    
    if (isEmpty(&myStack)) {
        printf("A pilha est� vazia.\n");
    } else {
        printf("A pilha n�o est� vazia.\n");
    }
    
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    
    if (isFull(&myStack)) {
        printf("A pilha est� cheia.\n");
    } else {
        printf("A pilha n�o est� cheia.\n");
    }
    
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    
    if (isEmpty(&myStack)) {
        printf("A pilha est� vazia.\n");
    } else {
        printf("A pilha n�o est� vazia.\n");
    }
    
    return 0;
}

