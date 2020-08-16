#include <stdlib.h>
#include <stdio.h>

void func(int *px){ // Aqui vemos que o valor é passado por referência
    ++(*px); // Aqui o valor é incrementado, sobre o endereço de memória da variável
    printf("%d\n", *px); // Mostra o valor ja incrementado
}

int main(){
    int aux = 5; // Valor a ser atribuido ao ponteiro
    int *x = &aux;

    printf("%d\n", *x); // Valor esperado é 5
    func(x); // chama a função para incremetar sobre o valor atribuido ao ponteiro
    
    // Valor esperado é 6, incrementado por uma função através de passagem por referência
    printf("%d\n", *x); 
}