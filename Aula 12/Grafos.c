/// Programa que implementa um Grafo ///

#include <stdio.h>

/// Definição de constantes ///

const int TAMANHO = 5;

///  Função que cria o grafo ///

void criar(int grafo[TAMANHO][TAMANHO]){
    /// Declaração de variáveis
    int i = 0;
    int j = 0;
    int amigo = 0;

    /// Iniciaçização do grafo
    for (i = 0; i < TAMANHO; i++){
        for (j = 0; j < TAMANHO; j++){
            grafo[i][j] = 0;
        }
    }

    /// Definição dos conexões do grafo
    for (i = 0; i < (TAMANHO -1); i++){
        for (j = (i +1); j < TAMANHO; j++){
            printf("Digite <1> caso %d seja amigo de %d: ", i , j);
            scanf("%d", &amigo);

            grafo[i][j] = amigo;
            grafo[j][i] = amigo;
        }
    }
}

/// Função que imprimi o grafo ///

void imprimir(int grafo[TAMANHO][TAMANHO]){
    /// Declaração de variáveis
    int i = 0;
    int j = 0;

    /// Impressão propriamente dita
    for (i = 0; i < TAMANHO; i++){
        for (j = 0; j < TAMANHO; j++){
            printf("%d\t", grafo[i][j]);
        }
        printf("\n");
    }
}

/// Função que descobre o vértice de meoir grau ///

int descobrirVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]){
    /// Declaração de variáveis
    int i = 0;
    int j = 0;
    int contador = 0;
    int maior = 0;
    int vertice = 0;

    /// Navegação dp grafo ///
    for (i = 0; i < TAMANHO; i++){
        contador = 0;
        for (j = 0; j < TAMANHO; j++){
            if (grafo[i][j]){
                contador++;
            }
        }
        if (contador > maior){
            maior = contador;
            vertice = i;
        }
    }
    /// Retorno
    return vertice;

}

/// Função principal de execução do programa ///

int main(){
    int grafo[TAMANHO][TAMANHO];

    criar(grafo);

    imprimir(grafo);

    printf("Vertice mais popular: %d\n", descobrirVerticeMaiorGrau(grafo));
}
