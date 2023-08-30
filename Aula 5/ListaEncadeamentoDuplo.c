#include <stdio.h>
#include <stdlib.h>

/// Declara��o da estrutura do n� ///

struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
};

/// Declara��o de vari�veis ///

struct no *cabeca = NULL;

/// Fun��o que insere um n� na lista ///

void inserir(int numero){
    /// Aloca��o da mem�ria
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> anterior = NULL;
    novoNo -> proximo = NULL;

    if (cabeca == NULL)
        /// Caso facil, a lista esta vazia
        cabeca = novoNo;
    else {
        /// Caso dificil, a lista NAO esta vazia
        struct no *ponteiro = cabeca;

        /// Procurando o ultimo n� da lista
        while (ponteiro -> proximo != NULL){
         ponteiro = ponteiro -> proximo;
        }

        /// Executa os apontamentos
        ponteiro -> proximo = novoNo;
        novoNo -> anterior = ponteiro;
    }
}

/// Fun��o que imprime a lista ///

void imprimir(){
    struct no *ponteiro = cabeca;

    while (ponteiro != NULL){
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }

    printf("===============================\n");
}

/// Fun��o que remove um n� da lista ///

void remover(int numero){
    struct no *ponteiro = cabeca;

    while (ponteiro != NULL){
       if (ponteiro -> numero == numero){
            if (ponteiro -> anterior == NULL){
                /// Excluir o primeiro n� da lista
                cabeca = cabeca -> proximo;
                if (cabeca != NULL){
                   cabeca -> anterior = NULL;
                }
                free(ponteiro);
                ponteiro = cabeca;
            } else if (ponteiro -> proximo == NULL){
                /// Excluir o �ltimo n� da lista
                struct no *temp = ponteiro;
                ponteiro = ponteiro -> anterior;
                ponteiro -> proximo = NULL;
                free(temp);
            } else {
                /// Excluir um n� no meio da lista
                struct no *temp = ponteiro;
                ponteiro = ponteiro -> anterior;
                temp -> anterior -> proximo = temp -> proximo;
                temp -> proximo -> anterior = temp -> anterior;
                free(temp);
            }
       }
        if (ponteiro != NULL){
            ponteiro = ponteiro -> proximo;
        }
    }
}

int main(){
    imprimir();

    inserir(1);
    remover(1);
    imprimir();

    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    remover(1);
    remover(5);
    remover(3);
    imprimir();
}
