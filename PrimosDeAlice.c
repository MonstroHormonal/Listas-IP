#include <stdio.h>
#include <math.h>

int main() {
    int tam = 100;
    int n;
    scanf("%d", &n);

    int matriz[tam][tam], i, j, k;
    int primos[tam * tam];
    int numprimos = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int primo = 1;
            if (matriz[i][j] < 2) {
                primo = 0;
            }
            for (k = 2; k <= sqrt(matriz[i][j]); k++) {
                if (matriz[i][j] % k == 0) {
                    primo = 0;
                    break;
                }
            }
            if (primo) {
                primos[numprimos] = matriz[i][j];
                numprimos++;
            }
        }
    }
    for (i = 0; i < numprimos - 1; i++) {
        int min = i;
        for (j = i + 1; j < numprimos; j++) {
            if (primos[j] < primos[min]) {
                min = j;
            }
        }
        int temp = primos[i];
        primos[i] = primos[min];
        primos[min] = temp;
    }
    for (i = 0; i < numprimos; i++) {
        printf("%d ", primos[i]);
    }

    return 0;
}
