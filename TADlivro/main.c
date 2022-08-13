#include <stdio.h>
#include <stdlib.h>
#include "livro.h"


int main(int argc, char *argv[]) {
	
	Livro* biblio[4];
	
	biblio[0] = crialivro("Harry potter e a pedra filosofal", "J. K. Rowling", "Fantasia", 1997);
	biblio[1] = crialivro("Harry potter e a Camara secreta", "J. K. Rowling", "Fantasia", 1998);
	biblio[2] = crialivro("Harry potter e o Prisioneiro de Askaban", "J. K. Rowling", "Fantasia", 1999);
	biblio[3] = crialivro("Harry potter e o Calice de Fogo", "J. K. Rowling", "Fantasia", 2000);
	biblio[4] = crialivro("Harry potter e a Ordem da Fenix", "J. K. Rowling", "Fantasia", 2003);
	
	int i;
	
	for( i=0; i<5; i++){
		printf("\n %-2s |-| %-2s |-| %-2s |-| %-2d \n", obtemTitulo(biblio[i]), obtemAutor(biblio[i]), obtemGenero(biblio[i]), obtemAno(biblio[i]));
	}
	
	
	return 0;
}
