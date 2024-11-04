/*Leia dois nomes e compare se os nomes são iguais. Se forem iguais imprima “São Iguais!”, senão
imprima “São Diferentes”.
OBSERVAÇÃO:
Faça usando:
char nome1[20];
char nome2[20];
USE A FUNÇÃO STRCMP () PARA COMPARAR AS STRINGS
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char nome1[20];
    char nome2[20];

    cout << "Digite o primeiro nome:" << endl;
    cin >> nome1;
    cout << "Digite o segundo nome: " << endl;
    cin >> nome2;

    // comparando as strings usando strcmp

    if(strcmp(nome1, nome2) == 0) {
        cout << "Os nomes são iguais!" << endl;
    } else {
        cout << "Os nomes são diferentes!" << endl;
    }

    return 0;

}