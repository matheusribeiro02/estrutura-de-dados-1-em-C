#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include <string.h>

int verifica(char* expressao) {
	
	Pilha* pi = cria_Pilha();
	struct caractere carac;
	
	 int i = 0;
	 for(i=0; i < strlen(expressao); i++){
    	
		if (expressao[i] == '(' || expressao[i] == '[') {
			carac.c = expressao[i];
	    	insere_Pilha(pi, carac);
		}
		else {
			if (Pilha_vazia(pi)) {
			libera_Pilha(pi);
			return 0;
			}
			
			consulta_topo_Pilha(pi, &carac);
			remove_Pilha(pi);
			
			if((expressao[i] == ')' && carac.c != '(') || (expressao[i] == ']' && carac.c != '[')){
				libera_Pilha(pi);
				return 0;
			}
		}
		
    }
    
    if(i != strlen(expressao) || (!Pilha_vazia(pi)))
		return 0;
   
    libera_Pilha(pi);
	return 1;
}

int main(){
    
    char expressao[20];
    
    strcpy(expressao, "([](([]))[])");
    
    if (verifica(expressao))
    	printf("\nSUCESSO\n");
	else
		printf("\nNAO ESTA NO PADRAO\n");
    
    // printf("\n %s \n", expressao);   
    // printf("\n %d \n", strlen(expressao));
    
   
    
    /*
	Pilha* pi = cria_Pilha();
    
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);
	*/
	
    
    
    system("pause");
    return 0;
}

