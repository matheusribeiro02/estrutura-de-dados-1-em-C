#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

//Definição do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}


int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
        
    no->dados = al;
    no->prox = NULL;
    
    if((*li) == NULL){//lista vazia: insere início
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}


int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}


void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;    
	
	printf("\n");
  	printf("%-4s %-4s %-10s %-4s %-4s %-4s\n", "#", "MAT", 
	  "NOME", "N1", "N2", "N3");
  	printf("------------------------------------\n");   
	
	int i=0;
	while(no != NULL){
        printf("%-4d %04d %-10s %-4.1f %-4.1f %-4.1f \n", ++i, 
		no->dados.matricula, no->dados.nome, no->dados.n1, 
		no->dados.n2, no->dados.n3);
        no = no->prox;
    }
    printf("------------------------------------\n\n");
}


struct elemento* endereco(Lista* li, int pos){
    	if(li == NULL)
        return;
    	Elem* no;  
	
	while(li != (struct Lista *) 0){
        if(li->pos == pos){
        	return (li);
		} else {
			li = li->prox;	
		}
    }
		  
	return(Lista*) 0;
}
