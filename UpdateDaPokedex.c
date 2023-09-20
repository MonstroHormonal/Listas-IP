#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    char tipo[100];
    int ataque;
    int defesa;
} atributosI;

typedef struct {
    char nome[100];
    char tipo[100];
    int ataque;
    int defesa;
    int fatVant;
} atributosA;

int main() {

    int i, n, j, k;
    atributosI inimigo[1];

    scanf("%s %s %d %d", inimigo[0].nome, inimigo[0].tipo, &inimigo[0].ataque, &inimigo[0].defesa);

    scanf("%d", &n);

    atributosA pokemon[n];

    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d", pokemon[i].nome, pokemon[i].tipo, &pokemon[i].ataque, &pokemon[i].defesa);
    }

    for (i = 0; i < n; i++) {
        if (strcmp(pokemon[i].tipo, "agua") == 0 && strcmp(inimigo[0].tipo, "fogo") == 0) {
            pokemon[i].fatVant = 1.5 * pokemon[i].ataque - inimigo[0].defesa;
        } else if (strcmp(pokemon[i].tipo, "grama") == 0 && strcmp(inimigo[0].tipo, "agua") == 0) {
            pokemon[i].fatVant = 1.5 * pokemon[i].ataque - inimigo[0].defesa;
        } else if (strcmp(pokemon[i].tipo, "fogo") == 0 && strcmp(inimigo[0].tipo, "grama") == 0) {
            pokemon[i].fatVant = 1.5 * pokemon[i].ataque - inimigo[0].defesa;
        } else {
            pokemon[i].fatVant = pokemon[i].ataque - inimigo[0].defesa;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pokemon[j].fatVant < pokemon[j + 1].fatVant) {
                atributosA temp = pokemon[j];
                pokemon[j] = pokemon[j + 1];
                pokemon[j + 1] = temp;
            } else if (pokemon[j].fatVant == pokemon[j + 1].fatVant) {
                // Se o atributo fatVant for igual, ordenar por nome
                if (strcmp(pokemon[j].nome, pokemon[j + 1].nome) > 0) {
                    atributosA temp = pokemon[j];
                    pokemon[j] = pokemon[j + 1];
                    pokemon[j + 1] = temp;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, pokemon[i].nome);
    }

    return 0;
}
