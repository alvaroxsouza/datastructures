#include <stdlib.h>
#include <stdio.h>

unsigned long int fatorial(unsigned long int n){
    if(n == 1 || n == 0){
        printf("\nx1");
        return 1;
    }
    else{
        printf("\nx");
        return n * fatorial(n - 1);
    }
}

int main(){
    unsigned long int n;
    printf("Digite um numero inteiro e positivo para saber o fatorial: ");
    scanf("%ld", &n);
    printf("\n%ld\n", fatorial(n));    
}