//ALUNO: Jorge murillo Santa Rosa Araujo
//ALUNO: Luiz Nicollas De Melo Campos

#include <iostream>
#include <stdlib.h>
#include "pilhaFila.h"
using namespace std;

int main() {
    tipoFila filaPar, filaImpar;
    tipoPilha pilha;
    int numero;
    bool alternar = true;
    
    criarFila(&filaPar);
    criarFila(&filaImpar);
    criarPilha(&pilha); 

    cout << "Digite números inteiros (digite 0 para parar):" << endl;
    
    while (true) {
        cout<<"número: ";
        cin >> numero;
        
        if (numero == 0) break;
        
        if (numero % 2 == 0) {
            inserirFila(&filaPar, numero);
        }
        
        else {
            inserirFila(&filaImpar, numero);
        }
    }
    
    
    while (!filaVazia(&filaImpar) || !filaVazia(&filaPar)) {
        tipoFila* filaAtual;

        if (alternar) {
            filaAtual = &filaImpar;
        } 
        
        else {
            filaAtual = &filaPar;
        }
        
        if (!filaVazia(filaAtual)) {
            int valor = removerFila(filaAtual);
            
            if (valor > 0) {
                empilhar(&pilha, valor);
            }
            
            else if (valor < 0 && !pilhaVazia(&pilha)) {
                desempilhar(&pilha);
            }
        }
        alternar = !alternar; 
    }

    cout << "\nElementos na pilha:" << endl;
    
    while (!pilhaVazia(&pilha)) {
        cout << desempilhar(&pilha) << endl;
    }

    liberarFila(&filaPar);
    liberarFila(&filaImpar);
    liberarPilha(&pilha);

    return 0;
}