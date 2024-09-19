#include <iostream>

using namespace std;

typedef struct {
    string nome;
    int numero;
} tipoItem;

typedef struct celula {
    tipoItem item;
    struct celula *proximo;
} celula;

typedef struct {
    celula *inicio;
    celula *fim;
} tipoFila;


void criarFila(tipoFila *fila);

int filaVazia(tipoFila *fila);

void inserirFila(tipoFila *fila, tipoItem item);

tipoItem removerFila(tipoFila *fila);

void exibirFila(tipoFila *fila);

int numeroItensFila(tipoFila *fila);

void exibirPrimeiroFila(tipoFila *fila);

void liberarFila(tipoFila *fila);