#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *items;
	int top;
} Stack;

void initialize (Stack *ptrStack) {
	ptrStack->top = -1;
	ptrStack->items = NULL;
}

int main () {
	Stack myStack;
	initialize(&myStack);
	
	printf("Pilha inicializada com sucesso!\n");
	
	free(myStack.items);
}
