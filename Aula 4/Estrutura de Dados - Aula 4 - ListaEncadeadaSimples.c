# include <stdio.h>  // Entrada e saida
# include <stdlib.h>

/// Declaracao da estrutura do nó ///

struct no {
    int numero;
    struct no *proximo;
};

/// Declaracao de variaveis ///

struct no *cabeca = NULL;

/// Funcao que insere um no na lista ///

void inserir(int numero) {
    // Alocacao do espaco de memoria
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));  // MALLOC = é uma funcao de alocacao do espaco de memoria que vem da segunda biblioteca // SIZEOF = tamanho da estrutura do ponteiro
    novoNo -> numero = numero;                                    // struct no é sem o (*) porque precisamos pegar o tamanho todo da estutura que temos 4 bytes do inteiro e 8 bytes do ponteiro
    novoNo -> proximo = NULL;

    if (cabeca == NULL){
        // Caso facil, a lista esta vazia
        cabeca = novoNo;
    } else {
        // Caso dificil, a lista NAO esta vazia
        struct no *ponteiro = cabeca;            // O ponteiro esta apontando para oque a cabeca esta apontando

        while (ponteiro -> proximo != NULL){
            ponteiro = ponteiro -> proximo;      // Ele verifica se o ponteiro proximo é nulo, caso nao ele vai apontar para esse proximo, se for nulo o while acaba
        }

        ponteiro -> proximo = novoNo;
    }
}

/// Funcao que imprimi os nos da lista ///

void imprimir(){
    printf("============================\n");

    struct no *ponteiro = cabeca;

    while (ponteiro != NULL){
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
}

/// Funcao que exclui o no da lista ///

void remover(int numero){
    if(cabeca != NULL){
        if (cabeca -> numero == numero){
            // Caso facil, excluir o primeiro no da lista
            struct no *ponteiroExcluir = cabeca;
            cabeca = cabeca -> proximo;
            free (ponteiroExcluir);                               // FREE = funcao que desaloca o espaco da memoria (limpa a memoria)
        } else {
            // Caso dificil, excluir algum no no meio da lista
            struct no *ponteiroAnterior = cabeca;

            while ((ponteiroAnterior -> proximo != NULL) && (ponteiroAnterior -> proximo -> numero != numero)){
                ponteiroAnterior = ponteiroAnterior -> proximo;
            }
            if (ponteiroAnterior -> proximo != NULL){
                struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
                ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
                free(ponteiroExcluir);
            }
        }
    }
}

/// Funcao principal de execucao do programa ///

int main(int argc, char *argv[]){
    int opcao = 0;
    int numero = 0;

    while (opcao != 4){
        printf("+================+\n");
        printf("| Menu de Opcoes |\n");
        printf("+================+\n");
        printf("| 1 - Inserir    |\n");
        printf("| 2 - Remover    |\n");
        printf("| 3 - Imprimir   |\n");
        printf("| 4 - Sair       |\n");
        printf("+================+\n");
        printf("Digite a opcao: \n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Digite o numero: ");
            scanf("%d", &numero);
            inserir(numero);
            break;
        case 2:
            printf("Digite o numero: ");
            scanf("%d", &numero);
            remover(numero);
            break;
        case 3:
            imprimir();
            break;
        }

    }
}
