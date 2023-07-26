#include <stdio.h>

// Declaracao de variaveis //

int vetor[10];
int i = 0;

// Função principal de execucao do programa //

int main () {
    // Inicializacao da memoria
    for (i = 0; i < 10; i++) {
        vetor[i] = 0;
    }

    // Preenchimento do vetor
    for (i = 0 ; i < 10 ; i++) {
        printf("Digite o valor da posicao %d:", i);
        scanf("%d", &vetor[i]);
    }

    // Impresso do vetor
    for (i = 0 ; i < 10 ; i++) {
        printf("vetor[%d] = %d\n", i , vetor[i]);
    }
}
