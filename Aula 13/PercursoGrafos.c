/// Programa que implementa um percurso em grafos ///

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/// Declaração de constantes ///

const int TAMANHO = 5;

/// Função que cria o grafo ///

void criar(int grafo[TAMANHO][TAMANHO], int aleatorio){
    int aresta = 0;

    ///Inicialização do grafo ///
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            grafo[i][j] = 0;
        }
    }

    /// Preenchimento do grafo ///
    for (int i = 0; i < (TAMANHO - 1); i++){
        for (int j = (i + 1); j < TAMANHO; j++){
            if (aleatorio){
                aresta = (rand() % 2);
            } else {
                printf("Digite <1> se %d tem aresta com %d: ",i,j);
                scanf("%d", &aresta);
            }

            grafo[i][j] = aresta;
            grafo[j][i] = aresta;
        }
    }
}

/// Função recursiva que

int procurarPercursoRecursivo(int grafo[TAMANHO][TAMANHO], int visitado[TAMANHO], int inicio, int fim){
    int vizinho = 0;
    int retorno = 0;

    if (inicio == fim){
        retorno = 1;
    } else {
        visitado[inicio] = 1;
        for (vizinho = 0; vizinho < TAMANHO; vizinho++){
            if ((grafo[inicio][vizinho]) && (!visitado[vizinho])){
                if (procurarPercursoRecursivo(grafo, visitado, vizinho, fim)){
                    retorno = 1;
                    printf("%d <- ", vizinho);
                    break;
                }
            }
        }
    }

    return retorno;
}

/// Função que executa a descoberta do caminho ///

int procurarPercurso(int grafo[TAMANHO][TAMANHO], int inicio, int fim){
    int visitado[TAMANHO];
    int encontrei = 0;

    for (int i = 0; i < TAMANHO; i++){
        visitado[i] = 0;
    }

    encontrei = procurarPercursoRecursivo(grafo, visitado, inicio, fim);
    printf("%d", inicio);

    return encontrei;
}

/// Função peincipal de execução do programa ///
int main(){
    int grafo[TAMANHO][TAMANHO];
    int inicio = 0;
    int fim = 0;

    criar(grafo, 0);

    printf("Digite o vertice inicial: ");
    scanf("%d", &inicio);

    printf("Digite o vertice final: ");
    scanf("%d", &fim);

    if (procurarPercurso(grafo, inicio, fim)){
        printf("\nHa um caminho!\n");
    } else {
        printf("NAO ha um caminho!\n");
    }

}
