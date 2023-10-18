/// Programa que implementa uma �rvore rubro - negra ///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Defini��o da estrutura do n� ///

struct no{
    int numero;
    struct no *esquerda;
    struct no *direita;
    int cor;     /// 0: preto   1: vermelho
};

/// Fun��o que rotaciona a �rvore � esquerda ///

struct no *rotacionarEsquerda(struct no *raiz){
    /// Rota��o propriamente dita ///
    struct no *temp = raiz -> direita;
    raiz -> direita = temp -> esquerda;
    temp -> esquerda = raiz;

    /// Ajuste da cor
    temp -> cor = raiz -> cor;
    raiz -> cor = 1;

    /// Retorno
    return temp;
};

/// Fun��o que rotaciona a �rvore � direita ///

struct no *rotacionarDireita(struct no *raiz){
    /// Rota��o propriamenet dita ///
    struct no *temp = raiz -> esquerda;
    raiz -> esquerda = temp -> direita;
    temp -> direita = raiz;

    /// Ajuste da cor
    temp -> cor = raiz -> cor;
    raiz -> cor = 1;

    /// Retorno
    return temp;
};

/// Fun��o que sobe o vermelho ///

void subirVermelho(struct no *raiz){
    raiz -> cor = 1;
    raiz -> esquerda -> cor = 0;
    raiz -> direita -> cor = 0;
}

/// Fun��o que determinar a cor do n� ///

int vermelho(struct no *raiz){
    int retorno = 0;

    if (raiz != NULL){
        retorno = raiz -> cor;
    }

    return retorno;
}

/// Fun�ao que insere um n� na �rvore ///

struct no *inserir(struct no *raiz, int numero){
    /// Inser��o como �rvore de busca ///
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

    /// Balanceamento da �rvore ///
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

/// Fun��o que imprimi a �rvore

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

/// Fun��o principal de execu��o do c�digo ///

int main(){
    struct no *raiz = NULL;

    for (int i = 0; i < 100000;  i++){
        raiz = inserir(raiz,i);
    }

    imprimir(raiz, "");
}
