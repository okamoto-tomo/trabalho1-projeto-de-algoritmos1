#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "danceteria.h"

using namespace std;

/* funções de fila_pessoa */
void init_fila_pessoa (tipo_fila_pessoa *fila_pessoa) {
    fila_pessoa->frente = new celula_pessoa;
    fila_pessoa->tras = fila_pessoa->frente;
    fila_pessoa->frente->proximo = NULL;
};

bool is_fila_pessoa_vazia (tipo_fila_pessoa *fila_pessoa) {
    return (fila_pessoa->frente == fila_pessoa->tras);
};

void enq_fila_pessoa (tipo_pessoa *pessoa, tipo_fila_pessoa *fila_pessoa) { 
    fila_pessoa->tras->proximo = new celula_pessoa;
    fila_pessoa->tras = fila_pessoa->tras->proximo;
    fila_pessoa->tras->pessoa = *pessoa;
    fila_pessoa->tras->proximo = NULL;
}; /* enq = enqueue, de enfileirar */

tipo_pessoa deq_fila_pessoa (tipo_fila_pessoa *fila_pessoa) {
    if (is_fila_pessoa_vazia(fila_pessoa)) {
        tipo_pessoa erro;
        erro.nome = "";
        erro.sexo = "";
        return erro;
    };
    celula_pessoa* primeiro = fila_pessoa->frente;
    fila_pessoa->frente = fila_pessoa->frente->proximo;
    delete primeiro;  // ← delete, not free
    return fila_pessoa->frente->pessoa;
}; /* deq = dequeue, de desenfileirar */



/* funções de lista_par */
void init_lista_par (tipo_lista_par *lista_par) {
    lista_par->frente = new celula_par;
    lista_par->tras = lista_par->frente;
    lista_par->frente->proximo = NULL;
};

bool is_lista_par_vazia (tipo_lista_par *lista_par) {
    return (lista_par->frente == lista_par->tras);
};

void add_lista_par (tipo_par *par, tipo_lista_par *lista_par) {
    lista_par->tras->proximo = new celula_par;
    lista_par->tras = lista_par->tras->proximo;
    lista_par->tras->par = *par;
    lista_par->tras->proximo = NULL;
};
