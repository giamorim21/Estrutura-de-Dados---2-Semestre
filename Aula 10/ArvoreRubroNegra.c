/// Programa que implementa uma árvore rubro - negra ///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Definição da estrutura do nó ///

struct no{
    int numero;
    struct no *esquerda;
    struct no *direita;
    int cor;     /// 0: preto   1: vermelho
};

/// Função que rotaciona a árvore à esquerda ///

struct no *rotacionarEsquerda(struct no *raiz){
    /// Rotação propriamente dita ///
    struct no *temp = raiz -> direita;
    raiz -> direita = temp -> esquerda;
    temp -> esquerda = raiz;

    /// Ajuste da cor
    temp -> cor = raiz -> cor;
    raiz -> cor = 1;

    /// Retorno
    return temp;
};

/// Função que rotaciona a árvore à direita ///

struct no *rotacionarDireita(struct no *raiz){
    /// Rotação propriamenet dita ///
    struct no *temp = raiz -> esquerda;
    raiz -> esquerda = temp -> direita;
    temp -> direita = raiz;

    /// Ajuste da cor
    temp -> cor = raiz -> cor;
    raiz -> cor = 1;

    /// Retorno
    return temp;
};

/// Função que sobe o vermelho ///

void subirVermelho(struct no *raiz){
    raiz -> cor = 1;
    raiz -> esquerda -> cor = 0;
    raiz -> direita -> cor = 0;
}

/// Função que determinar a cor do nó ///

int vermelho(struct no *raiz){
    int retorno = 0;

    if (raiz != NULL){
        retorno = raiz -> cor;
    }

    return retorno;
}

/// Funçao que insere um nó na árvore ///

struct no *inserir(struct no *raiz, int numero){
    /// Inserção como árvore de busca ///
    if (raiz == NULL){
        raiz = (struct no *)malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        raiz -> cor = 1;
    } else {
        if (numero < raiz -> numero){
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        } else {
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    /// Balanceamento da árvore ///
    if ((! vermelho(raiz -> esquerda)) && (vermelho(raiz -> direita))){
        raiz = rotacionarEsquerda(raiz);
    }

    if (vermelho(raiz -> esquerda) && vermelho(raiz -> esquerda -> esquerda)){
        raiz = rotacionarDireita(raiz);
    }

    if (vermelho(raiz -> esquerda) && vermelho(raiz -> direita)){
        subirVermelho(raiz);
    }
    return raiz;
};

/// Função que imprimi a árvore

void imprimir(struct no *raiz, char *endentacao){
    if (raiz != NULL){
        printf("%s%d\n", endentacao, raiz -> numero);

        char *temp = (char *)malloc(1024 * sizeof(char));

        strcpy(temp, "--- ");  /// copia
        strcat(temp, endentacao);

        imprimir(raiz -> esquerda, temp);
        imprimir(raiz -> direita, temp);
    }
}

/// Função principal de execução do código ///

int main(){
    struct no *raiz = NULL;

    for (int i = 0; i < 100000;  i++){
        raiz = inserir(raiz,i);
    }

    imprimir(raiz, "");
}
