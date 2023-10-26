/// Programa que implementa um Grafo ///

#include <stdio.h>

/// Defini��o de constantes ///

const int TAMANHO = 5;

///  Fun��o que cria o grafo ///

void criar(int grafo[TAMANHO][TAMANHO]){
    /// Declara��o de vari�veis
    int i = 0;
    int j = 0;
    int amigo = 0;

    /// Inicia�iza��o do grafo
    for (i = 0; i < TAMANHO; i++){
        for (j = 0; j < TAMANHO; j++){
            grafo[i][j] = 0;
        }
    }

    /// Defini��o dos conex�es do grafo
    for (i = 0; i < (TAMANHO -1); i++){
        for (j = (i +1); j < TAMANHO; j++){
            printf("Digite <1> caso %d seja amigo de %d: ", i , j);
            scanf("%d", &amigo);

            grafo[i][j] = amigo;
            grafo[j][i] = amigo;
        }
    }
}

/// Fun��o que imprimi o grafo ///

void imprimir(int grafo[TAMANHO][TAMANHO]){
    /// Declara��o de vari�veis
    int i = 0;
    int j = 0;

    /// Impress�o propriamente dita
    for (i = 0; i < TAMANHO; i++){
        for (j = 0; j < TAMANHO; j++){
            printf("%d\t", grafo[i][j]);
        }
        printf("\n");
    }
}

/// Fun��o que descobre o v�rtice de meoir grau ///

int descobrirVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]){
    /// Declara��o de vari�veis
    int i = 0;
    int j = 0;
    int contador = 0;
    int maior = 0;
    int vertice = 0;

    /// Navega��o dp grafo ///
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

/// Fun��o principal de execu��o do programa ///

int main(){
    int grafo[TAMANHO][TAMANHO];

    criar(grafo);

    imprimir(grafo);

    printf("Vertice mais popular: %d\n", descobrirVerticeMaiorGrau(grafo));
}
