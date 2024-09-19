typedef struct celulaFila {
    int item;
    struct celulaFila *proximo;
} celulaFila;

typedef struct {
    celulaFila *inicio;
    celulaFila *fim;
} tipoFila;

typedef struct celulaPilha {
    int item;
    struct celulaPilha *proximo;
} celulaPilha;

typedef struct {
    celulaPilha *topo;
} tipoPilha;

void criarFila(tipoFila *fila);

int filaVazia(tipoFila *fila);

void inserirFila(tipoFila *fila, int item);

int removerFila(tipoFila *fila);

void liberarFila(tipoFila *fila);

void criarPilha(tipoPilha *pilha);

int pilhaVazia(tipoPilha *pilha);

void empilhar(tipoPilha *pilha, int item);

int desempilhar(tipoPilha *pilha);

void liberarPilha(tipoPilha *pilha);