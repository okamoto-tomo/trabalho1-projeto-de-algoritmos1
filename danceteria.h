#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct tipo_pessoa {
    string nome;
    string sexo;
} tipo_pessoa;

typedef struct tipo_par {
    tipo_pessoa homem;
    tipo_pessoa mulher;
} tipo_par;

/* fila de pessoas */
typedef struct celula_pessoa {
    tipo_pessoa pessoa;
    struct celula_pessoa *proximo;
} celula_pessoa;

typedef struct tipo_fila_pessoa {
    celula_pessoa *frente, *tras;
} tipo_fila_pessoa;

/* lista de pares */
typedef struct celula_par {
    tipo_par par;
    struct celula_par *proximo;
} celula_par;

typedef struct tipo_lista_par {
    celula_par *frente, *tras;
} tipo_lista_par;



/* funções */
void init_fila_pessoa (tipo_fila_pessoa *fila_pessoa);

bool is_fila_pessoa_vazia (tipo_fila_pessoa *fila_pessoa);

void enq_fila_pessoa (tipo_pessoa *pessoa, tipo_fila_pessoa *fila_pessoa); /* enq = enqueue, de enfileirar */

tipo_pessoa deq_fila_pessoa (tipo_fila_pessoa *fila_pessoa); /* deq = dequeue, de desenfileirar */

void init_lista_par (tipo_lista_par *lista_par);

bool is_lista_par_vazia (tipo_lista_par *lista_par);

void add_lista_par (tipo_par *par, tipo_lista_par *lista_par);