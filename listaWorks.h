//Arquivo LDED.h - ListaWorks Dinamica Encadeada Dupla
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef struct palavras Palavras;

struct palavras {
    char *input;
    char *codigo;
    char *errorMessage;
    char *errorKind;
    int line;
    int flag;
};
//Definição do tipo ListaWorks
struct elemento {
    struct elemento *ant;
    Palavras dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento *ListaWorks;

ListaWorks *cria_ListaWorks();

void libera_ListaWorks(ListaWorks *li);

int insere_ListaWorks_final(ListaWorks *li, char *msg, int i);

int tamanho_ListaWorks(ListaWorks *li);

int ListaWorks_vazia(ListaWorks *li);

void imprime_ListaWorks(ListaWorks *li);