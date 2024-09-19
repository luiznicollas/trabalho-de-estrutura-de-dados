#include <iostream>
#include <stdlib.h>
#include "pilhaFila.h"
using namespace std;

void criarFila(tipoFila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(tipoFila *fila) {
    return (fila->inicio == NULL);
}

void inserirFila(tipoFila *fila, int item) {
    celulaFila *novaCelula = (celulaFila *)malloc(sizeof(celulaFila));
    
    if (novaCelula == NULL) {
        cout<<"Erro ao alocar memória para a fila\n";
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

int removerFila(tipoFila *fila) {
    if (filaVazia(fila)) {
        cout<<"A fila está vazia\n";
    }
    
    celulaFila *temp = fila->inicio;
    int item = temp->item;
    fila->inicio = temp->proximo;
    
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(temp);
    
    return item;
}

void liberarFila(tipoFila *fila) {
    while (!filaVazia(fila)) {
        removerFila(fila);
    }
}


void criarPilha(tipoPilha *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(tipoPilha *pilha) {
    return (pilha->topo == NULL);
}

void empilhar(tipoPilha *pilha, int item) {
    celulaPilha *novaCelula = (celulaPilha *)malloc(sizeof(celulaPilha));
    if (novaCelula == NULL) {
        cout<<"Erro ao alocar memória para a pilha\n";
        return;
    }
    novaCelula->item = item;
    novaCelula->proximo = pilha->topo;
    pilha->topo = novaCelula;
}

int desempilhar(tipoPilha *pilha) {
    if (pilhaVazia(pilha)) {
        cout<<"Pilha vazia!\n";
    }
    celulaPilha *temp = pilha->topo;
    int item = temp->item;
    pilha->topo = temp->proximo;
    free(temp);
    return item;
}


void liberarPilha(tipoPilha *pilha) {
    while (!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }
}