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
    no* prox;
};

struct fila{
    int tamanhoDaFila;
    int quantidade;
    int inicio, fim;
    no** vetor;
};

// Função que inicializa um nó
no* createNo(int id, float valor){
    no* x = (no*)malloc(sizeof(no));
    if(x != NULL){
        x->id = id;
        x->valor = valor;
        x->prox = NULL;
        return x;
    }
    else{
        return NULL;
    }
}

// função criadora da fila com vetor
f* createQueue(int tamanhoDaFila){
    f* q = (f*)malloc(sizeof(f));
    if(q != NULL){
        q->tamanhoDaFila = tamanhoDaFila;
        q->inicio = 0;
        q->fim = -1; 
        q->quantidade = 0;
        q->vetor = (no**)malloc(tamanhoDaFila * sizeof(no*));
        if(q->vetor == NULL){
            return NULL;
        }
        else{
            return q;
        }
    }
    else{
        return NULL;
    }
}

// Função que verifica se a fila está cheia
int fullQueue(f* q){
    if(q->quantidade == q->tamanhoDaFila){
        return 1;
    }
    else{
        return 0;
    }
}

// Função que verifica se a fila está vazia
int empty(f* q){
    if(q->quantidade == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// Função que insere um elemento na fila
void insert(no* x, f* q){
    if(fullQueue(q) == 1){
        printf("\nA fila esta cheia: OVERFLOW");
    }
    else{
        if(empty(q) == 1){
            q->fim = ++q->fim;
            q->vetor[q->fim] = x;
            q->vetor[q->fim]->prox = NULL;
            q->quantidade++;
        }
        else{
            int last = q->fim;
            q->fim = ++q->fim;
            q->vetor[last]->prox = x; 
            q->vetor[q->fim] = x;
            q->quantidade++;
        }
    }
}

// Remove o primeiro elemento da fila e o retorna
no* popQueue(f* q){
    if(empty(q) == 1){
        printf("\nA fila esta vazia: UNDERFLOW");
        return NULL;
    }
    else{
        int inicio = q->inicio;
        q->inicio = q->inicio+1;
        q->quantidade--;
        return q->vetor[inicio];
    }
}

// retorna o tamanho da fila
int sizeFila(f* q){
    return q->quantidade;
}


// Função para Imprimir os dados e testar se a alocação funciona
void print(f* q){
    printf("\n\nIMPRIMINDO");
    no* aux = q->vetor[q->inicio];
    while(aux != NULL){
        printf("\n\nID: %d | Valor: %.2f", aux->id, aux->valor);
        aux = aux->prox;
    }
    printf("\n\n");
}

// libera a memória dos nós, vetor e da fila
void freeMemory(f* q){
    while(empty(q) != 1){
        no* aux = popQueue(q);
        free(aux);
    }
    free(q->vetor);
    free(q);
}

int main(){
    int n;
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);
    f* q = createQueue(n);
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
    freeMemory(q);
}