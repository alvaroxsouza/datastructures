#include <stdlib.h>
#include <stdio.h>

// Ótimo algoritmo de busca tendo tempo= O(log n)

int binarySearch(int v[], int tamanho, int k){
    int inicio, fim;
    // base para a primeira busca
    inicio = 0;
    fim = tamanho - 1;
    //////////////////////////////
    int meio;
    while(inicio <= fim){
        // a cada loop o meio é ajustado
        meio = (inicio + fim) / 2;
        ///////////////////////////////

        // Caso o meio ajustado seja aquele que esta procurando ele retornará
        // a posição do vetor
        if(k == v[meio]){
            return meio;
        }
        // Caso contrário, verificará se a chave K é menor ou maior do que o valor "meio"/
        //////////////////////////////////////////////////////////////////////////////////

        // Caso a chave seja menor que o meio, o fim será redefinido para uma posição
        // anterior ao mesmo
        if(k < v[meio]){
            fim = meio - 1;
        }
        // Caso a chave seja maior que o meio, o inicio será redefinido para uma posição
        // posterior ao mesmo
        else{
            inicio = meio + 1;
        }
    }
    return -1;
}

int main(){
    int tamanho = 100000;
    int v[tamanho];
    int n;
    for(int i = 0; i < tamanho; i++){
        v[i] = i + 2 * 3;
    }
    printf("Digite um numero inteiro para ser buscado: ");
    scanf("%d", &n);
    int resultado = binarySearch(v, tamanho, n);
    if(resultado != -1){
        printf("\n\nO numero esta na posicao: %d\n\n", resultado);
    }
    else
    {
        printf("\n\nNao foi encontrado\n\n");
    }
    
}