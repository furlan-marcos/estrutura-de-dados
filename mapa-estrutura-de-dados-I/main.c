#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definindo a estrutura da fila
struct no {
    char dado;
    struct no *prox;
};

typedef struct no *ptr_no;
ptr_no fila;
int op;

//Prototipacao
void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);
void fila_mostrar(ptr_no fila);

//Funcao principal
int main(void){
	//inicializando a maquina de numeros randomicos
	srand(time(NULL));
	op = 1;
	//criando o primeiro no da fila
	fila = (ptr_no) malloc(sizeof(struct no));
	fila->dado = 0;
	fila->prox = NULL;
	//laco principal
	while (op != 0){
		system("cls");
		menu_mostrar();
		scanf("%d", &op);
		menu_selecionar(op);
	}
	system("Pause");
	return (0);
}

//mostrar menu de opcoes
void menu_mostrar(){
	fila_mostrar(fila);
	printf("\n\nEscolha uma das opcoes:\n");
	printf("1 - Inserir no final da fila\n");
	printf("2 - Remover no inicio da fila\n");
	printf("0 - Sair\n");
}

//executa a opcao escolhida no menu
void menu_selecionar(int op){
	switch (op){
		case 1:
			fila_inserir(fila);
		break;
		case 2:
			fila_remover(fila);
		break;
	}
}

//insere um elemento no final da fila
void fila_inserir(ptr_no fila) {
	while (fila->prox != NULL) {
		fila = fila->prox;
	}
	fila->prox = (ptr_no) malloc(sizeof(struct no));
	fila = fila->prox;
	fila->dado = rand()%100;
	fila->prox = NULL;
}

//Remove um elemento do inicio da vila
void fila_remover(ptr_no fila) {
	ptr_no atual;
	atual = (ptr_no) malloc(sizeof(struct no));
	atual = fila;
	if (fila->prox != NULL) {
		fila = fila->prox;
		atual->prox = fila->prox;
	}
}

//desenha o conteudo da fila na tela
void fila_mostrar(ptr_no fila) {
	system ("cls");
	while (fila->prox != NULL) {
		printf ("%d, ", fila->dado);
		fila = fila->prox;
	}
	printf("%d, ", fila->dado);
}

