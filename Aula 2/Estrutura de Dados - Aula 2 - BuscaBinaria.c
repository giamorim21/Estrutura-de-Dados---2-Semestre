#include <stdio.h>

// Declaracao de variaveis //
// A Busca Binaria so funciona se a lista estiver ordenada //
// Sempre comeca no medio

int vetor[10000];
int i = 0;
int busca = 0;
int inicio = 0;
int meio = 0;
int fim = 0;

// Funcao principal de execucao do programa //

int main(){
    // Inicializacao da memoria
    for (i = 0; i < 10000; i++){
        vetor[i] = i;
    }

    // Perguntar o parametro de busca
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &busca);

    // Bisca propriamente dita
    inicio = 0;
    fim = 9999;
    while ( fim >= inicio){
        meio = (inicio + fim) / 2;

        if (busca == vetor[meio]){
            printf("ACHEI PORRA ! Na posicao %d\n", meio);
            return 0;
        } else if (busca > vetor[meio]){
            inicio = (meio + 1);
        } else {
            fim = (meio - 1);
        }
    }
    printf("Se fodeu! Nao existe!");

}


