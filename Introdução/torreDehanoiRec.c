#include <stdlib.h>
#include <stdio.h>
int ac = 0;
void towerOfHanoi(int n, char origem, char destino, char aux){
    ac++;
    if(n == 1){
        printf("\nMover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    towerOfHanoi(n-1, origem, aux, destino);
    printf("\nMover disco %d de %c para %c.\n", n, origem, destino);  
    towerOfHanoi(n-1, aux, destino, origem);
}

int main(){
    int n; // numero de discos

    printf("Digite a quantidade de discos: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n\n%d\n", ac);
}
