#include <stdio.h>
#include <stdlib.h>

main() {
	int *ptr;
	printf ("Endereco: %p\n\n", ptr);
	ptr = (int *) malloc(sizeof (int));
	printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
	*ptr = 10;
	printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
	
	int x;
	x = 20;
	ptr = &x;
	printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
	
	ptr = (int *) malloc(sizeof (int));
	printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
	
	system("Pause");
	return(0);
}
