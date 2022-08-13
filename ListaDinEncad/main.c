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
 
    imprime_lista(li);    
    
    
    libera_lista(li);
    system("pause");
    return 0;
}


