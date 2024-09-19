#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "filaAviao.h"
using namespace std;

void criarFila(tipoFila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}


int filaVazia(tipoFila *fila) {
    return (fila->inicio == NULL);
}


void inserirFila(tipoFila *fila, tipoItem item) {
    celula *novaCelula = (celula *)malloc(sizeof(celula));
    
    if (novaCelula == NULL) {
        cout << "Erro ao alocar memória\n";
        return;
    }
    
    novaCelula->item = item;
    novaCelula->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novaCelula;
    }
    
    else {
        fila->fim->proximo = novaCelula;
    }
    
    fila->fim = novaCelula;
}


tipoItem removerFila(tipoFila *fila) {
    if (filaVazia(fila)) {
        cout << "A fila está vazia\n";
    }

    celula *temp = fila->inicio;
    tipoItem item = temp->item;
    fila->inicio = fila->inicio->proximo;
    
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    
    return item;
}


void exibirFila(tipoFila *fila) {
    if (filaVazia(fila)) {
        cout << "A fila está vazia" << endl;
        return;
    }

    celula *atual = fila->inicio;
    while (atual != NULL) {
        cout << "Nome: " << atual->item.nome << ", Id: " << atual->item.numero << endl;
        atual = atual->proximo;
    }
}


int numeroItensFila(tipoFila *fila) {
    int contagem = 0;
    celula *atual = fila->inicio;
    while (atual != NULL) {
        contagem++;
        atual = atual->proximo;
    }
    return contagem;
}


void exibirPrimeiroFila(tipoFila *fila) {
    if (filaVazia(fila)) {
        cout << "A fila está vazia\n";
        return;
    }
    cout << "Primeiro na fila: "<< "Nome: " << fila->inicio->item.nome << ", Id: " << fila->inicio->item.numero << endl;
}


void liberarFila(tipoFila *fila) {
    while (!filaVazia(fila)) {
        removerFila(fila);
    }
}
