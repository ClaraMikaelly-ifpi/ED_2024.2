#include <stdio.h>

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para realizar o selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i; //Assume que o menor valor está na posição i.
        for (int j = i+1; j < n; j++) { //Laço interno para encontrar o menor elemento na parte não ordenada do array.
            if (arr[j] < arr[min_idx]) { // Compara o elemento atual arr[j] com o menor elemento arr[min_idx].
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]); //Troca o menor elemento encontrado com o primeiro elemento não ordenado.
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    selectionSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
