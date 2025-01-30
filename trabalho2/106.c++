#include <stdio.h>
#include <stdlib.h>


/* 10.6 A função recursiva exibep (), definida na Figura 10.11, exibe o polinómio P(x)=4x-2x como +4.0*x^3-2.0*x^1.
 Crie uma versão iterativa dessa função, que não mostra o ex- poente 1, isto é, que exibe +4.0*x^3-2.0*x
*/

// Definição da estrutura Poli
typedef struct poli {
    float coef; // armazena o coeficiente do termo do polinômio
    int expo; // armazena o expoente do termo do polinômio
    struct poli *prox; // ponteiro para o próximo termo do polinômio
} Poli;

// Função para criar um novo termo no polinômio
Poli *termo(float c, int e, Poli *p) {
    Poli *novo = (Poli *)malloc(sizeof(Poli)); // aloca memoria para um novo no da estrutura Poli e armazena o ponteiro em novo
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->coef = c; // atribui o coeficiente c ao campo coef do no
    novo->expo = e; // atribui o expoente e ao campo expo do no
    novo->prox = p; // atribui o ponteiro p ao campo prox do no
    return novo; // retorna o ponteiro para o novo no
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
