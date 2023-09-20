#include <stdio.h>

int main() {
    int ai = 0, aj = 0, bi = 0, bj = 0, i = 0, j = 0, k = 0, ia = 0, ib = 0, ja, jb = 0, l = 0, m;
    scanf("%d %d %d %d", &ai, &aj, &bi, &bj);
    int matrizA[ai][aj];
    int matrizB[bi][bj];
    int matrizC[ai][bj];
    if (aj == bi) {
        for (ia = 0; ia < ai; ia++) { // Corrigir a inicializa��o de ia e ib
            for (ja = 0; ja < aj; ja++) {
                scanf("%d", &matrizA[ia][ja]);
            }
        }
        for (ib = 0; ib < bi; ib++) { // Corrigir a inicializa��o de ia e ib
            for (jb = 0; jb < bj; jb++) {
                scanf("%d", &matrizB[ib][jb]);
            }
        }
        for (i = 0; i < ai; i++) {
            for (j = 0; j < bj; j++) {
                matrizC[i][j] = 0; // Inicialize a matrizC para evitar valores incorretos
                for (k = 0; k < aj; k++) {
                    matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
                }
            }
        }
        printf("\n");
        for (l = 0; l < ai; l++) {
            for (m = 0; m < bj; m++) {
                printf("%d ", matrizC[l][m]);
            }
            printf("\n");
        }
    } else {
        printf("Nao e possivel multiplicar");
    }
    return 0;
}
