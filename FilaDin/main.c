#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

void concatenar(Fila* fi_1, Fila* fi_2, Fila* fi_3 ){
	
	struct aluno al;
	Fila* fi_aux = cria_Fila();
	
	while(!Fila_vazia(fi_1)){
		consulta_Fila(fi_1, &al);
		remove_Fila(fi_1);
		insere_Fila(fi_3, al);	
		insere_Fila(fi_aux, al);	
	}
	
	while(!Fila_vazia(fi_aux)){
		consulta_Fila(fi_aux, &al);
		remove_Fila(fi_aux);
		insere_Fila(fi_1, al);		
	}
	
	while(!Fila_vazia(fi_2)){
		consulta_Fila(fi_2, &al);
		remove_Fila(fi_2);
		insere_Fila(fi_3, al);	
		insere_Fila(fi_aux, al);		
	}
	
	while(!Fila_vazia(fi_aux)){
		consulta_Fila(fi_aux, &al);
		remove_Fila(fi_aux);
		insere_Fila(fi_2, al);		
	}
	
	libera_Fila(fi_aux);
}


void separa(Fila* fi, Fila* fi_ap, Fila* fi_rep); ){
	
	struct aluno al;
	Fila* fi_aux = cria_Fila();
	
	Elem *no = (Elem*) malloc(sizeof(Elem));
	
    if(no == NULL)
        return 0;
		
		while(!fila_vazia(fi_1) && (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3 >= 6){
		consulta_Fila(fi_1, &al);
		remove_Fila(fi_1);
		insere_Fila(fi_3, al);
		insere_Fila(fi_aux, al);		
	}
	
		while(!Fila_vazia(fi_aux)){
		consulta_Fila(fi_aux, &al);
		remove_Fila(fi_aux);
		insere_Fila(fi_1, al);		
	}
	
libera_Fila(fi_aux);	

}


void intercala(Fila* fi, Fila* fi_2, Fila* fi_3){
	
	struct aluno al;
	
	while(!Fila_vazia(fi) || !Fila_vazia(fi_2)) {
		
		if(!Fila_vazia(fi)){
			consulta_Fila(fi, &al);
			remove_Fila(fi);
			insere_Fila(fi_3, al);
		}
		
		if(!Fila_vazia(fi_2)){
		consulta_Fila(fi_2, &al);
		remove_Fila(fi_2);
		insere_Fila(fi_3, al);		
		}
	}
	
}


/*
void inverte(Fila* fi,Fila* fi_2,Fila* fi_3){
	
	struct aluno al;
	Fila* fi_aux = cria_Fila();
	
	while(!Fila_vazia(fi) || !Fila_vazia(fi_2)) {
		
		if(!Fila_vazia(fi)){
			consulta_FilaFinal(fi, &al);
			remove_Fila(fi);
			insere_Fila(fi_3, al);
			insere_Fila(fi_aux, al);
		}
		
		if(!Fila_vazia(fi_2)){
			consulta_FilaFinal(fi_2, &al);
			remove_Fila(fi_2);
			insere_Fila(fi_3, al);
		}
		
	}
	
}

*/

int main(){
    struct aluno al,a[6] = {{1,"Andre",9.5,7.8,8.5},
                         {2,"Ricardo",7.5,8.7,6.8},
                         {3,"Bianca",9.7,6.7,8.4},
                         {4,"Ana",5.7,6.1,7.4},
						 {5,"João",5.7,2.4,1.3},
						 {6,"Matheus",5.7,1.3,3.4}};
    
	Fila* fi = cria_Fila();
    int i;
    for(i=0; i < 6; i++){
        insere_Fila(fi,a[i]);        
    }   
	
/*	struct aluno b[6] = {{7,"Marcos",9.5,7.8,8.5},
                         {8,"RRR",7.5,8.7,6.8},
                         {9,"AAA",9.7,6.7,8.4},
                         {10,"TTT",5.7,6.1,7.4},
						 {11,"FFF",5.7,2.4,1.3},
						 {12,"Felps",5.7,1.3,3.4}};
    
	Fila* fi_2 = cria_Fila();
	for(i=0; i < 6; i++){
        insere_Fila(fi_2,b[i]);        
    }   
*/
    Fila* fi_ap = cria_Fila();
	Fila* fi_rep = cria_Fila();
	
	//intercala(fi, fi_2, fi_3);
	
	//intercala(fi, fi_2, fi_3);
	
	aprovar(fi, fi_ap, fi_rep);
	
	//concatenar(fi, fi_2, fi_3);
	
	imprime_Fila(fi);
	imprime_Fila(fi_2);
	imprime_Fila(fi_3);

    libera_Fila(fi);
    libera_Fila(fi_2);
	libera_Fila(fi_3);
    system("pause");
    return 0;
}

