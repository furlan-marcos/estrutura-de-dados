#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 10

int lista[tamanho];
int ordenado [tamanho];
int opt= -1;
int qtd;

void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);

int main (void){
	srand(time(NULL));
	do {
		system("cls");
		lista_mostrar();
		lista_mostrar_ordenado();
		menu_mostrar();
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				lista_gerar();
			break;
			case 2:
				lista_ler();
			break;
		}
	} while (opt!=0);
	system("pause");
	return(0);
}

void lista_mostrar (void) {
	int i;
	printf("[ ");
	for (i = 0; i < tamanho; i++){
		printf("%d ", lista[i]);
	}
	printf(" ]\n\n");
}

void menu_mostrar (void) {
	printf("1 - Gerar lista aleatóriamente\n");
	printf("2 - Gerar lista manualmente\n");
	printf("0 - Sair...\n\n");
}

void lista_gerar (void) {
	int i;
	for	(i = 0; i < tamanho; i++){
		lista[i] = rand()%50;
	}
}

void lista_ler (void) {
	int i;
	for(i = 0; i < tamanho; i++){
		system("cls");
		lista_mostrar();
		printf("\nDigite o valor para a posição %d: ", i);
		scanf("%d", &lista[i]);
	}
}

void lista_limpar (void) {
	int i;
	for (i = 0; i < tamanho; i++){
		ordenado[i] = lista[i];
	}
}

void lista_mostrar_ordenado(void){
	int i;
	printf("[ ");
	for (i = 0; i < tamanho; i++){
		printf("%d ", ordenado[i]);
	}
	printf("] Tempo = %d iterações\n\n", qtd);
}



