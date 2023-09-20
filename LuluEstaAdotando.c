#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
    float altura;
} filho;

int main() {
    int n, m, x, i, j;
    char aux[100];

    scanf("%d %d %d", &n, &m, &x);
    int numx[n];
    filho filhos[n];

    for (i = 0; i < n; i++) {
        scanf("%s %d %f", filhos[i].nome, &filhos[i].idade, &filhos[i].altura);
        numx[i] = (filhos[i].idade) * (filhos[i].altura) * (strlen(filhos[i].nome)) + 0;
    }

    for (i = 0; i < n; i++) {
        numx[i] = numx[i] - x;
        if (numx[i] < 0) {
            numx[i] = -numx[i];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (numx[j] > numx[j + 1]) {
                int temp = numx[j];
                numx[j] = numx[j + 1];
                numx[j + 1] = temp;

                strcpy(aux, filhos[j].nome);
                strcpy(filhos[j].nome, filhos[j + 1].nome);
                strcpy(filhos[j + 1].nome, aux);
            }
        }
    }

    for (i = 0; i < m; i++) {
        printf("%s\n", filhos[i].nome);
    }

    return 0;
}
