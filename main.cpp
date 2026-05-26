#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "danceteria.h"

using namespace std;

int controle;

tipo_lista_par pares;
tipo_fila_pessoa homens, mulheres;
tipo_pessoa pessoa;
tipo_par par;

celula_par *duo;
celula_pessoa *man, *woman;

string nome, sexo;


int main() {
    init_lista_par(&pares);
    init_fila_pessoa(&homens);
    init_fila_pessoa(&mulheres);

    do {
        /* Menu do terminal */
        cout << "1. Adicionar uma pessoa.\n";
        cout << "2. Verificar a lista de pares e as filas.\n\n";
        cout << "0. Sair do programa.\n\n";
        cout << "> ";
        cin >> controle;

        switch (controle) {
            case 0: {
                break;
            }

            case 1: {
                cout << "\nDigite o nome da pessoa: ";
                cin >> nome;

                do {
                    cout << "Digite o sexo da pessoa: ";
                    cin >> sexo;
                } while ((sexo != "H") && (sexo != "h") && (sexo != "M") && (sexo != "m"));

                if (sexo == "h") {sexo = "H";};
                if (sexo == "m") {sexo = "M";};

                pessoa.nome = nome;
                pessoa.sexo = sexo;
                
                if (pessoa.sexo == "H") {enq_fila_pessoa(&pessoa, &homens);};
                if (pessoa.sexo == "M") {enq_fila_pessoa(&pessoa, &mulheres);};

                if (!(is_fila_pessoa_vazia(&homens)) && !(is_fila_pessoa_vazia(&mulheres))) {
                    par.homem = deq_fila_pessoa(&homens);
                    par.mulher = deq_fila_pessoa(&mulheres);
                    add_lista_par(&par, &pares);
                };

                cout << endl;

                break;
            }

            case 2: {
                /* pares */
                cout << "Lista de pares: ";

                if (!is_lista_par_vazia(&pares)) {
                    duo = pares.frente->proximo;
                    do {
                        cout << "Par: " << duo->par.homem.nome << " e " << duo->par.mulher.nome << " | ";
                        duo = duo->proximo;
                    } while (duo != NULL);
                    cout << "\n";
                }
                else {cout << "vazia." << endl;};

                /* homens */
                cout << "Lista de homens: ";

                if (!is_fila_pessoa_vazia(&homens)) {
                    man = homens.frente->proximo;
                    do {
                        cout << "Homem: " << man->pessoa.nome << " | ";
                        man = man->proximo;
                    } while (man != NULL);
                    cout << "\n";
                }
                else {cout << "vazia." << endl;};

                /* mulheres */
                cout << "Lista de mulheres: ";

                if (!is_fila_pessoa_vazia(&mulheres)) {
                    woman = mulheres.frente->proximo;
                    do {
                        cout << "Mulher: " << woman->pessoa.nome << " | ";
                        woman = woman->proximo;
                    } while (woman != NULL);
                    cout << "\n";
                }
                else {cout << "vazia." << endl;};

                cout << endl;

                break;
            }

            default: {
                cout << "Tente novamente.";

                cout << endl;

                break;
            };
        };
    } while (controle != 0);
};