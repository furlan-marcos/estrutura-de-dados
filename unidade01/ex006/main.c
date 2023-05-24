#include <stdio.h>
#include <stdlib.h>

/*Ponteiros funcao com parametro por referencia
https://youtu.be/MzC5wpz88F8 */

/* Funcao que soma 10 ao valor recebido */
void soma10(int x) {
	x = x + 10;
	printf("Valor de 'x' apos a soma = %d \n", x);
	return;
}

void soma10p(int *x) {
	*x = *x + 10;
	printf("Valor de 'x' apos a soma = %d \n", *x);
	return;
}


int main(void) {
	int numero;
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	printf("O numero digitado foi: %d \n", numero);
	
	soma10(numero);	//chamada da funcao
	printf("Agora o numero vale: %d \n", numero);	
	
	soma10p(&numero); //chamada da funcao com ponteiro como parametro
	printf("Agora o numero vale: %d \n", numero);	
	
	return 0;
}
