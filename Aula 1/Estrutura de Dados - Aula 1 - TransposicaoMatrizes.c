#include <stdio.h>

// Declaracao de variaveis //

int matriz[2][3];
int transposta[3][2];
int i;
int j;

// Funcao principal de execucao do programa //

int main() {
    // Limpeza da memoria
    for(i = 0 ; i < 2 ; i++) {
        for (j = 0 ; j < 3 ; j++) {
            matriz[i][j] = 0;
            transposta[j][i] = 0;
        }
    }

    // Preenchimento da matriz //
    for(i = 0; i < 2 ; i++) {
        for (j = 0 ; j < 3 ; j++){
            printf("matriz[%d, %d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Transposicao propriamente dita //
    for (i = 0 ; i < 2 ; i++) {
        for (j = 0 ; j < 3 ; j++){
            transposta[j][i] = matriz[i][j];
        }
    }

    //Impressao das matrizes //
    printf("\n");
    for ( i = 0 ; i < 2 ; i ++) {
        for (j = 0; j < 3; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for( i = 0 ; i < 3 ; i++) {
        for (j = 0; j < 2; j++){
            printf("%d\t", transposta[i][j]);
        }
        printf("\n");
    }
}
