//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define tamanho 10

//Variáveis
int lista[tamanho];
int ordenado[tamanho];
int opt=-1;
int qtd;

//Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);
void troca(int* a, int* b);
int shellSort(int vec[], int tam);

//Função Principal
int main(void){
	srand(time(NULL));
	do {
		system("cls");
		lista_mostrar();
		lista_mostrar_ordenado();
		menu_mostrar();
		scanf("%d",&opt);
		switch (opt){
			case 1:
				lista_gerar();
			break;
			case 2:
				lista_ler();
			break;
			case 3:
				lista_limpar();
                qtd = shellSort(ordenado, tamanho);
                lista_mostrar_ordenado();
                break;
		}
	}while(opt!=0);
	system("pause");
	return(0);
}

//Mostra o conteúdo da lista
void lista_mostrar(void){
	int i;
	printf("[ ");
	for (i = 0; i < tamanho; i++ ){
		printf("%d ",lista[i]);
	}
	printf("]\n\n");
}

//Mostra o menu
void menu_mostrar(void){
	printf("1 - Gerar lista aleatoriamente\n");
	printf("2 - Criar lista manualmente\n");
	printf("3 - Utilizar Shell Sort\n");
	printf("0 - Sair...\n\n");
}

//Gera uma lista aleatória
void lista_gerar(void){
	int i;
	for (i = 0; i < tamanho; i++){
	lista[i] = rand()%50;
	}
}

//Permite que o usuário entre com os valores da lista
void lista_ler(void){
	int i;
	for (i = 0; i < tamanho; i++){
		system("cls");
		lista_mostrar();
		printf("\nDigite o valor para a posicao %d: ", i);
		scanf("%d", &lista[i]);
	}
}

//Preparar a lista para ordenação
void lista_limpar(void){
	int i;
	for (i = 0; i < tamanho; i++) {
		ordenado[i] = lista[i];
	}
}

//Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void){
	int i;
	printf("[ ");
	for (i = 0; i < tamanho; i++ ){
	printf("%d ",ordenado[i]);
	}
	printf("] Tempo = %d iteracoes\n\n", qtd);
}

//Função genérica de troca de valores
void troca(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//Aplica o shellSort
int shellSort(int vec[], int tam) {
	int i , j , valor, qtd=0;
	int gap = 1;
	do {
		gap = 3*gap+1;
	} while(gap < tam);
	do {
		gap /= 3;
		for(i = gap; i < tam; i++) {
			valor = vec[i];
			j = i - gap;
			while (j >= 0 && valor < vec[j]) {
			vec[j + gap] = vec[j];
			j -= gap;
			qtd++;
			}
			vec[j + gap] = valor;
		}
	} while ( gap > 1);
	return (qtd);
}
