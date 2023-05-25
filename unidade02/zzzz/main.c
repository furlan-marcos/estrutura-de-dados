#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

//inicializa a pilha, definindo top como -1 para indicar que está vazia.
void initialize(Stack* myStack) { 
    myStack->top = -1;
}

//verifica se a pilha está vazia, retornando 1 se top for igual a -1.
int isEmpty(Stack* myStack) {
    return myStack->top == -1;
}

//verifica se a pilha está cheia, retornando 1 se top for igual a MAX_SIZE - 1.
int isFull(Stack* myStack) {
    return myStack->top == MAX_SIZE - 1;
}

//adiciona um elemento no topo da pilha, verificando antes se a pilha está cheia.
void push(Stack* myStack, int item) {
    if (isFull(myStack)) {
        printf("Erro: a pilha está cheia.\n");
        return;
    }
    myStack->items[++myStack->top] = item;
}

//remove e retorna o elemento do topo da pilha, verificando antes se a pilha está vazia.
int pop(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Erro: a pilha está vazia.\n");
        return -1;
    }
    return myStack->items[myStack->top--];
}

//retorna o elemento do topo da pilha sem removê-lo, verificando antes se a pilha está vazia.
int peek(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Erro: a pilha está vazia.\n");
        return -1;
    }
    return myStack->items[myStack->top];
}

//função principal do programa, onde a pilha é criada e as funções são testadas.

/*
a pilha é inicializada, elementos são adicionados com push, o elemento do 
topo é obtido com peek, um elemento é removido com pop e as verificações 
de pilha vazia e cheia são feitas usando isEmpty e isFull.
*/

int main() {
    Stack myStack;
    initialize(&myStack);

    printf("Pilha está vazia? %s\n", isEmpty(&myStack) ? "Sim" : "Não");

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Pilha está cheia? %s\n", isFull(&myStack) ? "Sim" : "Não");

    printf("Elemento do topo: %d\n", peek(&myStack));

    printf("Removendo elemento do topo: %d\n", pop(&myStack));
    printf("Elemento do topo: %d\n", peek(&myStack));

    printf("Pilha está vazia? %s\n", isEmpty(&myStack) ? "Sim" : "Não");

    return 0;
}
