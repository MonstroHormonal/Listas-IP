#include <stdio.h>
#include <string.h>

int main(){

    int qtdsenhas = 0, i, nletras = 0, j, k, senhaInvalida = 0;
    scanf(" %d", &qtdsenhas);
    char senhas[200], senhas2[200] ="", senhasConvertidas[200][200];

    for(j = 0; j < qtdsenhas; j++){
        scanf("%*[\n]");
        scanf("%199s", senhas);
        strcpy(senhas2, "");
        for(i = 0; senhas[i] != '\0'; i++){
            nletras += 1;
            if(senhas[i] > 64 && senhas[i] < 91 || senhas[i] > 47 && senhas[i] < 58){
                switch (senhas[i])
                {
                case '0':
                    senhas2[i] = '6';
                    break;

                case '1':
                    senhas2[i] = '7';
                    break;
                
                case '2':
                    senhas2[i] = '9';
                    break;
                
                case '3':
                    senhas2[i] = '8';
                    break;
                
                case '4':
                    senhas2[i] = 'A';
                    break;
                
                case '5':
                    senhas2[i] = '2';
                    break;
                
                case '6':
                    senhas2[i] = 'B';
                    break;
                
                case '7':
                    senhas2[i] = 'F';
                    break;
                
                case '8':
                    senhas2[i] = '1';
                    break;
                
                case '9':
                    senhas2[i] = 'C';
                    break;
                
                case 'A':
                    senhas2[i] = '0';
                    break;
                
                case 'B':
                    senhas2[i] = 'D';
                    break;
                
                case 'C':
                    senhas2[i] = 'E';
                    break;
                
                case 'D':
                    senhas2[i] = '3';
                    break;
                
                case 'E':
                    senhas2[i] = '5';
                    break;
                
                case 'F':
                    senhas2[i] = '4';
                    break;
            
                default:
                    senhas2[i] = senhas[i];
                    break;
                }
            }
            else{
                senhaInvalida = 1;
                j = qtdsenhas;
            }
        }
        
        senhas2[i] = '\0';
        if(senhaInvalida != 0) printf("Alguma senha eh invalida!");
        for(k = 0; senhas2[k] != '\0'; k++){
            senhasConvertidas[j][k] = senhas2[k];
        }
        
    }

    if(senhaInvalida == 0){
        for(j = 0; j < qtdsenhas; j++){
            printf("-%s", senhasConvertidas[j]);
        }
        printf(" %d", nletras);
    }

    return 0;
}