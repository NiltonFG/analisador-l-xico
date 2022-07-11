#include "listaWorks.h" //inclui os Protótipos

ListaWorks *cria_ListaWorks() {
    ListaWorks *li = (ListaWorks *) malloc(sizeof(ListaWorks));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_ListaWorks(ListaWorks *li) {
    if (li != NULL) {
        Elem *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}


int insere_ListaWorks_final(ListaWorks *li, char *msg, int i) {
    if (strlen(msg) == 0) {
        return ERRO;
    }
    Elem *no;
    if (li == NULL) return ERRO;
    no = (Elem *) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;
    no->dado.input = (char *) malloc(sizeof(char) * strlen(msg) + 1);
    strcpy(no->dado.input, msg);
    char b = '\0';
    char *c = &b;
    strcat(no->dado.input, c);
    no->dado.codigo = (char *) malloc(sizeof(char) * 50);
    no->dado.errorKind = (char *) malloc(sizeof(char) * 50);
    no->dado.errorMessage = (char *) malloc(sizeof(char) * 50);
    no->dado.line = i;
    no->prox = NULL;
    if ((*li) == NULL) {   //lista vazia: insere início
        no->ant = NULL;
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return OK;
}

int tamanho_ListaWorks(ListaWorks *li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem *no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int ListaWorks_cheia(ListaWorks *li) {
    return FALSO;
}

int ListaWorks_vazia(ListaWorks *li) {
    if (li == NULL)
        return OK;
    if (*li == NULL)
        return OK;
    return FALSO;
}

void imprime_ListaWorks(ListaWorks *li) {
    Elem *no = *li;
    if (li == NULL)
        return;
    while (no != NULL) {
        printf("%s, %s\n", no->dado.input, no->dado.codigo);
        no = no->prox;
    }
}