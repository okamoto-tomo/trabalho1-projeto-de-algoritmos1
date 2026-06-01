#include <iostream>
#include <string>
#include "palindromo.h"
using namespace std;


// inicializa a pilha definindo o topo como NULL (pilha vazia)
void inicializa(Pilha* p) {
    p->topo = NULL;
}

// verifica se a pilha tá vazia
bool estaVazia(Pilha* p) {
    return p->topo == NULL;
}

// método de inserção : adiciona um caractere no topo da pilha
void empilhar(Pilha* p, char c) {
    No* novo = new No;     // coloca um novo nó na memória
    novo->caractere = c;   // guarda o caractere nele
    novo->proximo = p->topo; // o novo nó aponta para o antigo topo
    p->topo = novo;        // o topo da pilha passa a ser o novo nó
}

// método de Remoção : Remove um elemento do topo da pilha
void desempilhar(Pilha* p) {
    if (!estaVazia(p)) {
        No* aux = p->topo;   // guarda o endereço do topo atual
        p->topo = p->topo->proximo; // o topo avança para o próximo nó
        delete aux;          // libera a memória do nó removido
    }
}

// método que retorna o elemento no topo da pilha (sem remover)
char espiarTopo(Pilha* p) {
    if (!estaVazia(p)) {
        return p->topo->caractere;
    }
    return '\0'; // retorna caractere nulo se estiver vazia
}

// método para verificação da condição de palíndromo
bool ehPalindromo(string cadeia) {
    Pilha p;
    inicializa(&p);

    // 1 - passa todos os caracteres da string para a pilha
    for (char c : cadeia) {
        empilhar(&p, c);
    }

    // 2 - compara a string original com os elementos saindo da pilha (ordem inversa)
    for (char c : cadeia) {
        // se o caractere atual for diferente do topo, não é palíndromo
        if (c != espiarTopo(&p)) {
            // limpa o resto da pilha da memória antes de retornar Falso
            while (!estaVazia(&p)) {
                desempilhar(&p);
            }
            return false; 
        }
        desempilhar(&p); // move para o próximo elemento da pilha
    }

    return true; // se todas as letras baterem, retorna verdadeiro
}