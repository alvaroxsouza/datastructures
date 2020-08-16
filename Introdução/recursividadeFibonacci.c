#include <stdlib.h>
#include <stdio.h>

// Apesar de mais legível o algoritmo recursivo é muito redundante e custoso
// sendo o menos eficiente se comparado com o iterativo

unsigned long int fibonacci(unsigned long int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else{
        return fibonacci(n-1) + fibonacci(n - 2);
    }
}

int main(){
    unsigned long int n;
    printf("Digite um numero inteiro e positivo para saber qual o numero de Fibonacci: ");
    scanf("%ld", &n);
    printf("\n%ld\n", fibonacci(n));    
}