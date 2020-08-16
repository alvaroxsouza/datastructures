// By Álvaro Souza Oliveira 07/05/2020
// Estudando Estruturas de dados :D
// Renomeie as variáveis, fiz com sono

#include <stdio.h>
#include <stdlib.h>

typedef struct list l;
typedef struct no no;

struct list{
    no* first;
    int lenthg;
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

// Cria e inicializa a Lista
l* createList(){
    l* newList = (l*)malloc(sizeof(l));
    newList->lenthg = 0;
    newList->first = NULL;
    return newList;    
}

// Retorna o tamanho da Lista
int getLenghtList(l* lt){
    return lt->lenthg;
}

// Diz se a Lista está ou não vazia
int empty(l* lt){
    if(lt->lenthg == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// Procura um nó da lista e retorna-o
no* searchList(l* lt, int id){
    no* aux = lt->first;
    while(aux != NULL){
        if(aux->id == id){
            return aux;
        }
        aux = aux->next;
        if(aux == lt->first){
            break;
        }
    }
    return NULL;

}

// Insere um Nó na Lista
void push(l* lt, no* x){
    if(empty(lt) == 1){
        lt->first = x;
        lt->first->next = x;
        lt->lenthg++;
    }
    else{
        no* aux = lt->first;
        if(aux->next->id == lt->first->id){
            x->next = lt->first->next;
            lt->first->next = x;
            lt->lenthg++;
        }
        else{
            while(aux != NULL){
                if(aux->next->id == lt->first->id){
                    x->next = aux->next;
                    aux->next = x;
                    lt->lenthg++;
                    break;
                }
                aux = aux->next;
            }
        }
    }
}


// Remove o nó desejado, e retorna-o
no* pop(l* lt , no* x){
    if(empty(lt) == 1){
        printf("\nA lista esta vazia");
        return NULL;
    }
    else{
        // Se não encontrar
        if(searchList(lt, x->id) == NULL){
            return NULL;
        }
        else{
            if(lt->first->id == x->id){
                no* y = lt->first;
                lt->first = lt->first->next;
                lt->lenthg--;
                return y;
            }
            else{
                no* aux = lt->first;
                while(aux != NULL){
                    if(aux->id = x->id){
                        no* y = aux;
                        aux = aux->next;
                        lt->lenthg--;
                        return y;
                    }
                    aux = aux->next;
                }
            }
            return NULL;
        }
    }
}
    

// Faz a Impressão resultante da Lista sem perder os Nós
// Ordem de Inserção
void print(l* lt){
    printf("\n----Saber o Valor do no----");
    no* aux = lt->first;
    no* aux2 = lt->first->next;
    while(aux2->id != lt->first->id){
        printf("\nID: %d Valor: %.2f", aux->id, aux->valor);
        aux = aux->next;
        aux2 = aux;
    }
    printf("\n");
}

// Libera a memória dos Nós e da Lista alocados
void freeList(l* lt){
    printf("\n");
    while(empty(lt) != 1){
        free(pop(lt, lt->first));
    }
    free(lt);
}

int main(){
    int qntContas;
    printf("\n........Cash........");
    printf("\nInforme a quantidade de contas: ");
    scanf("%d", &qntContas);
    l* newList = createList();
    no* previous = NULL;
    for(int i = 0; i < qntContas; i++){
        int id;
        float valor;
        printf("\nInforme o id: ");
        scanf("%d", &id);
        printf("\nInforme o valor definido para esta conta: ");
        scanf("%f", &valor);
        no* newNode = createNode(id, valor);
        push(newList, newNode);
    }
    print(newList);
    freeList(newList);
}