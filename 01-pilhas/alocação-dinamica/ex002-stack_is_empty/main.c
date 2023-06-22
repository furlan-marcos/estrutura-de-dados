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

int	isEmpty (const Stack *ptrStack) {
	return ptrStack->top == -1;
}


int main () {
	Stack myStack;
	initialize(&myStack);
	
	printf("Pilha inicializada com sucesso!\n");
	
	if (isEmpty(&myStack)){
		printf("A pilha est� vazia!\n");
	} else {
		printf("A pilha n�o est� vazia!\n");
	}
	
	free(myStack.items);
}
