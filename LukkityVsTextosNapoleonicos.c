#include <stdio.h>
#include <string.h>

int main(){
    int quantidadePadroes = 0, indiceTexto = 0, indicePadrao = 0, i = 0, j = 0,
        encontrouColchete = 0, traducao = 0, indiceCodigo = 0, indicePalavra = 0, contagemCasos = 0;
    char codigo[4], texto[500], backup[500], padroes[5][31], padraoBackup[31];

    scanf(" %499[^\n]", texto);

    while (texto[indiceTexto] != '\0'){
        if (texto[indiceTexto] == '[') encontrouColchete = 1;
        else if (texto[indiceTexto] == ']'){
            encontrouColchete = 0;
            quantidadePadroes += 1;
            indicePadrao = 0;
        }
        else if (encontrouColchete){
            padroes[quantidadePadroes][indicePadrao] = texto[indiceTexto];
            ++indicePadrao;
        }
        ++indiceTexto;
    }

    for (i = 0; i < quantidadePadroes; ++i){   
        strcpy(padraoBackup, padroes[i]);
        for (j = 0; j < strlen(padraoBackup); ++j){
            if (padraoBackup[j] == '-'){
                codigo[indiceCodigo] = '\0';
                indiceCodigo = 0;
                if (strlen(codigo) == 3)traducao = (((int)codigo[0] - 48) * 100) + (((int)codigo[1] - 48) * 10) + (((int)codigo[2] - 48));
                else traducao = (((int)codigo[0] - 48) * 10) + (((int)codigo[1] - 48));
                padroes[i][indicePalavra] = traducao;
                ++indicePalavra;
            }
            else{
                codigo[indiceCodigo] = padroes[i][j];
                ++indiceCodigo;
            }
        }
        padroes[i][indicePalavra] = '\0';
        indicePalavra = 0;
        indiceCodigo = 0;
    }

    int tamanhoPadrao;
    contagemCasos = 0;
    for (i = 0; i < quantidadePadroes; ++i){
        tamanhoPadrao = strlen(padroes[i]);
        for (j = 0; j < tamanhoPadrao; ++j){
            if (padroes[i][j] >= 65 && padroes[i][j] <= 90)contagemCasos -= 1;
            else if (padroes[i][j] >= 97 && padroes[i][j] <= 122)contagemCasos += 1;
        }

        if (!(contagemCasos == tamanhoPadrao || contagemCasos == -1 * tamanhoPadrao)){
            for (j = 0; j < tamanhoPadrao; ++j){
                if (contagemCasos > 0 && padroes[i][j] >= 65 && padroes[i][j] <= 90)padroes[i][j] += 32;
                else if (contagemCasos < 0 && padroes[i][j] >= 97 && padroes[i][j] <= 122)padroes[i][j] -= 32;
            }
        }
        contagemCasos = 0;
    }

    indiceTexto = 0;
    int restantes = quantidadePadroes;

    while (texto[indiceTexto] != '\0'){
        if (texto[indiceTexto] == '['){
            strcpy(backup, texto);
            texto[indiceTexto] = '\0';
            strcat(texto, padroes[quantidadePadroes - restantes]);

            for (i = indiceTexto; backup[i] != '\0'; ++i){
                if (backup[i] == ']'){
                    strcat(texto, backup + i + 1);
                    break;
                }
            }

            --restantes;
        }

        ++indiceTexto;
    }

    printf("%s", texto);

    return 0;
}
