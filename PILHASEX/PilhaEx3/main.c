#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include <string.h>

int main(){
    
    char expressao[20];
    
    strcpy(expressao, "Instituto Federal de Goias");
    
    printf("\n %s \n", expressao);
    
    printf("\n %d \n", strlen(expressao));
    
    Pilha* pi = cria_Pilha();
    struct caractere carac;
    
    int i;
    for(i=0; i < strlen(expressao); i++){
    	carac.c = expressao[i];
	    insere_Pilha(pi, carac);
    }
    
    /*
	Pilha* pi = cria_Pilha();
    
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);
	*/
	
    imprime_Pilha(pi);
    libera_Pilha(pi);
    
    system("pause");
    return 0;
}

