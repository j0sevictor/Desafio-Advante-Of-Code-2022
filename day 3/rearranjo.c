#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char acharPrioridade(char **bolsas, int *tamanho){ 
    int i, j, k;

    for (i = 0; i < tamanho[0]; i++){
        for (j = 0; j < tamanho[1]; j++){
            for (k = 0; k < tamanho[2]; k++){
                if (bolsas[0][i] == bolsas[1][j] && bolsas[0][i] == bolsas[2][k]){
                    return bolsas[0][i];
                }
            }
        }
    }

    return '\0';
}

int conversorDePrioridade(char item){
    if (item >= 65 && item <= 90){
        return item - 38;
    }

    if (item >= 97 && item <= 122){
        return item - 96;
    }

    return -1;
}

int main(){
    FILE *bolsas = fopen("input.txt", "r");

    int i, somaPrioridades=0;
    int tamanho[3];
    char prioridade;
    
    char **trincaBolsa = (char**) malloc(3 * sizeof(char*));
    for (i = 0; i < 3; i++){
        trincaBolsa[i] = (char*) malloc(50 * sizeof(char));
    }

    while (!feof(bolsas)){
        for (i = 0; i < 3; i++){
            fgets(trincaBolsa[i], 51, bolsas);
            
            tamanho[i] = strlen(trincaBolsa[i]);
            trincaBolsa[i][tamanho[i] - 1] = '\0';
            tamanho[i]--;
        }

        prioridade = acharPrioridade(trincaBolsa, tamanho);
        somaPrioridades += conversorDePrioridade(prioridade);
    }

    printf("A SOMA DAS PRIORIDADES E: %d", somaPrioridades);

    fclose(bolsas);
    return 0;
}