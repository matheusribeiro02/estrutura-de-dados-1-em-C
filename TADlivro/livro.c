#include "livro.h"
#include <string.h>

struct livro {
	char titulo[50];
	char autor[30];
	char genero[10];
	int ano;
};

Livro* crialivro(char* titulo, char* autor, char* genero, int ano){
	
		Livro* p = (Livro*) malloc(sizeof(Livro));
	
		if (p != NULL) {
		p->ano = ano;
		strcpy(p->titulo, titulo);
		strcpy(p->autor, autor);
		strcpy(p->genero, genero);
		}
		
			return p;
	}

	int obtemAno(Livro* p) {
		return p->ano;
	}

	char* obtemTitulo(Livro* p){
		return p->titulo;
	}
	
	char* obtemAutor(Livro* p){
		return p->autor;
	}

	char* obtemGenero(Livro* p){
		return p->genero;
	}
	
	int verificaModernismo(Livro* p){
		if(p->ano < 1930)
		return -1;
		if(1930 < p->ano < 1945)
		return 0;
		if(p->ano > 1945)
		return 1;
		else printf("erro");
	}
	
