#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Declara��o de constantes ///

const int MODULO = 3;

/// Declara��o de estruturas ///

struct no {
    int numero;
    struct no *proximoNo;
};

struct diretor {
    int resto;
    struct no *proximoNo;
    struct diretor *proximoDiretor;
};

/// Declara��o de variav�is ///

struct diretor *cabeca = NULL;

/// Fun��o que procura o diretor certo ///

struct diretor *procurarDiretor(int resto) {
    struct diretor *ponteiro = cabeca;

    /// Varrendo a lista at� encontrar o resto certo ou chegar no final ///
    while ((ponteiro != NULL) && (ponteiro -> resto != resto)){
        ponteiro = ponteiro -> proximoDiretor;
    }

    if (ponteiro == NULL){
        /// Criar um diretor novo ///
        ponteiro = (struct diretor *)malloc(sizeof(struct diretor));
        ponteiro -> resto = resto;
        ponteiro -> proximoNo = NULL;
        ponteiro ->  proximoDiretor = cabeca;

        cabeca = ponteiro;
    }

    return ponteiro;
};

/// Fun��o que insere um n� na matriz esparsa ///

void inserir(int numero){
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);

    struct no *novoNo = (struct no *)malloc(sizeof(struct no));

    novoNo -> numero = numero;
    novoNo -> proximoNo = ponteiroDiretor -> proximoNo;

    ponteiroDiretor -> proximoNo = novoNo;
}

/// Fun��o que imprime a matriz esparsa ///

void imprimir(){
    struct diretor *ponteiroDiretor = cabeca;

    printf("============ MATRIZ ESPARSA ==============\n");
    while (ponteiroDiretor != NULL){
        struct no *ponteiroNo = ponteiroDiretor -> proximoNo;

        printf("%d:\t", ponteiroDiretor -> resto);
        while (ponteiroNo != NULL){
            printf("%d\t", ponteiroNo -> numero);
            ponteiroNo = ponteiroNo -> proximoNo;
        }
        printf("\n");
        ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
    }
}

/// Fun��o que remove um numero ///

void remover (int numero){
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);

    if (ponteiroDiretor -> proximoNo != NULL){
        if (ponteiroDiretor -> proximoNo -> numero == numero){
            /// Caso f�cil, excluir o primeiro numero da lista ///
            struct no *ponteiroExcluir = ponteiroDiretor -> proximoNo;
            ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
            free(ponteiroExcluir);
        } else {
            /// Caso dificil, excluir algum n� meio da lista ///
            struct no *ponteiroAnterior = ponteiroDiretor -> proximoNo;

            while ((ponteiroAnterior -> proximoNo != NULL) && (ponteiroAnterior -> proximoNo -> numero != numero)){
                ponteiroAnterior = ponteiroAnterior -> proximoNo;
            }

            if (ponteiroAnterior -> proximoNo != NULL){
                struct no *ponteiroExcluir = ponteiroAnterior -> proximoNo;
                ponteiroAnterior -> proximoNo = ponteiroExcluir -> proximoNo;
                free(ponteiroExcluir);
            }
        }
    }
}

/// Fun��o principal de execu��o do programa ///

int main(){
    int i = 0;
    int numero = 0;
    time_t t;

    srand((unsigned) time(&t));

    for (i = 0; i < 10; i++){
        inserir(rand());
    }
    imprimir(i);

    printf("Digite um numero para excluir: ");
    scanf("%d", &numero);

    remover(numero);

    imprimir();
}
