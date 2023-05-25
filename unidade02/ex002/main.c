#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

int isEmpty(Stack* myStack) {
    return myStack->top == -1;
}

int main() {
    Stack myStack;
    myStack.top = -1;
    
    if (isEmpty(&myStack)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }
    
    return 0;
}
