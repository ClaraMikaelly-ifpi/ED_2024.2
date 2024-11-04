/*Leia dois nomes e compare se os nomes são iguais. Se forem iguais imprima “São Iguais!”, senão
imprima “São Diferentes”.
OBSERVAÇÃO:
Faça usando:
char nome1[20];
char nome2[20];
UTILIZE O COMANDO DE REPETIÇÃO “FOR” PARA PERCORRER AS
STRINGS CARACTERE A CARACTERE E FAZER A COMPARAÇÃO ENTRE
ELAS.*/

#include <iostream>

using namespace std;

int main() {
    char nome1[20];
    char nome2[20];

    cout << "Digite o primeiro nome:" << endl;
    cin >> nome1;

    cout << "Digite o segundo nome:" << endl;
    cin >> nome2;

    bool iguais = true; //assume que são iguais até provar o contrario

    // comparação caractere por caractere
    for (int i = 0; nome1[i] != '\0' || nome2[i] != '\0'; i++) {
        if (nome1[i] != nome2[i]){
            iguais = false;
            break;
        }
    }

    //verificar o resultado
    if (iguais) {
        cout << "São iguais!" << endl;
    } else {
        cout << "São diferentes!" << endl;
    }

    return 0;

}