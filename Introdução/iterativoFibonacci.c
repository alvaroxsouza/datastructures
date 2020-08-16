#include <stdlib.h>
#include <stdio.h>

// O algoritmo iterativo é muito mais eficiente do que o recursivo apesar
// de ser menos legível

unsigned long int fibonacci(unsigned long int n){
    unsigned long int penultimo = 1, ultimo = 1;
    if(n == 1) return penultimo;
    else if(n == 2) return ultimo;
    else{
        unsigned long int atual;
        for(int i = 2; i <= n; i++){
            atual = ultimo + penultimo;
            penultimo = ultimo;
            ultimo = atual;
        }
        return atual;
    }
}

int main(){
    unsigned long int n;
    printf("Digite um numero inteiro e positivo para saber qual o numero de Fibonacci: ");
    scanf("%ld", &n);
    printf("\n%ld\n", fibonacci(n));    
}