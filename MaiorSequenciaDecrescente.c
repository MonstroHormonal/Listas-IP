#include <stdio.h>

int main() {
    int casos_teste = 0, i, j, tamseq;
    scanf("%d", &casos_teste);

    for (i = 0; i < casos_teste; i++) {
        scanf("%d", &tamseq);
        int sequencia[tamseq];

        for (j = 0; j < tamseq; j++) {
            scanf("%d", &sequencia[j]);
        }

        int tamanho_sequencia_decrescente = 1;
        int max_tamanho_sequencia = 1;
        int max_inicio_sequencia = 0;

        for (j = 0; j < tamseq; j++) {
            if (sequencia[j] < sequencia[j - 1] && j != 0) {
                tamanho_sequencia_decrescente++;
            } else {
                if (tamanho_sequencia_decrescente > max_tamanho_sequencia) {
                    max_tamanho_sequencia = tamanho_sequencia_decrescente;
                    max_inicio_sequencia = j - max_tamanho_sequencia;
                }
                tamanho_sequencia_decrescente = 1;
            }
        }

        if (tamanho_sequencia_decrescente > max_tamanho_sequencia) {
            max_tamanho_sequencia = tamanho_sequencia_decrescente;
            max_inicio_sequencia = tamseq - max_tamanho_sequencia;
        }

        printf("%d\n", max_tamanho_sequencia);

        for (j = max_inicio_sequencia; j < max_inicio_sequencia + max_tamanho_sequencia; j++) {
            printf("%d ", sequencia[j]);
        }
        printf("\n");
    }

    return 0;
}


