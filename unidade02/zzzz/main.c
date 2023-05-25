#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

//inicializa a pilha, definindo top como -1 para indicar que est� vazia.
void initialize(Stack* myStack) { 
    myStack->top = -1;
}

//verifica se a pilha est� vazia, retornando 1 se top for igual a -1.
int isEmpty(Stack* myStack) {
    return myStack->top == -1;
}

//verifica se a pilha est� cheia, retornando 1 se top for igual a MAX_SIZE - 1.
int isFull(Stack* myStack) {
    return myStack->top == MAX_SIZE - 1;
}

//adiciona um elemento no topo da pilha, verificando antes se a pilha est� cheia.
void push(Stack* myStack, int item) {
    if (isFull(myStack)) {
        printf("Erro: a pilha est� cheia.\n");
        return;
    }
    myStack->items[++myStack->top] = item;
}

//remove e retorna o elemento do topo da pilha, verificando antes se a pilha est� vazia.
int pop(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Erro: a pilha est� vazia.\n");
        return -1;
    }
    return myStack->items[myStack->top--];
}

//retorna o elemento do topo da pilha sem remov�-lo, verificando antes se a pilha est� vazia.
int peek(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Erro: a pilha est� vazia.\n");
        return -1;
    }
    return myStack->items[myStack->top];
}

//fun��o principal do programa, onde a pilha � criada e as fun��es s�o testadas.

/*
a pilha � inicializada, elementos s�o adicionados com push, o elemento do 
topo � obtido com peek, um elemento � removido com pop e as verifica��es 
de pilha vazia e cheia s�o feitas usando isEmpty e isFull.
*/

int main() {
    Stack myStack;
    initialize(&myStack);

    printf("Pilha est� vazia? %s\n", isEmpty(&myStack) ? "Sim" : "N�o");

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Pilha est� cheia? %s\n", isFull(&myStack) ? "Sim" : "N�o");

    printf("Elemento do topo: %d\n", peek(&myStack));

    printf("Removendo elemento do topo: %d\n", pop(&myStack));
    printf("Elemento do topo: %d\n", peek(&myStack));

    printf("Pilha est� vazia? %s\n", isEmpty(&myStack) ? "Sim" : "N�o");

    return 0;
}
