#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(){
    struct aluno al, a[6] = {{2,"Andre",2.1,2.2,2.3},
                         {4,"Ricardo",4.1,4.2,4.3},
                         {1,"Bianca",1.1,1.2,1.3},
                         {3,"Ana",3.1,3.2,3.3},						 
						  {5,"Carla",5.1,5.1,5.3},
						  {7,"Luana",7.1,7.2,7.3}					 
						 
						 };
						 
    Lista* li = cria_lista();
   

    int i;
    for(i=0; i < 6; i++)
        insere_lista_final(li,a[i]);
        
    printf("tamanho da lista : %d\n", tamanho_lista(li));
        
    imprime_lista(li);
 
 	/*
    pElem p;
    p = retornarEndereco1(li, 1);
    printf("p -> %d\n", p);
    */
    
    /*
	Lista* li_1 = cria_lista();
    Lista* li_2 = cria_lista();
    
	divideLista(li, 5, li_1, li_2);

	imprime_lista(li);  
	imprime_lista(li_1);    
	imprime_lista(li_2);
	*/
	
	//trocaDados(li, 1, 2);
	
	//trocaElemento(li, 1, 2);
	
    //imprime_lista(li);
    
	libera_lista(li);
    system("pause");
    return 0;
}


