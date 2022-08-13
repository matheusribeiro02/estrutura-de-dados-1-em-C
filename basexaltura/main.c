#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[]) {
	
	struct Retangulo ret;

	printf("Digite o valor da altura do retangulo em metros: ");
	scanf("%d", &ret.altura);

	printf("Digite o valor da largura do retangulo em metros: ");
	scanf("%d", &ret.largura);

	printf("Perimetro = %d\n",perimetro(ret));

	printf("Area = %d\n",area(ret));
	return 0;
}
