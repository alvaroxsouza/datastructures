#include <stdlib.h>
#include <stdio.h>
#define num 10

int main(){
    int v[num]; // declarando um vetor

    for(int i = 0; i < num; i++){
        v[i] = 1000 + i; // atribuindo valor a cada elemento do vetor
    }

    for(int i = 0; i < num; i++){
        // Pega o endereço e referencia do ponto inicial 
        printf("%d\n", *(v+i)); // forma alternativa de acessar os elementos de um vetor
    }

    printf("\n\n");
    
    for(int i = 0; i < num; i++){
        printf("%p\n", &v+i); // forma de ver os endereços de memória em que cada elemento do vetor está
    }
}