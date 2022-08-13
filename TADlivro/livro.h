typedef struct livro Livro;

Livro* crialivro(char* titulo, char* autor, char* genero, int ano);

int obtemAno(Livro* p);
char* obtemTitulo(Livro* p);
char* obtemAutor(Livro* p);
char* obtemGenero(Livro* p);

int verificaModernismo(Livro* p);
