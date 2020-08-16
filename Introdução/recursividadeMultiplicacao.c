#include <stdlib.h>
#include <stdio.h>

unsigned long int multiplicacao(unsigned long int a, unsigned long int b){
    unsigned long int resultado;
    if(b == 0){
        return b;
    }
    else{
        return a + multiplicacao(a, b - 1);
    }
}

int main(){
    unsigned long int a, b;
    printf("Digite dois numeros para serem multiplicados: ");
    scanf("%ld %ld", &a, &b);
    printf("\n%ld\n", multiplicacao(a, b));
}