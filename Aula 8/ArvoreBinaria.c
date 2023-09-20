/// Programa que implementa uma �rvore bin�ria e suas respectivas navega��o///

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Declara��o de estruturas ///

struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

/// Fun��o que insere um n� na �rvore ///

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

/// Navega��o em PRE-ORDEM ///

void navegarPreOrdem(struct no *raiz){
    if (raiz != NULL){
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    }
}

/// Navega��o em EM-ORDEM ///

void navegarEmOrdem(struct no *raiz){
    if (raiz != NULL){
        navegarPreOrdem(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> direita);
    }
}

/// Navega��o em POS-ORDEM ///

void navegarPosOrdem(struct no *raiz){
    if (raiz != NULL){
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
        printf("%d\t", raiz -> numero);
    }
}

/// Fun��o principal de execu��o do programa ///

int main(){
    /// Declara��o de variav�is ///
    struct no *raiz = NULL;

    /// Inicializa��o da aleatoriedade ///
    time_t t;
    srand((unsigned) time(&t));

    /// Preenchimento da �rvore ///
    int i = 0;
    for (i = 0; i < 10; i++){
        raiz = inserir(raiz,i);
    }

    /// Navega��o ///
    printf("\n==================================== PRE-ORDEM ====================================\n");
    navegarPreOrdem(raiz);

    printf("\n==================================== EM-ORDEM ====================================\n");
    navegarEmOrdem(raiz);

    printf("\n==================================== POS-ORDEM ====================================\n");
    navegarPosOrdem(raiz);
    printf("\n");
}
