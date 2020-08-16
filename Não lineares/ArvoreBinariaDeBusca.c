// By Álvaro Souza Oliveira 21/07/2020
// Estudando Estruturas de dados :D

#include <stdlib.h>
#include <stdio.h>

typedef struct no no;
typedef struct tree tr;

struct no{
    int id;
    float value;
    no* left;
    no* right;
};

struct tree{
    no* root;
    int amount;
};

// Inicializa Nó de Árvore
no* createNode(int id, float value){
    no* x = (no*)malloc(sizeof(no));
    x->id = id;
    x->value = value;
    x->right = NULL;
    x->left = NULL;
    return x;
}

// Inicializa Árvore
tr* createTree(){
    tr* t = (tr*)malloc(sizeof(tr));
    t->root = NULL;
    t->amount = 0;
    return t;
}

// Retorna o ID do Nó
int idClient(no* x){
    if(x == NULL){
        return 0;
    }
    return x->id;
}

// Retorna o valor do campo Value do Nó
float valueClient(no* x){
    if(x == NULL){
        return 0;
    }
    return x->value;
}

// Retorna a Raiz da Árvore
no* root(tr* t){
    return t->root;
}

// Retorna o nó sucessor
no* successor(no* x){
    if(x->left == NULL && x->right == NULL){
        return NULL;
    }
    no* aux = x->right;
    while(aux->right != NULL){
        aux = aux->left;
    }
    return aux;
}

// Retorna o Nó antecessor
no* predecessor(no* x){
    if(x->left == NULL && x->right == NULL){
        return NULL;
    }
    no* aux = x->left;
    while(aux->right != NULL){
        aux = aux->right;
    }
    return aux;
}

// Verifica se a Árvore está vazia
int empty(tr* t){
    if(t->root == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Faz a operação de Busca de um Nó da Árvore 
no* search(tr* t, int id){
    if(empty(t) == 1){
        printf("\nArvore Vazia: UNDERFLOW");
        return NULL;
    }
    else{
        no* root = t->root;
        while(root != NULL){
            if(id < root->id){
                root = root->left;
            }
            else if(id > root->id){
                root = root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
    }
}

// Insere um Nó na Árvore
void insertTree(tr* t, no* x){
    if(empty(t) == 1){
        t->root = x;
        t->amount++;
    }
    else{
        no* root = t->root;
        while(root != NULL){
            if(x->id < root->id){
                if(root->left == NULL){
                    root->left = x;
                    t->amount++;
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else if(x->id > root->id){
                if(root->right == NULL){
                    root->right = x;
                    t->amount++;
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
    }
}

// Remove e libera um Nó da Árvore
no* removeTree(no* x, int id){
    if(x == NULL) return NULL;
    else if(id < x->id) x->left = removeTree(x->left, id);
    else if(id > x->id) x->right = removeTree(x->right, id);
    else if(id == x->id){
        if(x->left == NULL && x->right == NULL){
            free(x);
            x = NULL;
        }
        else if(x->right == NULL){
            no* aux = x;
            x = x->left;
            free(aux);
        }
        else if(x->left == NULL){
            no* aux = x;
            x = x->right;
            free(aux);
        }
        else{
            no* y = x->left;
            while(y->right != NULL){
                y = y->right;
            }
            x->id = y->id;
            y->id = id;
            x->left = removeTree(x->left, id);
        }
    }
    return x;
}

// Imprime Árvore em ordem crescente
no* print(no* x){
    if(x == NULL){
        return NULL;
    }
    else{
        print(x->left);
        printf("\nID: %d|Valor: %.2f", x->id, x->value);
        print(x->right);
    }
}

// Libera os Nós da Árvore
void freeMemoryNode(no* x){
    if(x != NULL){
        freeMemoryNode(x->left);
        freeMemoryNode(x->right);
        free(x);
    }
}

// Libera a Árvore
void freeMemoryTree(tr* t){
    free(t);
}

int main(){
    int n = 0;
    tr* newTree = createTree();
    printf("\nQuantidade de Nos a serem alocados: ");
    scanf("%d", &n);
    printf("\n----------------------------------");
    for(int i = 0; i < n; i++){
        int id = 0;
        float value = 0;
        printf("\nDigite o ID do No: ");
        scanf("%d", &id);
        printf("\nDigite o valor do No: ");
        scanf("%f", &value);
        no* newNode = createNode(id, value);
        insertTree(newTree,newNode);
    }
    printf("\n");
    print(newTree->root);
    printf("\n");
    freeMemoryNode(newTree->root);
    freeMemoryTree(newTree);
    printf("\n");
}