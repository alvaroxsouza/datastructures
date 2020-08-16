// By Álvaro Souza Oliveira 07/05/2020
// Estudando Estruturas de dados :D
// Renomeie as variáveis, fiz com sono

#include <stdio.h>
#include <stdlib.h>

typedef struct stack s;
typedef struct no no;

struct stack{
    no* top;
    int size;
};

struct no{
    int id;
    float valor;
    no* next;
};


// Cria e inicializa um Nó
no* createNode(int id, float valor){
    no* newNode = (no*)malloc(sizeof(no));
    newNode->id = id;
    newNode->valor = valor;
    newNode->next = NULL;
    return newNode;
}

// Cria e inicializa a Pilha
s* createStack(){
    s* newStack = (s*)malloc(sizeof(s));
    newStack->size = 0;
    newStack->top = NULL;
    return newStack;    
}

// Retorna o tamanho da Pilha
int lenghtStack(s* st){
    return st->size;
}

// Diz se a Pilha está ou não vazia
int empty(s* st){
    if(st->size == 0||st->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Insere um Nó no topo da Pilha
void push(no* pushNode, s* st){
    pushNode->next = st->top;
    st->top = pushNode;
    st->size++;
}


// Remove o Nó do topo da Pilha
no* pop(s* st){
    if(empty(st) == 0){
        no* aux = st->top;
        st->top = aux->next;
        aux->next = NULL;
        st->size--;
        return aux;
    }
    else{
        printf("\nA pilha esta vazia");
    }
}

// Faz a Impressão resultante da pilha sem perder os Nós
void print(s* st){
    int lenght = lenghtStack(st);
    no* aux = st->top;
    printf("\n----IMPRIMINDO RESULTADO----");
    while(empty(st) != 1 && aux != NULL){
        printf("\nID: %d Valor: %.2f", aux->id, aux->valor);
        aux = aux->next;
    }
    printf("\n");
}

// Libera a memória dos Nós e da Pilha alocados
void desalocarPilha(s* st){
    while(empty(st) != 1){
        free(pop(st));
    }
    free(st);
}

int main(){
    int qntContas;
    printf("\n........Cash........");
    printf("\nInforme a quantidade de contas: ");
    scanf("%d", &qntContas);
    s* newStack = createStack();
    for(int i = 0; i < qntContas; i++){
        int id = i+1;
        float valor;
        printf("\nInforme o valor definido para esta conta: ");
        scanf("%f", &valor);
        no* newNode = createNode(id, valor);
        push(newNode, newStack);
    }
    
    print(newStack);
    desalocarPilha(newStack);
}