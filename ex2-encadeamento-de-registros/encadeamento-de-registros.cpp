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

int InsereNoInicio(Item** inicio, Aluno aluno) {
	Item* no = (Item*) malloc(sizeof(Item));
	
	if(no == NULL) {
		return 0;
	}
    	        
    no->aluno = aluno;    
	    
    if (inicio != NULL) {
    	no->prox = *inicio;		
	} else {
		no->prox = NULL;
	}
	
    *inicio = no;
    return 1;	
}

void imprimeItens(Item** ini) {
		 
	if(ini == NULL) {
		return;
	}        
	
	Item* no = *ini;
		
	while(no != NULL){
    	printf("%d %s\n", no->aluno.Matricula, no->aluno.Nome); 
        no = no->prox;
    }	
}

int main(int argc, char *argv[]) {
 	
	Item* inicio = NULL;
	
	Aluno a1 = {123, "Maria"};  InsereNoInicio(&inicio, a1);	
	Aluno a2 = {234, "Pedro"};  InsereNoInicio(&inicio, a2);
	Aluno a3 = {345, "Renan"};  InsereNoInicio(&inicio, a3);		
	Aluno a4 = {456, "Silvia"}; InsereNoInicio(&inicio, a4);
	Aluno a5 = {111, "1111"}; InsereNoInicio(&inicio, a5);		
	
	imprimeItens(&inicio);
	
	return 0;
}
