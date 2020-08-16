#include <stdlib.h>
#include <stdio.h>

// define uma union
// Super semelhante à struct
union uniao{ 
    int numero;
    float pi;
    char nome[20];
};

// No final das contas serve para fazer uma espécie de organização com possíveis variáveis
// E fazer o uso destas, um por vez, promovendo o gerenciamento da memória do programa

int main(){
    union uniao test; // forma de criar uma instancia da union
    /* test.numero = 10; */
    test.pi = 3.14;
    /* scanf("%s", test.nome); */
    printf("%d\n", test.numero);
    printf("%f\n", test.pi);
    printf("%s\n", test.nome);
}