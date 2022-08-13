
struct Retangulo{

    int altura;
    int largura;
};

// funções

	int perimetro(struct Retangulo ret){
		return (ret.altura*2)+(ret.largura*2);
}

	int area(struct Retangulo ret){
    	return ret.altura*ret.largura;
}
