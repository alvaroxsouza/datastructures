#include <stdlib.h>
#include <stdio.h>

typedef struct aluno no;
struct aluno{
    char nome[20];
    int idade;
    float nota;
};
int teste; // Váriaveis globais não inicializadas iniciam em 0
// Serve para criar uma estrutura de aluno
no* criarAluno(char nome[], int idade, float nota){
    no* aluno = (no*)malloc(sizeof(no)); // aloca dinamicamente cada nó
    sprintf(aluno->nome,"%s", nome);
    aluno->idade = idade;
    aluno->nota = nota;
    return aluno;
}

// Imprime as informações de entrada
void imprimirLista(no* v[], int quantidadeAlunos){
    // statics são acessadas somente dentro do escopo da função
    // Assim, mesmo que são variaveis que permanecem armazenadas até o fum da execução
    // Não podem ser acessadas fora do escopo da função de maneira nenhuma
    static int cont = 0; 
    printf("......................\n");
    printf("\nIMPRIMINDO A LISTA DE ALUNOS\n");
    for(int i = 0; i < quantidadeAlunos; i++){
        printf("Aluno %d:\n", i+1);
        printf("Nome: %s\n", v[i]->nome);
        printf("idade: %d\n", v[i]->idade);
        printf("nota: %.2f\n", v[i]->nota);
        printf("......................\n");
        cont++;
    }
    printf("Quantidade de impressões: %d", cont);
}

int main(){

    int quantidadeAlunos;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantidadeAlunos);
    printf("\n");
    
    no* v[quantidadeAlunos]; // cria um vetor estático de nós Aluno

    printf("......................\n");
    for(int i = 0; i < quantidadeAlunos; i++){
        char nome[20];
        int idade;
        float nota;

        printf("Digite o nome do aluno: ");
        scanf("%s", nome);
        fflush(stdin);

        printf("Digite a idade do aluno: ");
        scanf("%d", &idade);

        printf("Digite a nota do aluno: ");
        scanf("%f", &nota);

        v[i] = criarAluno(nome, idade, nota);
        printf("......................\n");
    }
    imprimirLista(v, quantidadeAlunos);
    printf("\n");
    printf("%d\n", teste);
}