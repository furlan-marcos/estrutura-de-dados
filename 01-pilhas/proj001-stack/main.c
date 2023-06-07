#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define MAX_SIZE 40

typedef struct {
	char nome[50];
	struct tm dataNascimento;
	char matricula[10];
} Aluno;

typedef struct {
    Aluno alunos[MAX_SIZE];
    int topo;
} Pilha;

/* A função 'inicializarPilha' recebe um ponteiro para uma estrutura Pilha e 
inicializa o topo da pilha com o valor -1,   indicando que a pilha está vazia.*/   
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

/* A função 'pilhaVazia' recebe um ponteiro para uma estrutura Pilha e verifica 
se a pilha está vazia. Retorna 1 se a pilha estiver vazia e 0 caso contrário.*/
int pilhaVazia(Pilha *pilha) {
	return pilha->topo == -1; 
}

/* A função 'pilhaCheia' recebe um ponteiro para uma estrutura Pilha e verifica 
se a pilha está cheia. Retorna 1 se a pilha estiver cheia e 0 caso contrário.*/
int pilhaCheia(Pilha *pilha){
	return pilha->topo == MAX_SIZE - 1;
}

/* A função 'empilhar' recebe um ponteiro para uma estrutura Pilha e um aluno a 
ser empilhado. Verifica se a pilha está cheia e, se não estiver, incrementa o 
topo e armazena o aluno na posição correspondente da pilha.*/
void empilhar(Pilha *pilha, Aluno aluno) {
	if (pilhaCheia(pilha)) {
		printf("Erro: a pilha está cheia\n");
		return;
	}
	
	pilha->topo++;
	pilha->alunos[pilha->topo] = aluno;
}

/* A função 'desempilhar' recebe um ponteiro para uma estrutura Pilha e remove o 
aluno do topo da pilha. Verifica se a pilha está vazia e, se não estiver, retorna
o aluno desempilhado. Caso a pilha esteja vazia, retorna um aluno vazio.*/

Aluno desempilhar(Pilha *pilha) {
	Aluno alunoVazio;
	memset(&alunoVazio, 0, sizeof(Aluno)); // Inicializa com zero
	
	if (pilhaVazia(pilha)) {
		printf("Erro: a pilha está vazia\n");
		return alunoVazio;
	}
	
	Aluno alunoDesempilhado = pilha->alunos[pilha->topo];
	pilha->topo--;
	
	return alunoDesempilhado;
}

/* A função 'topoPilha' recebe um ponteiro para uma estrutura Pilha e retorna o 
aluno do topo da pilha, sem removê-lo. Verifica se a pilha está vazia e, se não 
estiver, retorna o aluno do topo. Caso a pilha esteja vazia, retorna um aluno vazio.*/
Aluno topoPilha(Pilha *pilha) {
	Aluno alunoVazio;
	memset(&alunoVazio, 0, sizeof(Aluno)); // Inicializa com zero
	
	if (pilhaVazia(pilha)) {
		printf("Erro: a pilha está vazia\n");
		return alunoVazio;
	}
	
	return pilha->alunos[pilha->topo];
}	

/* A função 'gerarMatricula' recebe um ponteiro para uma estrutura Aluno e gera 
uma matrícula com base na data atual. A matrícula é armazenada no campo matricula
da estrutura Aluno.*/
void gerarMatricula(Aluno *aluno) {
    time_t t = time(NULL);
    struct tm dataAtual = *localtime(&t);

    int ano = dataAtual.tm_year % 100;
    int mes = dataAtual.tm_mon + 1; // A função localtime retorna os meses de 0 a 11

    static int sequencia = 1; // Variável estática para manter o valor entre as chamadas da função
    sprintf(aluno->matricula, "%02d%02d%03d", ano, mes, sequencia++);
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "pt_BR.UTF-8");
	
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao;
    do {
        printf("\n----- Menu -----\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Remover aluno do topo\n");
        printf("3. Exibir todos os alunos cadastrados\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
            	system("cls"); // Limpar a tela
                Aluno aluno;
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]s", aluno.nome);
                gerarMatricula(&aluno);
                empilhar(&pilha, aluno);
                printf("Aluno cadastrado com sucesso!\n");
                break;
            }
            case 2: {
            	system("cls"); // Limpar a tela
                if (!pilhaVazia(&pilha)) {
                    Aluno alunoRemovido = desempilhar(&pilha);
                    printf("Aluno removido: %s\n", alunoRemovido.nome);
                } else {
                    printf("A pilha está vazia. Nenhum aluno para remover.\n");
                }
                break;
            }
            case 3: {
            	system("cls"); // Limpar a tela
                if (!pilhaVazia(&pilha)) {
                    printf("\n----- Alunos Cadastrados -----\n");
                    for (int i = pilha.topo; i >= 0; i--) {
                        printf("Nome: %s\n", pilha.alunos[i].nome);
                        printf("Matrícula: %s\n\n", pilha.alunos[i].matricula);
                    }
                } else {
                    printf("A pilha está vazia. Nenhum aluno cadastrado.\n");
                }
                break;
            }
            case 4:
            	system("cls"); // Limpar a tela
                printf("Encerrando o programa.\n");
                break;
            default:
            	system("cls"); // Limpar a tela
                printf("Opção inválida. Digite novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

