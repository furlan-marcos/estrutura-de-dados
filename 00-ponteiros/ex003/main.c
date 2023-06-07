#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int tam;
	int *vetor;
	int i; 
	
	printf ("Escolha o tamanho do vetor: ");
	scanf("%d", &tam);
	vetor = (int *) malloc(sizeof (int)*tam);
	
	for (i = 0; i < tam; i++) { 
		vetor[i] = pow(2,i);
		printf ("Posicao %d: %d\n", i, vetor[i]);
	}	
	
	system("Pause");
	return(0);
}
