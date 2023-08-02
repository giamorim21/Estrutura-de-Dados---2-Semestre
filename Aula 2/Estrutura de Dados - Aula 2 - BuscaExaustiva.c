#include <stdio.h>
#include <stdlib.h>

// Declaracao de variaveis //

int vetor[10000];
int i = 0;
int busca = 0;
int achei = 0;

// Funcao principal de execucao do programa //

int main(){
    // Inicializacao da memoria //
    for ( i = 0; i < 10000; i++){
        vetor[i] = (rand() % 10000);
    }

    // Perguntar o parametro de busca //
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &busca);

    // Busca propriamente dita //
    achei = -1; // Nao comecar no 0 poque o 0 eh a posicao 1 ( inicial )
    for (i = 0; i < 10000; i++){
        if (vetor[i] == busca){
            achei = i;
        }
    }

    if (achei == -1){
        printf("Se fodeu! Nao existe!");
    } else {
        printf("ACHEI PORRA!! Na posicao %d\n", achei);
    }
}
