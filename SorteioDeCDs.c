#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[20];
    char classificacao[6];
    int status;
    char dono[21];
} lista1;

typedef struct{
    char nome[21];
    lista1 albuns[30];
    int nAlbuns;
} Artista;

int main(){

    int nArtistas, i, j;
    int cd1, cd2, cd3;
    lista1 CDs[100];
    int indiceCD = 0;

    scanf("%d", &nArtistas);

    Artista artistas[nArtistas];

    for (i = 0; i < nArtistas; i++){
        int x = 0;
        scanf(" %[^\n] %d", artistas[i].nome, &artistas[i].nAlbuns);
        for (j = 0; j < artistas[i].nAlbuns; j++){
            scanf("%s %d %[^\n]", artistas[i].albuns[x].nome, &artistas[i].albuns[x].status, artistas[i].albuns[x].classificacao);
            strcpy(artistas[i].albuns[j].dono, artistas[i].nome);
            x++;
        }
    }

    scanf("%d %d %d", &cd1, &cd2, &cd3);

    for (i = 0; i < nArtistas; i++){
        for (j = 0; j < nArtistas - 1; j++){
            if (strcmp(artistas[j].nome, artistas[j + 1].nome) > 0){
                Artista aux;
                aux = artistas[j + 1];
                artistas[j + 1] = artistas[j];
                artistas[j] = aux;
            }
        }
    }

    for (int i = 0; i < nArtistas; i++){
        for (int j = 0; j < artistas[i].nAlbuns; j++){
            CDs[indiceCD] = artistas[i].albuns[j];
            indiceCD++;
        }
    }

    lista1 escolhidos[3];
    escolhidos[0] = CDs[cd1 - 1];
    escolhidos[1] = CDs[cd2 - 1];
    escolhidos[2] = CDs[cd3 - 1];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            if (strlen(escolhidos[j].classificacao) < strlen(escolhidos[j + 1].classificacao)){
                lista1 temp;
                temp = escolhidos[j + 1];
                escolhidos[j + 1] = escolhidos[j];
                escolhidos[j] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++){
        if (escolhidos[i].status) printf("Infelizmente %s ta emprestado:(\n", escolhidos[i].nome);
        else printf("%s - %s\n", escolhidos[i].dono, escolhidos[i].nome);
    }
    return 0;
}
