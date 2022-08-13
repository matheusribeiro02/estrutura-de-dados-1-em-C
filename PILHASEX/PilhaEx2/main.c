#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

void copia(Pilha* pi_1, Pilha* pi_2){
	
	struct aluno al;
	Pilha* pi_aux = cria_Pilha();
	
	while(!Pilha_vazia(pi_1)){
		consulta_topo_Pilha(pi_1, &al);
		remove_Pilha(pi_1);
		insere_Pilha(pi_2, al);	
		insere_Pilha(pi_aux, al);	
	}
	
	//QUESTAO NÃO PEDE PARA RECUPERAR PILHA1
}



int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    
	Pilha* pi = cria_Pilha();
    
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);
        
	Pilha* pi_2 = cria_Pilha();
    
	copia(pi, pi_2);

    imprime_Pilha(pi);
    imprime_Pilha(pi_2);
    
    libera_Pilha(pi);
    libera_Pilha(pi_2);
    system("pause");
    return 0;
}

