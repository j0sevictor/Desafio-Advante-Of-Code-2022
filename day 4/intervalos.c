#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int areas[4];
} tParDeElfos;

int conversorCharInt(char numero){
    return numero - 48;
}

int estaContido(tParDeElfos *parElf){

    int area1 = parElf->areas[1] - parElf->areas[0] + 1;
    int area2 = parElf->areas[3] - parElf->areas[2] + 1;
    int i, j;

    for (i = 0; i < area1; i++){
        for (j = 0; j < area2; j++){
            if (parElf->areas[0] + i == parElf->areas[2] + j){
                return 1;
            }
        }
    }

    return 0;
}

int potenciaDe10(int i){
    if (i == 0){
        return 1;
    }

    return 10 * potenciaDe10(i-1);
}

int main(){
    FILE *arquivo = fopen("input.txt", "r");

    char *intervalos = (char*) malloc(16*sizeof(char));
    tParDeElfos *parDeElfos = (tParDeElfos*) malloc(sizeof(tParDeElfos));
    int i, j, valor=0, contador=0, intervalosContidos = 0;
    char *resultado;
    
    while (!feof(arquivo)){
        resultado = fgets(intervalos, 15, arquivo);

        if (resultado != NULL){
            i = 0; j = 0;

            while (1){
                if (intervalos[i] == '-' || intervalos[i] == ',' || intervalos[i] == '\n'){
                    parDeElfos->areas[j] = valor;
                    contador = 0;
                    valor = 0;
                    j++;
                    
                    if (intervalos[i] == '\n'){
                        break;
                    }
                }else if (intervalos[i] >= '0' && intervalos[i] <= '9'){
                    valor = valor*potenciaDe10(contador) + conversorCharInt(intervalos[i]);
                    contador++;
                }
                i++;
            }

            if (estaContido(parDeElfos)){
                intervalosContidos++;
            }
        }else{
            printf("ERRO NA LEITURA");
        }
    }

    printf("NUMERO DE INTERVALOS CONTIDOS: %d", intervalosContidos);

    fclose(arquivo);
    return 0;
}