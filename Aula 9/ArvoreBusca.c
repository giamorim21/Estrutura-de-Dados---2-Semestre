/// Programa que implementa uma Arvore de Busca ///

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
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    } else {
        if (numero < raiz -> numero){
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        } else if (numero > raiz -> numero){
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    return raiz;
};

/// Fun��o que busca um n� na �rvore ///

void buscar(struct no *raiz, int numero){
    if (raiz == NULL){
        printf("Nao achei!!!");
    } else if (raiz -> numero == numero){
        printf("Achei porra!!!");
    } else if (numero < raiz -> numero){
        buscar(raiz -> esquerda, numero);
    } else {
        buscar(raiz -> direita, numero);
    }
}

/// Fun��o que navega a �rvore em ordem ///

void navegar(struct no *raiz){
    if (raiz != NULL){
        navegar(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegar(raiz -> direita);
    }
}

/// Fun��o que desenha um MENU na tela ///

int menu(){
    int opcao;

    printf("\n");
    printf("+===========================================================+\n");
    printf("|                      Menu De Opcoes                       |\n");
    printf("+===========================================================+\n");
    printf("|           1 - Inserir                                     |\n");
    printf("|           2 - Buscar                                      |\n");
    printf("|           3 - Navegar                                     |\n");
    printf("|           4 - Construir Arvore Aleatoriamente             |\n");
    printf("|           5 - Sair                                        |\n");
    printf("+===========================================================+\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

/// Fun��o principal de execu��o do programa ///

int main(){
    /// Declara��o de vari�veis ///
    struct no *raiz = NULL;
    int opcao = 0;
    int numero = 0;
    int i = 0;

    /// Inicializa��o da aleatoriedade ///
    time_t t;
    srand((unsigned) time(&t));

    /// Manipula��o da �rvore ///
    while (opcao != 5){
        opcao = menu();

        switch (opcao){
            case 1:
                printf("Digite o numero: ");
                scanf("%d", &numero);

                raiz = inserir(raiz, numero);

                break;
            case 2:
                printf("Digite o numero: ");
                scanf("%d", &numero);

                buscar(raiz, numero);

                break;
            case 3:
                navegar(raiz);

                break;
            case 4:
                for(i = 0; i < 1000; i++){
                    raiz = inserir(raiz, rand());
                }
                break;

        }
    }
}
