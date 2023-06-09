#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//definindo a estrutura da fila
struct no {
    char dado;
    struct no *prox;
};

typedef struct no *ptr_no;
ptr_no fila;
int op;

//definindo a estrutura da pilha
struct no_pilha {
    char dado;
    struct no_pilha* prox;
};
typedef struct no_pilha* ptr_no_pilha;

// Prototipacao
void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir_manual(ptr_no fila);
void fila_inserir_aleat(ptr_no fila);
char atribuir_valor(int numero);
void fila_remover(ptr_no* fila);
void fila_mostrar(ptr_no fila);

void converter_sequencia(ptr_no fila, ptr_no_pilha* pilha);
void imprimir_pilha(ptr_no_pilha pilha);

//Funcao principal
int main(void){
	//inicializando a maquina de numeros randomicos
	srand(time(NULL));
	op = 1;
	
	//criando o primeiro no da fila
	fila = (ptr_no) malloc(sizeof(struct no));
	fila->dado = 0;
	fila->prox = NULL;
	
	//criando o topo da pilha
	ptr_no_pilha pilha = NULL;

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

//insere um elemento escolhido no final da fila
void fila_inserir_manual(ptr_no fila) {
    int opcao;
    char valor;
    ptr_no atual = fila;

    do {
        system("cls");
        fila_mostrar(fila);
        printf("\n\nInserindo valor manualmente");
        printf("\n\nEscolha um valor:\n");
        printf("1 - A\n");
        printf("2 - C\n");
        printf("3 - T\n");
        printf("4 - G\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;
        }

        valor = atribuir_valor(opcao);

        if (valor == '\0') {
            printf("Opcao invalida! Por favor, tente novamente.\n");
            continue;
        }

        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = (ptr_no)malloc(sizeof(struct no));
        atual = atual->prox;
        atual->dado = valor;
        atual->prox = NULL;
    } while (1);

    if (opcao == 0) {
        return;
    }
}

//insere 4 elemento aleatorio no final da fila
void fila_inserir_aleat(ptr_no fila) {
    int i = 0;
    ptr_no atual;

    while (i < 4) {
        system("cls");
        fila_mostrar(fila);
        printf("\n\nInserindo valores aleatoriamente\n");

        int opcao = (rand() % 4) + 1;
        char valor = atribuir_valor(opcao);

        printf("Valor a ser inserido: %c\n", valor);
        sleep(1);

        atual = fila; // reinicializa para o primeiro n� da fila

        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = (ptr_no)malloc(sizeof(struct no));
        atual = atual->prox;
        atual->dado = valor;
        atual->prox = NULL;

        i++;
    }
    system("cls");
    fila_mostrar(fila);    
	system("pause");
    return; // retorna ao menu_selecionar
}

//mostrar menu de opcoes
void menu_mostrar(){
	fila_mostrar(fila);
	printf("\n\nEscolha uma das opcoes:\n");
	printf("1 - Inserir manualmente na fila\n");
	printf("2 - Inserir aleatoriamente na fila\n");
	printf("3 - Remover da fila\n");
	printf("0 - Sair\n");
}

//executa a opcao escolhida no menu
void menu_selecionar(int op){
	switch (op){
		case 1:
			fila_inserir_manual(fila);
		break;
		case 2:
			fila_inserir_aleat(fila);
		break;
		case 3:
			fila_remover(&fila);
		break;
	}
}

char atribuir_valor(int numero) {
    char valor;

    switch (numero) {
        case 1:
            valor = 'A';
            break;
        case 2:
            valor = 'C';
            break;
        case 3:
            valor = 'T';
            break;
        case 4:
            valor = 'G';
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida! Por favor, tente novamente.\n");
            break;
    }

    return valor;
}

void converter_sequencia(ptr_no fila, ptr_no_pilha* pilha) {
    ptr_no atual = fila;
    
    while (atual != NULL) {
        char nucleotideo = atual->dado;
        char convertido;
        
        // Realize a convers�o de nucleot�deos
        switch (nucleotideo) {
            case 'A':
                convertido = 'T';
                break;
            case 'T':
                convertido = 'A';
                break;
            case 'C':
                convertido = 'G';
                break;
            case 'G':
                convertido = 'C';
                break;
            default:
                convertido = nucleotideo; // Mant�m o mesmo valor se n�o for um nucleot�deo v�lido
                break;
        }
        
        // Insira o nucleot�deo convertido na pilha
        ptr_no_pilha novo = (ptr_no_pilha)malloc(sizeof(struct no_pilha));
        novo->dado = convertido;
        novo->prox = *pilha;
        *pilha = novo;
        
        atual = atual->prox;
    }
}

void imprimir_pilha(ptr_no_pilha pilha) {
    printf("Pilha: ");
    
    while (pilha != NULL) {
        printf("%c ", pilha->dado);
        pilha = pilha->prox;
    }
    
    printf("\n");
}

//Remove um elemento do inicio da fila
void fila_remover(ptr_no* fila) {
    if (*fila != NULL) {
        ptr_no atual = *fila;
        *fila = (*fila)->prox;
        free(atual);
    }
}

//desenha o conteudo da fila na tela
void fila_mostrar(ptr_no fila) {
    system("cls");

    if (fila == NULL || (fila->prox == NULL && fila->dado == 0)) {
        printf("Fila: [a fila esta vazia]\n");
        return;
    }

    printf("Fila: ");
    while (fila != NULL) {
        printf("%c ", fila->dado);
        fila = fila->prox;
    }
    printf("\n");
}
