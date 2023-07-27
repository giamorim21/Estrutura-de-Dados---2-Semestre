#include <stdio.h>

int matriz1[3][4];
int matriz2[4][3];
int matrizResultado[3][3];
int i = 0;
int j = 0;
int k = 0;

void main() {
    // Inicializacao da memoria
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            matriz1[i][j] = 0;
        }
    }
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            matriz2[i][j] = 0;
        }
    }
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            matrizResultado[i][j] = 0;
        }
    }

    // Preenchimento das matrizes
    printf("Dados da Matriz 1\n");
    printf("\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            printf("matriz1[%d, %d] = ", i , j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\n");
    printf("Dados da Matriz 2\n");
    printf("\n");
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("matriz2[%d, %d] = ", i , j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Multiplicacao da matriz
    for(i = 0; i < 3; i++){    // i = linha da matriz 1
        for(j = 0; j < 3; j++){ // j = coluna da matriz 2
            for(k = 0; k < 4; k++){ // k = coluna da matriz 1 = linha da matriz 2
                matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    //Impressao da matriz
    printf("\n");
    printf("Matriz Resultante da Multiplicacao\n");
    printf("\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d\t", matrizResultado[i][j]);
        }
        printf("\n");
    }
}
