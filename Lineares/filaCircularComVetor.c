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
    int tamanhoMax;
    int first, last;
    no** vetor;
};

// Cria e inicializa um nó
no* createNo(int id, float valor){
    no* aux = (no*)malloc(sizeof(no));
    if(aux != NULL){
        aux->id = id;
        aux->valor = valor;
        aux->next = NULL;
        return aux;
    }
    else{
        return NULL;
    }
}

// Cria e inicializa a fila
f* createQueue(int tamanhoMax){
    f* q = (f*)malloc(sizeof(f));
    if(q != NULL){
        q->first = 0;
        q->last = tamanhoMax - 1;
        q->tamanhoMax = tamanhoMax;
        q->vetor = (no**)malloc(tamanhoMax * sizeof(no*));
        q->size = 0;
        return q;
    }
    else{
        return NULL;
    }
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

// Verifica se a fila atingiu seu tamanho maximo ou não
int fullQueue(f* q){
    if(q->size == q->tamanhoMax){
        return 1;
    }
    else{
        return 0;
    }
}

// Insere um nó na fila
void insert(no* x, f* q){
    if(fullQueue(q) == 1){
        printf("\nA fila está cheia: OVERFLOW");
    }
    else{
        if(empty(q) == 1){
            q->last = (q->last + 1) % q->tamanhoMax;
            q->vetor[q->last] = x;
            q->vetor[q->last];
            q->size++;
        }
        else{
            int last = q->last;
            q->vetor[last]->next = x;
            q->last = (q->last + 1) % q->tamanhoMax;
            q->vetor[q->last] = x;
            q->vetor[q->last];
            q->size++;
        }
    }
}

// Remove um nó da lista
no* popQueue(f* q){
    if(empty(q) == 1){
        printf("\nA fila esta vazia: UNDERFLOW");
        return NULL;
    }
    else{
        int x = q->first;
        q->first = (q->first + 1) % q->tamanhoMax;
        q->size--;
        return q->vetor[x];
    }
}

// Retorna o tamanho da Fila
int sizeFila(f* q){
    return q->size;
}

// Imprime os dados da Fila
void print(f* q){
    printf("\n\nIMPRIMINDO");
    no* aux = q->vetor[q->first];
    while(aux != NULL){
        printf("\n\nID: %d | Valor: %.2f", aux->id, aux->valor);
        aux = aux->next;
    }
    printf("\n\n");
}

// Libera a memória dos Nós e da Fila, alocados
void destroy(f* q){
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
    destroy(q);
}