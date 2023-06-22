#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int top;
} Stack;

void initialize(Stack *ptrStack) {
    ptrStack->top = -1;
    ptrStack->items = NULL;
}

int isEmpty(const Stack *ptrStack) {
    return ptrStack->top == -1;
}

void push(Stack *ptrStack, int newItem) {
    ptrStack->top++;
    ptrStack->items[ptrStack->top] = newItem;
    
    printf("Valor %d inserido na pilha.\n", newItem);
}

int main() {
    Stack myStack;
    initialize(&myStack);
    int value = 10;
    
    printf("Pilha inicializada com sucesso!\n");
    
    myStack.items = (int*)malloc(100 * sizeof(int));
    
    push(&myStack, value); 
    
    if (isEmpty(&myStack)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("A pilha não está vazia!\n");
    }
    
    free(myStack.items); 
    
    return 0;
}


