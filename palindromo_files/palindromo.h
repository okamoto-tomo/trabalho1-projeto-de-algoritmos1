#include <iostream>
#include <string>

using namespace std;

// definição da estrutura do Nó (Célula) da Pilha
struct No {
    char caractere;
    No* proximo;
};

// definição da estrutura da Pilha
struct Pilha {
    No* topo;
};


void inicializa(Pilha* p);
bool estaVazia(Pilha* p);
void empilhar(Pilha* p, char c);
void desempilhar(Pilha* p);
char espiarTopo(Pilha* p);
bool ehPalindromo(string cadeia);

