#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_PACOTE 15

int todosDiferentes(char *letras, int tamanho){
    int i, j;
    for (i = 0; i < tamanho; i++){
        for(j = i+1; j < tamanho; j++){
            if (letras[i] == letras[j]){
                return 0;
            }
        }
    }

    return 1;
}

void addLetraFinal(char *letras, int tamanho, char letra){
    int i;
    char auxiliar;
    for (i = 0; i < tamanho - 1; i++){
        letras[i] = letras[i+1];
    }
    letras[i] = letra;
}

int main(){
    FILE *arquivo = fopen("input.txt", "r");
    char *cincoDaSequencia = (char*) malloc(TAM_PACOTE*sizeof(char));
    char *resultado;
    int numeroCaracteres=0, tamanho;

    resultado = fgets(cincoDaSequencia, TAM_PACOTE, arquivo);
    numeroCaracteres += TAM_PACOTE - 1;
    tamanho = strlen(cincoDaSequencia);

    while (!feof(arquivo)){
        if (resultado != NULL){
            if (!todosDiferentes(cincoDaSequencia, tamanho)){
                addLetraFinal(cincoDaSequencia, tamanho, fgetc(arquivo));
                numeroCaracteres++;     
            }else{
                break;
            }
        }else{
            printf("ERRO DE LEITURA");
        }
    } 

    printf("FORAM LIDOS %d CARACTERES", numeroCaracteres);

    fclose(arquivo);
    return 0;
}
