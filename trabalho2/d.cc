#include <stdio.h>
#include <stdbool.h>


// Verificação de A é um subconjunto de B.
bool verificar_subconjunto(
    int A[],
    int tamanho_a,
    int B[],
    int tamanho_b
)
{
    int i = 0, j = 0;

    while (i < tamanho_a && j < tamanho_b)
    {
        if (A[i] < B[j])
        {
            return false;  
        }
        else if (A[i] == B[j])
        {
            i++;  
        }
        j++;  
    }

    return (i == tamanho_a); 
}