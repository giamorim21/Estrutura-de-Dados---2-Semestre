#include<stdio.h>
#include <stdlib.h>  // Biblioteca usanda para puxar a a funcao 'rand' -> gerar numeros aleatorios

// Declaracao de variaveis //

int vetor[10000];
int i = 0;
int j = 0;

// Funcao principal de execucao do programa //

int main(){
    // Inicializacao da memoria //
    for (i = 0; i < 10000; i++){
        vetor[i] = (rand() % 10000);
    }

    // Ordenacao propriamente dita //
    for (i = 0; i < 9999; i++){  // Do primeiro ao penultimo porque o ultimo nao sera comparado com ninguem
        for (j = (i + 1); j < 10000; j++){ // Do proximo ao ultimo
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i]; // para trocar dois valores necessario a criacao de uma varaiavel temporaria
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    // Impressao do vetor //
    for (i = 0; i < 10000; i++){
        printf("%d\n", vetor[i]);
    }
}
