//Arquivo ListaDinEncad.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct aluno Aluno;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
int trocar_elementos(Lista* li, int i, int j);
int trocar_elementos_vesao2(Lista* li, int i, int j);
struct elemento* retornaEnd(Lista* li, int pos);
void divideLista(Lista* li, int pos, Lista* l1,Lista* l2);
