#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"
int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();

    int i;
    for(i=0; i < 4; i++)
       insere_lista_ordenada(li,a[i]);
        
    
    struct aluno b[4] = {{5,"Matheus",9.5,7.8,8.5},
                         {8,"Dudu",7.5,8.7,6.8},
                         {6,"Raphael",9.7,6.7,8.4},
                         {7,"Veiga",5.7,6.1,7.4}};
    Lista* li_2 = cria_lista();

    for(i=0; i < 4; i++)
        insere_lista_ordenada(li_2,b[i]);

    //Lista* li_3 = cria_lista();
    Lista* li_aux = cria_lista();
    
    //QUESTAO 1 // uniao(li, li_2, li_3);
    //QUESTAO 2 // inverte(li, li_aux);
    //QUESTAO 3 // intercala(li, li_2, li_3);
    //QUESTAO 4 //comparar(li, li_2);
    
 
    libera_lista(li);
    libera_lista(li_2);
    //libera_lista(li_3);
    system("pause");
    return 0;
}

