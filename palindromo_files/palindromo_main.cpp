#include <iostream>
#include <string>
#include "palindromo.h"
using namespace std;

int main() {
    string entrada;

    cout << "Digite uma palavra para verificar se e um palindromo: ";
    cin >> entrada;

    // faz a verificação e exibe o resultado 
    if (ehPalindromo(entrada)) {
        cout << "resultado: verdadeiro" << endl;
    } else {
        cout << "resultado: falso" << endl;
    }

    return 0;
}