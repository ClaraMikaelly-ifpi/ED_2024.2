#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Poli
typedef struct poli {
    float coef;
    int expo;
    struct poli *prox;
} Poli;

// Função para criar um novo termo no polinômio
Poli *termo(float c, int e, Poli *p) {
    Poli *novo = (Poli *)malloc(sizeof(Poli));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->coef = c;
    novo->expo = e;
    novo->prox = p;
    return novo;
}

// Função iterativa para exibir o polinômio
void exibep_iterative(Poli *P) {
    if (P == NULL) {
        printf("Polinômio nulo\n");
        return;
    }

    while (P != NULL) {
        printf("%+.1f", P->coef);
        if (P->expo != 0) {
            printf("*x");
            if (P->expo != 1) {
                printf("^%d", P->expo);
            }
        }
        if (P->prox != NULL) {
            printf(" + ");
        }
        P = P->prox;
    }
    printf("\n");
}

int main() {
    Poli *poli = NULL;
    poli = termo(1, 0, poli);
    poli = termo(2, 1, poli);
    poli = termo(3, 2, poli);

    exibep_iterative(poli);

    // Liberar a memória alocada
    Poli *temp;
    while (poli != NULL) {
        temp = poli;
        poli = poli->prox;
        free(temp);
    }

    return 0;
}
