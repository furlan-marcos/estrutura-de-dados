#include <stdio.h>
#include <stdlib.h>

struct Node {			
	int data;			
	struct Node *next;	
};

struct Node *head = NULL;

void insertElement (int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
		return;
	}
	
	struct Node *currentNode = head;
	
	if (value < currentNode->data) {
		newNode->next = currentNode;
		head = newNode;
		return;
	}
	
	while (currentNode->next != NULL && value > currentNode->next->data) { 
	currentNode = currentNode->next;
	}

	newNode->next = currentNode->next;
	currentNode->next = newNode;
}

void displayList() {
	struct Node *currentNode = head;
	
	printf("Lista: ");
	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}

int main() {
	insertElement(5);
	insertElement(10);
	insertElement(7);
	insertElement(3);
	displayList();
	
	return 0;
}
