#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int deCharParaInt(char *palavra, int tamanho){
    int numero=0, i;
    int auxiliar;

    if (palavra[0] < 48 || palavra[0] > 57){
        return 0;
    }

    for (i = 0; i < tamanho; i++){
        if (palavra[i] >= 48 && palavra[i] <= 57){
            auxiliar = palavra[i] - 48;
            numero = numero * 10 + auxiliar;
        }
    }

    return numero;
}

int main(){
    FILE* calorias;

    calorias = fopen("input.txt", "r");

    if (calorias == NULL){
        printf("ERRO NA ABERTURA");
        system("pause");
        exit(1);
    }

    char *palavra = (char*) malloc(6 * sizeof(char));
    char *result;
    int numero, contador=1, soma=0;
    int somaMaior1=0, somaMaior2=0, somaMaior3=0, posicaoMaior;

    while (!feof(calorias)){
        result = fgets(palavra, 7, calorias);

        if (result == NULL){
            printf("ERRO DE LEITURA");
        }else{
            numero = deCharParaInt(palavra, 5);

            if (numero != 0){
                soma += numero;
            }else{
                if (soma > somaMaior1){
                    somaMaior3 = somaMaior2;
                    somaMaior2 = somaMaior1;
                    somaMaior1 = soma;
                    posicaoMaior = contador;
                }else if(soma > somaMaior2){
                    somaMaior3 = somaMaior2;
                    somaMaior2 = soma;
                }else if (soma > somaMaior3){
                    somaMaior3 = soma;
                }
                soma = 0;
                contador++;
            }
        }
    }

    printf("O ELFO COM MAIS CALORIAS E: %d com %d CALORIAS\n", posicaoMaior, somaMaior1);
    printf("O ELSE EM SEGUNDO TEM: %d\n", somaMaior2);
    printf("O ELSE EM TERCEIRO TEM: %d\n", somaMaior3);
    printf("TOTALIZANDO: %d\n", somaMaior1 + somaMaior2 + somaMaior3);
    
    fclose(calorias);
    return 0;
}