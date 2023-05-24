#include <stdio.h>
#include <stdlib.h>

//Ponteiros para Struct
//https://youtu.be/MciBI4xxhEw

/* Usando typedef na struct para encurtar o comando na declaracao */
typedef struct {
	int matricula;
	float nota;
}tAluno;

int main(void) {
	tAluno a1; //a1 e uma struct do tipo tAluno
	tAluno *ptrAluno = &a1; //ponteiro do tipo tAluno que recebe o endereco de a1
	
	a1.matricula = 555;
	a1.nota = 8.0;
	
	//Exibindo dados usando a struct diretamente usando "."
	printf("Matricula: %d\nnota: %.2f\n", a1.matricula, a1.nota);
	
	//Podemos atribuir ou acessar um valor usando o ponteiro (*ptrAluno)
	(*ptrAluno).nota = 8.5;
	
	//Exibindo dados usando um ponteiro para struct
	printf("\nMatricula: %d\nnota: %.2f\n", (*ptrAluno).matricula, (*ptrAluno).nota);
	
	//ptrAluno-> substitui a notacao (*ptrAluno). de forma mais intuitiva
	//atribuindo um novo valor para a nota usando ptrAluno->
	ptrAluno->nota = 9.0; //portanto, "(*ptrAluno).nota" e a mesma coisa que usar "ptrAluno->nota"
	
	//Exibindo novamente dados usando um ponteiro para struct
	printf("\nMatricula: %d\nnota: %.2f\n", ptrAluno->matricula, ptrAluno->nota);
	
	system("pause"); 
	return 0;
}
