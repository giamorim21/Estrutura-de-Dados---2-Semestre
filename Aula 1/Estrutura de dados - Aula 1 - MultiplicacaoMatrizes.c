#include <stdio.h>

// Declaracao de varaiaveis //

int matriz1[2][3];
int matriz2[3][2];
int matrizResultado[2][2];
int i = 0;
int j = 0;
int k = 0;

// Funcao principal de xecucao do codigo //

int main() {
    // Inicializacao da memoria //
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++){
            matriz1[i][j] = 0;
        }
    }
    for(i = 0; i < 3 ; i++) {
        for (j = 0; j < 2; j++) {
            matriz2[i][j] = 0;
        }
    }
    for(i = 0; i < 2 ; i++) {
        for(j = 0; j < 2; j++) {
            matrizResultado[i][j] = 0;
        }
    }

    // Preenchimento das matrizes //
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            printf("matriz1[%d, %d] = ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    for( i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
           printf("matriz2[%d, %d] = ", i, j);
           scanf("%d", &matriz2[i][j]);
        }
    }

    //Multiplicacao propriamente dita //
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0 ; k < 3; k++){
                matrizResultado[i][j] += (matriz1[i][j] * matriz2[k][j]);
            }
        }
    }

    // Impressao do resultado
    printf("\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            printf( "%d\t", matrizResultado[i][j]);
        }
        printf("\n");
    }
}
