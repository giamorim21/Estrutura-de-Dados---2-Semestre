/// Programa que implementa uma árvore binária e suas respectivas navegação///

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Declaração de estruturas ///

struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

/// Função que insere um nó na árvore ///

struct no *inserir(struct no *raiz, int numero){
    if (raiz == NULL){
        raiz = (struct no *)malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> direita = NULL;
        raiz -> esquerda = NULL;
    } else {
        if ((rand() % 2) == 0){
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        } else {
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    return raiz;
};

/// Navegação em PRE-ORDEM ///

void navegarPreOrdem(struct no *raiz){
    if (raiz != NULL){
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    }
}

/// Navegação em EM-ORDEM ///

void navegarEmOrdem(struct no *raiz){
    if (raiz != NULL){
        navegarPreOrdem(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> direita);
    }
}

/// Navegação em POS-ORDEM ///

void navegarPosOrdem(struct no *raiz){
    if (raiz != NULL){
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
        printf("%d\t", raiz -> numero);
    }
}

/// Função principal de execução do programa ///

int main(){
    /// Declaração de variavéis ///
    struct no *raiz = NULL;

    /// Inicialização da aleatoriedade ///
    time_t t;
    srand((unsigned) time(&t));

    /// Preenchimento da árvore ///
    int i = 0;
    for (i = 0; i < 10; i++){
        raiz = inserir(raiz,i);
    }

    /// Navegação ///
    printf("\n==================================== PRE-ORDEM ====================================\n");
    navegarPreOrdem(raiz);

    printf("\n==================================== EM-ORDEM ====================================\n");
    navegarEmOrdem(raiz);

    printf("\n==================================== POS-ORDEM ====================================\n");
    navegarPosOrdem(raiz);
    printf("\n");
}
