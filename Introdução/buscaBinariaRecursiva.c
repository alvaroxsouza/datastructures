#include <stdlib.h>
#include <stdio.h>

// Faz a mesma coisa que o iterativo(claro) e tem mesma complexidade
// Mas sempre opitar pelo algoritmo iterativo

int binarySearchRecursive(int v[], int k, int inicio, int fim){
    if(inicio > fim) return -1;
    int meio = (inicio + fim)/2;
    if(k == v[meio]) return meio;
    else if(k < v[meio]) return binarySearchRecursive(v, k, inicio , meio - 1);
    else return binarySearchRecursive(v, k, meio + 1 , fim);
}

int main(){
    int tamanho = 100000;
    int v[tamanho];
    int k; 
    int inicio = 0; 
    int fim = tamanho;
    for(int i = 0; i < tamanho; i++){
        v[i] = i;
    }
    printf("Digite um numero inteiro para ser buscado: ");
    scanf("%d", &k);
    int resultado = binarySearchRecursive(v, k, inicio, fim);
    if(resultado != -1){
        printf("\n\nO numero esta na posicao: %d\n\n", resultado);
        printf("\n\nNumero da posicao v[%d]: %d", k, v[k]);
    }
    else{
        printf("\n\nNao foi encontrado\n\n");
    }
    
}