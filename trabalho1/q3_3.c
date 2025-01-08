#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAM 100 // Tamanho máximo da pilha

typedef char Item; // Tipo de dado armazenado na pilha

typedef struct {
    int topo;
    int max;
    Item *item;
} Pilha;

Pilha *cria_pilha(int m) {
    Pilha *P = (Pilha *)malloc(sizeof(Pilha));
    if (P == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
    P->max = m;
    P->topo = -1;
    P->item = (Item *)malloc(m * sizeof(Item));
    if (P->item == NULL) {
        printf("Erro ao alocar memória para os elementos da pilha.\n");
        free(P);
        exit(1);
    }
    return P;
}

void destroi_pilha(Pilha *P) {
    free(P->item);
    free(P);
}

int vazia(Pilha *P) {
    return (P->topo == -1);
}

void empilha(Pilha *P, Item x) {
    if (P->topo == P->max - 1) {
        printf("Pilha cheia.\n");
        return;
    }
    P->topo++;
    P->item[P->topo] = x;
}

Item desempilha(Pilha *P) {
    if (vazia(P)) {
        puts("Pilha vazia!");
        abort();
    }
    return P->item[P->topo--];
}

Item topo(Pilha *P) {
    if (vazia(P)) {
        puts("Pilha vazia!");
        abort();
    }
    return P->item[P->topo];
}

int prio(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0; // Menor prioridade para controlar os parênteses
        default:
            return -1; // Operador inválido
    }
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha *P = cria_pilha(256); // Cria pilha 

    for (int i = 0; e[i] != '\0'; i++) {
        if (isalpha(e[i])) {
            s[j++] = e[i];
        } else if (strchr("+-*/^", e[i])) {
            while (!vazia(P) && prio(topo(P)) >= prio(e[i])) {
                s[j++] = desempilha(P);
            }
            empilha(P, e[i]);
        } else if (e[i] == '(') {
            empilha(P, e[i]);
        } else if (e[i] == ')') {
            while (!vazia(P) && topo(P) != '(') {
                s[j++] = desempilha(P);
            }
            desempilha(P); // Descarta o '('
        }
    }

    while (!vazia(P)) {
        s[j++] = desempilha(P);
    }

    s[j] = '\0';
    destroi_pilha(P);
    return s;
}

int main() {
    char expr[100];

    printf("Digite a expressao infixa: ");
    fgets(expr, sizeof(expr), stdin);

    char *posfixa_expr = posfixa(expr);

    printf("Expressao pos-fixa: %s\n", posfixa_expr);

    // Liberar a memória alocada para a expressão pós-fixa
    free(posfixa_expr);
    
    return 0;
}