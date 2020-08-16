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
    no* previous;
};


// Cria e inicializa um Nó
no* createNode(int id, float valor){
    no* newNode = (no*)malloc(sizeof(no));
    newNode->id = id;
    newNode->valor = valor;
    newNode->next = NULL;
    newNode->previous = NULL;
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
no* searchList(l* lt, no* x){
    no* aux = lt->first;
    while(aux != NULL){
        if(aux->id == x->id){
            return aux;
        }
        aux = aux->next;
        if(aux->id == lt->first->id){
            break;
        }
    }
    return NULL;
}

// Insere um Nó na Lista (no fim)
no* push(l* lt, no* x){
    if(empty(lt) == 1){
        lt->first = x;
        lt->first->next = x;
        lt->first->previous = x;
        lt->lenthg++;
    }
    else{
        no* aux = lt->first;
        if(aux->next->id == lt->first->id){
            x->next = lt->first;
            x->previous = lt->first;
            lt->first->next = x;
            lt->first->previous = x;
            lt->lenthg++;
        }
        else{
            while(1==1){
                if(aux->next->id == lt->first->id){
                    x->next = lt->first;
                    x->previous = aux;
                    aux->next = x;
                    lt->first->previous = x;
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
        if(searchList(lt, x) == NULL){
            printf("\nNao Existe");
            return NULL;
        }
        else{

            if(lt->lenthg == 1){
                no* aux = lt->first;
                lt->lenthg--;
                return aux;
            }
            if(lt->first->id == x->id){
                no* y = lt->first;
                lt->first->next->previous = lt->first->previous;
                lt->first->previous->next = lt->first->next;
                lt->first = lt->first->next;
                lt->lenthg--;
                return y;
            }
            else{
                no* aux = lt->first;
                no* aux2 = lt->first->next;
                while(aux2->id != lt->first->id){
                    if(aux->id == x->id){
                        no* y = aux;
                        aux->next->previous = aux->previous;
                        aux->previous->next = aux->next;
                        aux->next = aux;
                        aux->next = NULL;
                        lt->lenthg--;
                        return y;
                    }
                    aux = aux->next;
                    aux2 = aux;
                }
            }
        }
        return NULL;
    }
}
    

// Faz a Impressão resultante da Lista sem perder os Nós
// Ordem de Inserção
void print(l* lt){
    printf("\n----Saber o Valor do no----");
    if(empty(lt) == 1){
        printf("\nLista Vazia");
    }
    else{
        no* aux = lt->first;
        no* aux2 = lt->first->next;
        while(aux2->id != lt->first->id){
            printf("\nID: %d Valor: %.2f", aux->id, aux->valor);
            aux = aux->next;
            aux2 = aux;
        }
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