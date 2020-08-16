#include <stdlib.h>
#include <stdio.h>

int main(){
    int pI = 2000;
    int *ponteiroInteiro = &pI; // Declarando um ponteiro int

    float flut;
    float *x = &flut; // declarando um ponteiro float

    printf("%p\n", &x); // mostrando o endereço de memória
    printf("%f\n", *x); // mostrando o valor contido no endereço de memória

    printf("%d\n", *ponteiroInteiro); // mostra o endereço de memória do ponteiro

    *ponteiroInteiro = 100; // Assim se atribui um valor (Lembrar do *)

    printf("%p\n", &ponteiroInteiro); // mostra o endereço de memória do ponteiro
    printf("%d\n", *ponteiroInteiro); // mostra o valor atribuido ao end de memória
}