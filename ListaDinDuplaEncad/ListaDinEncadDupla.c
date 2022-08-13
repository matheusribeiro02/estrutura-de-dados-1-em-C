#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
    struct elemento *ant;
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

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
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
    if((*li) == NULL){//lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
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
    no->ant = NULL;
    if(*li != NULL)//lista n�o vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){//TERMINAR
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);
    return 1;
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
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
  	printf("%-4s %-4s %-10s %-4s %-4s %-4s\n", "#", "MAT", "NOME", "N1", "N2", "N3");
  	printf("------------------------------------\n");   
	
	int i=0;
	while(no != NULL){
        printf("%-4d %04d %-10s %-4.1f %-4.1f %-4.1f \n", ++i, no->dados.matricula, no->dados.nome, no->dados.n1, no->dados.n2, no->dados.n3);
        no = no->prox;
    }
    printf("------------------------------------\n\n");
}

int uniao(Lista* li, Lista* li_2, Lista* li_3){
	
	if(li == NULL || li_2 == NULL || li_3 == NULL)
        return 0;
    
    struct aluno al;
    
    while(!lista_vazia(li)){
    	consulta_lista_pos(li, 1, &al);
    	insere_lista_final(li_3, al);
    	remove_lista_inicio(li);
	}
	
	while(!lista_vazia(li_2)){
    	consulta_lista_pos(li_2, 1, &al);
    	insere_lista_final(li_3, al);
    	remove_lista_inicio(li_2);
	}
    
	return 1;
}


void intercala(Lista* li,Lista* li_2,Lista* li_3){
	
	struct aluno al;
	
	while(!lista_vazia(li) || !lista_vazia(li_2)) {
		
		if(!lista_vazia(li)){
			consulta_lista_pos(li, 1, &al);
			remove_lista_inicio(li);
			insere_lista_final(li_3, al);
		}
		
		if(!lista_vazia(li_2)){
			consulta_lista_pos(li_2, 1, &al);
			remove_lista_inicio(li_2);
			insere_lista_final(li_3, al);
		}
		
	}
	
}


int inverte(Lista* li, Lista* li_aux){
	
	if(li == NULL || li_aux == NULL)
        return 0;
    
    struct aluno al;  
    
    while(!lista_vazia(li)){
    	consulta_lista_pos(li, 1, &al);
    	insere_lista_inicio(li_aux, al);
    	remove_lista_inicio(li);
	}

	return 1;
}

void comparar(Lista* li, Lista* li_2){
	
 	if(li == NULL)
        return;
    Elem* no = *li;
    Elem* no2 = *li_2;
    
    while (no->prox != NULL && no2->prox != NULL){
    no = no->prox;
    no2 = no2->prox;
    if(no->dados.matricula == no2->dados.matricula){
			
			printf("Iguais\n\n");
    }else
            printf("Diferentes\n\n");  
}
         
}     





