//ALUNO: Jorge murillo Santa Rosa Araujo
//ALUNO: Luiz Nicollas De Melo Campos

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "filaAviao.h"
using namespace std;

int main() {
    tipoFila fila;
    int resposta;
    tipoItem item;
    string nome;
    
    criarFila(&fila);

    do {
        cout << "\nMenu:\n";
        cout << "1. Listar o número de aviões na fila\n";
        cout << "2. Adicionar avião na fila\n";
        cout << "3. Exibir o primeiro avião na fila\n";
        cout << "4. Exibir todos os aviões na fila\n";
        cout << "5. Autorizar decolagem do primeiro avião na fila\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> resposta;

        switch (resposta) {
            case 1:
                cout << "Aviões na fila: " << numeroItensFila(&fila) << endl;
                break;

            case 2:
                cout << "Digite o nome do avião: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o número de Id do avião: ";
                cin >> item.numero;
                item.nome = nome;
                inserirFila(&fila, item);
                cout<<"Avião adicionado com sucesso\n";
                break;

            case 3:
                exibirPrimeiroFila(&fila);
                break;

            case 4:
                cout << "Aviões na fila:\n";
                exibirFila(&fila);
                break;

            case 5:
                if (!filaVazia(&fila)) {
                    tipoItem itemRemovido = removerFila(&fila);
                    cout << "O avião: " << itemRemovido.nome << ", Id: " << itemRemovido.numero << ", decolocou" << endl;
                } else {
                    cout << "A fila está vazia" << endl;
                }
                break;

            case 6:
                cout << "Programa encerrado\n";
                liberarFila(&fila);
                break;

            default:
                cout << "Opção inválida\n";
        }
    } while (resposta != 6);

    return 0;
}
