#include <stdio.h>

int buscaLinear(int arr[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == elemento) {
            return i;         // retorna o índice do elemento encontrado 
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int elemento = 10;
    int resultado = buscaLinear(arr, tamanho, elemento);
    if (resultado == -1) {
        printf("Elemento não encontrado\n");
    } else {
        printf("Elemento encontrado no índice %d\n", resultado);
    }
    return 0;
}
