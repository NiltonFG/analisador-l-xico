#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaWorks.h"
//#include "automatos.h"

/*
Analizador léxico.

Nilton Felippe Gavazzi
Luiz Fernando Rissotto
William Simonelli Rocha
*/

char *readFile();

void sintatico(Elem *no);

void writeFile(ListaWorks *li);

int pesquisaTabRes(char *input);

void lookAhead(Elem *no);

ListaWorks *separaArquivo(char *buffer);

void lexico(ListaWorks *lista);

char *strArr1[33] = {
        "program",
        "var",
        "integer",
        "real",
        "begin",
        "end",
        "while",
        "read",
        "write",
        "const",
        "procedure",
        "else",
        "then",
        "if",
        "do",
        "to",
        "for",
        ">=",
        "<>",
        "<=",
        "+",
        "-",
        ".",
        ",",
        ";",
        ":=",
        "*",
        "=",
        "/",
        "(",
        ")",
        "<",
        ":"

};
char *strArr2[33] = {
        "simb_program",
        "simb_var",
        "simb_tipo",
        "simb_tipo",
        "simb_begin",
        "simb_end",
        "simb_while",
        "simb_read",
        "simb_write",
        "simb_const",
        "simb_procedure",
        "simb_else",
        "simb_then",
        "simb_if",
        "simb_do",
        "simb_to",
        "simb_for",
        "simb_maior_igual",
        "simb_diferente",
        "simb_menor_igual",
        "simb_mais",
        "simb_menos",
        "simb_ponto",
        "simb_virgula",
        "simb_ponto_virgula",
        "simb_atribuição",
        "simb_mutiplicacao",
        "simb_igual",
        "simb_divisão",
        "simb_parentesesA",
        "simb_parentesesF",
        "simb_menor",
        "simb_doisPontos"

};

int main() {
    char *buffer = readFile();
    ListaWorks *li = separaArquivo(buffer);
    lexico(li);
    sintatico(li);
    libera_ListaWorks(li);
    return 0;
}

void lookAhead(Elem *no) {
    Elem *aux;
    if (strcmp(no->dado.input, "begin") == 0) {
        no = aux;
        while (1) {
            if (strcmp(aux->dado.input, "end") == 0 && aux->dado.flag == 0) {
                aux->dado.flag = 1;
                break;
            }
            if (aux->prox == NULL) {
                strcpy(no->dado.errorKind, "sintatico");
                strcpy(no->dado.errorMessage, "end esperado");
            }
            aux = aux->prox;
        }
    }
    if (strcmp(no->dado.input, "(") == 0) {
        no = aux;
        while (1) {
            if (strcmp(aux->dado.input, "(") == 0 && aux->dado.flag == 0) {
                aux->dado.flag = 1;
                break;
            }
            if (aux->prox == NULL) {
                strcpy(no->dado.errorKind, "sintatico");
                strcpy(no->dado.errorMessage, "fecha-parenteses esperado");
            }
            aux = aux->prox;
        }
    }
    if (strcmp(no->dado.input, "{") == 0) {
        no = aux;
        while (1) {
            if (strcmp(aux->dado.input, "{") == 0 && aux->dado.flag == 0) {
                aux->dado.flag = 1;
                break;
            }
            if (aux->prox == NULL) {
                strcpy(no->dado.errorKind, "sintatico");
                strcpy(no->dado.errorMessage, "fecha-chaves esperado");
            }
            aux = aux->prox;
        }
    }
}

void sintatico(Elem *no) {
    if (no == NULL)
        return;
    else {
        if (strcmp(no->dado.codigo, "simb_program")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_var")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_tipo")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_begin")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_end")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_while")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_read")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_write")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_const")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_procedure")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_else")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_then")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_if")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_do")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_to")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_for")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_maior_igual")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_diferente")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_menor_igual")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_mais")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_menos")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_ponto")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_virgula")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_ponto_virgula")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_atribuição")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_mutiplicacao")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_igual")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_divisão")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_parentesesA")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_parentesesF")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_menor")) {
            no = no->prox;
            sintatico(no);
        }
        if (strcmp(no->dado.codigo, "simb_doisPontos")) {
            no = no->prox;
            sintatico(no);
        }
        return;
    }
}

char *readFile() {
    FILE *ptr;
    ptr = fopen("../suportFile.txt", "r");
    if (ptr == NULL) { //Verifica erro na abertura de arquivo.
        printf("Erro ao abrir arquivo.\n");
        return ("erro de leitura");
    }

    fseek(ptr, 0, SEEK_END);
    int size = ftell(ptr);
    char *buffer;   //cria um buffer para salvar em memória para análise
    buffer = (char *) malloc(sizeof(char) * size);
    fseek(ptr, 0, SEEK_SET);
    fread(buffer, sizeof(size), size, ptr);
    fclose(ptr);
    return buffer;
}

ListaWorks *separaArquivo(char *buffer) {
    ListaWorks *lista = cria_ListaWorks();
    printf("%s\n", buffer);
    printf("\n\n\n ----------------------------------------------------------------------------\n\n\n");
    int aux;
    int flag = 0;
    char *auxMsg;
    char *pontos;
    char c;
    char mensagem[50];
    int n = 0;
    int line;

    for (int i = 0; i <= strlen(buffer); ++i) {
        if (flag != 1) {
            aux = i;
            flag = 1;
        }
        c = buffer[i];
        if ((int) c >= 97 && (int) c <= 122) {
            mensagem[n] = c;
            n++;
        }
        if ((int) c >= 48 && (int) c <= 57) {
            mensagem[n] = c;
            n++;
        } else if (c == '\n' || c == ' ' || c == '\t') {
            auxMsg = (char *) malloc(sizeof(char) * n);
            int j = 0;

            if (c == '\n') {
                line++;
            }
            while (j < n) {
                auxMsg[j] = mensagem[j];
                j++;
            }
            n = 0;
            auxMsg[j] = '\0';

            insere_ListaWorks_final(lista, auxMsg, line);
            flag = 0;
        }
        if (!((int) c >= 97 && (int) c <= 122) && !((int) c >= 48 && (int) c <= 57) && !(c == '\n' || c == ' ')) {
            auxMsg = (char *) malloc(sizeof(char) * n);
            int j = 0;
            mensagem[n] = c;
            while (j < n) {
                auxMsg[j] = mensagem[j];
                j++;
            }
            auxMsg[n] = '\0';
            if ((int) c == 58 && (int) buffer[i + 1] == 61) {
                mensagem[0] = c;
                mensagem[1] = buffer[i + 1];
                mensagem[2] = '\0';
            } else {
                mensagem[0] = c;
                mensagem[1] = '\0';
            }
            if ((int) c != 61 && (int) buffer[i - 1] != 58) {
                insere_ListaWorks_final(lista, auxMsg, 0);
                insere_ListaWorks_final(lista, mensagem, 0);
            }
            n = 0;
            flag = 0;
        }
    }
    int tam = tamanho_ListaWorks(lista);
    return lista;
}

void lexico(ListaWorks *lista) {
    if (lista == NULL)
        return;

    Elem *no = *lista;
    int flag = 0;
    int j = 0;
    while (no != NULL) {
        flag = 0;
        j = -1;
        j = pesquisaTabRes(no->dado.input);
        if (j != -1) {
            strcpy(no->dado.codigo, strArr2[j]);
            flag++;
        }
        char *uhu = no->dado.input;
        if ((int) no->dado.input[0] >= 97 && (int) no->dado.input[0] <= 122 && flag == 0) {
            strcpy(no->dado.codigo, "id");
            flag++;
        }
        if ((int) no->dado.input[0] >= 48 && (int) no->dado.input[0] <= 57 && flag == 0) {
            strcpy(no->dado.codigo, "simb_num");
            flag++;
        }
        if (flag == 0) {
            strcpy(no->dado.codigo, "ERRO, caracter nao permitido");
        }
        no = no->prox;
    }
    imprime_ListaWorks(lista);
    writeFile(lista);
    return;
}

int pesquisaTabRes(char *input) {
    int i = 0;
    int j = strlen(strArr1);
    while (i < 33) {
        if (!strcmp(input, strArr1[i])) {
            return i;
        }
        i++;
    }
    return -1;
}

void writeFile(ListaWorks *li) {
    FILE *ptr;
    ptr = fopen("../output.txt", "w+");
    if (ptr == NULL) { //Verifica erro na abertura de arquivo.
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    char *str;
    Elem *no = *li;
    if (li == NULL)
        return;
    while (no != NULL) {
        str = (char *) malloc(sizeof strlen(no->dado.input) + sizeof strlen(no->dado.codigo) + 50);
        strcat(str, no->dado.input);
        strcat(str, ",");
        strcat(str, no->dado.codigo);
        strcat(str, "\n");
        fwrite(str, sizeof(char) * strlen(str), 1, ptr);
        no = no->prox;
    }
    fclose(ptr);
    return;
}