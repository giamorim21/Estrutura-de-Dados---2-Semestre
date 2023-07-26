// Programa de Inversao de Elementos  do Vetor //

#include <stdio.h>

// Declaracao de variaveis //

int vetorOriginal[10];
int vetorInvertido[10];
int i = 0;

// Funcao principal de execucao do programa //

int main() {
    // Limpeza da memoria
    for (i = 0; i< 10; i++) {
        vetorOriginal[i] = 0;
        vetorInvertido[i] = 0;
    }
    // Preenchimento do vetor
    for (i = 0; i < 10 ; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetorOriginal[i]);
    }

    // Inversao do vetor
    for (i = 9 ; i >= 0 ; i--) {
        vetorInvertido[9 - i] = vetorOriginal[i];
    }

    // Impressao dos vetores
    for (i = 0 ; i < 10 ; i++) {
        printf("vetorOriginal[%d] = %d\n", i, vetorOriginal[i]);
    }
    printf("\n");
    for (i = 0 ; i < 10 ; i++) {
        printf("vetorinvertido[%d] = %d\n", i , vetorInvertido[i] );
}
}
