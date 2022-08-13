#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
    Aluno a1 =  {2,"Andre",2.1,2.2,2.3};
    Aluno a2 = {4,"Ricardo",4.1,4.2,4.3};
    Aluno a3 = {5,"Carla",5.1,5.1,5.3};   	
    Aluno a4 = {1,"Bianca",1.1,1.2,1.3};
	

    Lista* li = cria_lista();
   

        insere_lista_inicio(li,a1);
        insere_lista_inicio(li,a2);
        insere_lista_inicio(li,a3);
        insere_lista_inicio(li,a4);
 	   
    imprime_lista(li);    
 
	struct elemento* endereco = retornaEnd(li, 1);
    
    libera_lista(li);
    system("pause");
    return 0;
}

