// By Álvaro Souza Oliveira 07/05/2020
// Estudando Estruturas de dados :D
// Renomeie as variáveis, fiz com sono

#include <stdio.h>
#include <stdlib.h>

typedef struct no no;
typedef struct fila f;

struct no{
    int id;
    float valor;
    no* next;
};

struct fila{
    int size;
    no* first, *last;
};

// Cria e inicializa No
no* createNo(int id, float valor){
    no* x = (no*)malloc(sizeof(no));
    x->id = id;
    x->valor = valor;
    x->next = NULL;
    return x;
}

// Cria e inicializa a Fila
f* createQueue(){
    f* q = (f*)malloc(sizeof(f));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

// Verifica se a fila está vazia ou não
int empty(f* q){
    if(q->size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// Isere um nó no final da Fila
void insert(no* x, f* q){
    if(empty(q) == 1){
        q->first = x;
        q->last = x;
        q->size++;
    }
    else{
        no* aux = q->last;
        aux->next = x;
        q->last = aux->next;
        q->size++;
    }
}

// Remove um nó do início da fila e retorna-o
no* popQueue(f* q){
    if(empty(q) == 1){
        printf("\nUnderflow");
        return NULL;
    }
    else{
        no* aux = q->first;
        q->first = q->first->next;
        q->size--;
        return aux;
    }
}

// Retorna o tamanho da Fila
int sizeFila(f* q){
    return q->size;
}

// Imprime os dados da Fila
void print(f* q){
    printf("\n\nIMPRIMINDO");
    int queueLenght = sizeFila(q);
    no* aux = q->first;
    while(aux != NULL && empty(q) != 1){
        printf("\n\nID: %d | Valor: %.2f", aux->id, aux->valor);
        aux = aux->next;
    }
    printf("\n\n");
}

// Libera memória dos Nós e da Fila alocados
void destroy(f* q){
    while(empty(q) != 1){
        free(popQueue(q));
    }
    free(q);
}

int main(){
    int n;
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);
    f* q = createQueue();
    for(int i = 0; i < n; i++){
        int id;
        float valor;
        printf("\nDigite o ID: ");
        scanf("%d", &id);
        printf("\nDigite o valor: ");
        scanf("%f", &valor);
        no* x = createNo(id, valor);
        insert(x, q);
    }
    print(q);
    destroy(q);
}