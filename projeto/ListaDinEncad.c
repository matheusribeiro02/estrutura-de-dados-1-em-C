#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h" 

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
    
    if((*li) == NULL){
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

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
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
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
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
  	printf("%-4s %-4s %-10s %-4s %-4s %-4s %-4s %-4s\n", "#", "MAT", 
	  "NOME", "N1", "N2", "N3", "END", "PROX");
  	printf("------------------------------------\n");   
	
	int i=0;
	while(no != NULL){
        printf("%-4d %04d %-10s %-4.1f %-4.1f %-4.1f %d %d \n", ++i, 
		no->dados.matricula, no->dados.nome, no->dados.n1, 
		no->dados.n2, no->dados.n3, no, no->prox);
        no = no->prox;
    }
    printf("------------------------------------\n\n");
}

int consultaEndereco(Lista* li, int pos){
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
		return no;
	}
}

pElem retornarEndereco(Lista* li, int pos){
	if(lista_vazia(li) || pos <= 0 || pos > tamanho_lista(li)){
        return NULL;
	}
	
	Elem* no = *li;
	Elem* enderecoRetorno;
	
	int i=0;
	while(no != NULL && i < pos){
	i++;
	enderecoRetorno = no;
	no = no->prox;
	}
	
	return enderecoRetorno;
}

void divideLista(Lista*li, int pos, Lista* li_1, Lista* li_2){
	
	Elem* fim_p1 =  retornarEndereco(li, pos-1);
	Elem* inicio_p2 = retornarEndereco(li, pos);
	
	if(inicio_p2 == NULL ){
		*li_1 = *li;
		*li_2 = NULL;
		*li = NULL;
		return;
	}
	
	*li_1 = *li;
	fim_p1->prox = NULL;
	*li_2 = inicio_p2;
	*li = NULL;
}

int trocaDados(Lista* li, int i, int j){
	if(li == NULL || i <= 0 || j <= 0)
		return 0;
	Elem *no1 = *li;
	Elem *no2 = *li;
	
	char nomeaux[30];
	float nota1, nota2, nota3;
	int matriculaAux;
	
	int aux = 1;
	while(no1 != NULL && aux < i){
		no1 = no1->prox;
		aux++;
	}
	if(no1 == NULL)
		return 0;
	else{
	    matriculaAux = no1->dados.matricula;
	    strcpy(nomeaux, no1->dados.nome);
	    nota1 = no1->dados.n1;
	    nota2 = no1->dados.n2;
	    nota3 = no1->dados.n3;
	}
	
	aux = 1;
    while(no2 != NULL && aux < j){
        no2 = no2->prox;
        aux++;
    }
    if(no2 == NULL)
        return 0;
    else{
        no1->dados.matricula = no2->dados.matricula;
        strcpy(no1->dados.nome, no2->dados.nome);
        no1->dados.n1 = no2->dados.n1;
        no1->dados.n2 = no2->dados.n2;
        no1->dados.n3 = no2->dados.n3;
        
        no2->dados.matricula = matriculaAux;
        strcpy(no2->dados.nome, nomeaux);
        no2->dados.n1 = nota1;
        no2->dados.n2 = nota2;
        no2->dados.n3 = nota3;

    }

}

int trocaElemento(Lista* li, int i, int j){
	if(li == NULL || i <= 0 || j <= 0)
		return 0;
	
	int endereco1, endereco2;
	
    endereco1 = consultaEndereco(li, i);
    endereco2 = consultaEndereco(li, j);
    
    Elem *no1 = endereco1;
    Elem *no2 = endereco2;
    Elem *no3;
    
    no3 = (Elem*) malloc(sizeof(Elem));

    
    no3->dados = no1->dados;
    no1->dados = no2->dados;
    no2->dados = no3->dados;

    free(no3);
	
}
