#include <stdlib.h>
#include <stdio.h>

// define uma estrutura
struct nametype {
    char first[20];
    char mid;
    char last[20];
    int numb;
};

int main(){
    struct nametype sname; // cria variaveis do tipo struct
    sname.numb = 29;
    scanf("%s", sname.first);
    printf("%s\n", sname.first);
    scanf("%s", &sname.mid);
    printf("%c\n", sname.mid);
    scanf("%s", sname.last);
    printf("%s\n", sname.last);
    
    printf("%s %c. %s\n", sname.first, sname.mid, sname.last);
}