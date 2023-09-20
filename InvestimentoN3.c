#include <stdio.h>

int main() {
    int matriz[4][4] = {0};
    int x = 0, y = 0;
    int passo;
    char caminho[20];
    int maior = -1;
    int posicoes[20][2]; 
    int numPosicoes = 0;  
        for (passo = 0; passo < 20; passo++) {
        scanf(" %c", &caminho[passo]);
        if (caminho[passo] == 'b' && y + 1 < 4) {
            y += 1; 
            matriz[x][y] += 1;
        } else if (caminho[passo] == 'd' && x + 1 < 4) {
            x += 1; 
            matriz[x][y] += 1;
        } else if (caminho[passo] == 'c' && y - 1 >= 0) {
            y -= 1; 
            matriz[x][y] += 1;
        } else if (caminho[passo] == 'e' && x - 1 >= 0) {
            x -= 1; 
            matriz[x][y] += 1;
        }
    
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                numPosicoes = 0; 
                posicoes[numPosicoes][0] = i;
                posicoes[numPosicoes][1] = j;
                numPosicoes++;
            } else if (matriz[i][j] == maior) {
                posicoes[numPosicoes][0] = i;
                posicoes[numPosicoes][1] = j;
                numPosicoes++;
            }
        }
    }
        x = posicoes[0][0];
    y = posicoes[0][1];
    printf("Coordenada X:%d, Y:%d", x, y);
    return 0;
}