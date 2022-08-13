#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadCirc.h"
int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
						 };
    Lista* li = cria_lista();

    int i;
    for(i=0; i < 4; i++)
        insere_lista_inicio(li,a[i]);
        
struct aluno b[4] = {	 {8,"Bigode",5.7,6.1,7.4},
                         {5,"Weverton",5.7,6.1,7.4},
                         {6,"Marcos",5.7,6.1,7.4},
                         {7,"Veiga",5.7,6.1,7.4}
						 };
						 
	Lista* li_2 = cria_lista();

    for(i=0; i < 4; i++)
        insere_lista_inicio(li_2,b[i]);
        
    Lista* li_3 = cria_lista();
    
    //QUESTAO 1
    
	divide(li, li_2, li_3, 1);
	
	imprime_lista(li_2);
    
    
    //QUESTAO 2
        
    /*if(remove_n_primeiroselem(li, 2)){
    	printf("\nSUCESSO\n");
    	imprime_lista(li);
	} else{
		printf("\nERRO AO REMOVER\n");
	}
    */
    
    //QUESTAO 3
    
    //estaOrdenada(li);
    
    
    libera_lista(li);
    system("pause");
    return 0;
}

