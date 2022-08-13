#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include <string.h>

int compara(char* ax, char* ay){
	
	if(strlen(ax) != strlen(ay))
		return 0;
	
	Pilha* pi = cria_Pilha();
	struct caractere carac;
	
	int i;
    for(i=0; i < strlen(ax); i++){
    	carac.c = ax[i];
	    insere_Pilha(pi, carac);
    }
	
	
	libera_Pilha(pi);
	return 1;
}

int main(){
    
    char ax[20];
    char ay[20];
    
    strcpy(ax, "ABCD");
    strcpy(ay, "DCBA");
    
     if (compara(ax, ay))
    	printf("\nSUCESSO\n");
	else
		printf("\nNAO ESTA NO PADRAO\n");
/*   
    printf("\n %s \n", ax);
    printf("\n %s \n", ay);
    
    printf("\n %d \n", strlen(ax));
    printf("\n %d \n", strlen(ay));
*/  

    Pilha* pi = cria_Pilha();
    struct caractere carac;
   
    int i;
    for(i=0; i < strlen(ax); i++){
    	carac.c = ax[i];
	    insere_Pilha(pi, carac);
    }


    for(i=0; i < strlen(ay); i++){
    	carac.c = ay[i];
	    insere_Pilha(pi, carac);
    }
   
	
    imprime_Pilha(pi);
    libera_Pilha(pi);
    
    system("pause");
    return 0;
}

