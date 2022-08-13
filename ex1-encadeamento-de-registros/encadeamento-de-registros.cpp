#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    int Matricula;
    char Nome[30];    
};

struct Item{
    struct Aluno aluno; 
    struct Item *prox;
};

int main(int argc, char *argv[]) {
 	
	Item* inicio = NULL;
	
	Aluno a1 = {123, "Maria"}; 	
	Aluno a2 = {234, "Pedro"}; 
	Aluno a3 = {345, "Renan"};  	
	Aluno a4 = {456, "Silvia"}; 
	
	Item i1 = {a1, NULL};		
	inicio = &i1;
	
	Item i2 = {a2, NULL};
	i1.prox = &i2;
	
	Item i3 = {a3, NULL};
	i2.prox = &i3;
	
	Item i4 = {a4, NULL};
	i4.prox = &i2;
	i1.prox = &i4;
	
	while(inicio != NULL){
    	printf("%d %s\n", inicio->aluno.Matricula, inicio->aluno.Nome); 
        inicio = inicio->prox;
    }	
	
	return 0;
}
