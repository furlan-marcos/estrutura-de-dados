#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 //A constante MAX_SIZE com valor 100 representa o tamanho m�ximo da pilha.

/* definindo uma estrutura chamada Stack (pilha) que cont�m um array 'items' de tamanho MAX_SIZE
para armazenar os elementos da pilha, e um inteiro 'top' para rastrear a posi��o do topo da pilha. */

typedef struct {
    int items[MAX_SIZE];  //Usada para armazenar os elementos da pilha. 
    int top; // Usada para rastrear a posi��o do elemento mais recente adicionado � pilha.
} Stack;

void initialize(Stack* myStack) { //a fun��o recebe o endere�o de mem�ria de uma vari�vel do tipo Stack.
    myStack->top = -1; // Inicializa o topo da pilha com -1 para indicar que est� vazia
}

int main() {
    Stack myStack;
    initialize(&myStack);
    
    printf("Pilha inicializada com sucesso!\n");
    
    return 0;
}

