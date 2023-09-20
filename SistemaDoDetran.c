#include <stdio.h>
#include <string.h>

int main() {
    int nplacas = 0, i = 0, X = 0, Y = 0, cont, l = 0;
    scanf("%d", &nplacas);
    char placas[nplacas][8], placasC[nplacas][8], placasE[nplacas][8];

    for (i = 0; i < nplacas; i++) {
        scanf("%s", placas[i]);
        cont = 0;

        for (int k = 0; k < 3; k++) {
            if (placas[i][k] >= 'A' && placas[i][k] <= 'Z') {
                placasC[X][k] = placas[i][k];
                cont++;
            }
        }

        for (int k = 3; k < 7; k++) {
            if (placas[i][k] >= '0' && placas[i][k] <= '9') {
                placasC[X][k] = placas[i][k];
                cont++;
            }
        }

        placasC[X][7] = '\0';

        if (cont == 7) {
            X++;
        } else {
            strcpy(placasE[Y], placas[i]);
            Y++;
        }
    }

    printf("%d placas:\n", X);
    for (l = 0; l < X; l++)
        printf("%s\n", placasC[l]);

    printf("%d erros:\n", Y);
    for (l = 0; l < Y; l++)
        printf("%s\n", placasE[l]);

    return 0;
}
