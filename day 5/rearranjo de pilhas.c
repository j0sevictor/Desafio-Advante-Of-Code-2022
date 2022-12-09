#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINHAS 8
#define COLUNAS 9
#define TAM_STRING 60

char** matrizPont(int linhas, int colunas){
    char **matriz;
    int contador;
    
    matriz = (char**) malloc(linhas * sizeof(char*));

    for (contador = 0; contador < linhas; contador++){
        matriz[contador] = (char*) malloc(colunas * sizeof(char));
    }
    
    return matriz; 
}

void freeMatriz(char** matriz, int linhas){
    int i;

    for (i = 0; i < linhas; i++){
        free(matriz[i]);
    }

    free(matriz);
}

int charToInt(char numero){
    return numero - 48;
}

void moverLetra(char **matriz, int linhaPerde, int linhaGanha){
    char auxi;
    int indexFim1 = strlen(matriz[linhaPerde]) - 1;
    int indexZero = strlen(matriz[linhaGanha]);

    auxi = matriz[linhaPerde][indexFim1];
    matriz[linhaPerde][indexFim1] = '\0';
    matriz[linhaGanha][indexZero] = auxi;
    matriz[linhaGanha][indexZero + 1] = '\0';
}

int lerComando(char *comando, int tamanho){
    /*
        RETORNA TODOS OS NUMERO DA STRING "comando" EM 
        UM SÓ NUMERO.
    */
    int i, numero=0;

    for (i = 0; i < tamanho; i++){
        if (comando[i] >= '0' && comando[i] <= '9'){
            numero = numero * 10 + charToInt(comando[i]);
        }
    }

    return numero;
}

int main(){
    FILE *arquivo = fopen("input.txt", "r");
    char **pilhas = matrizPont(LINHAS, COLUNAS);

    char *linhaTexto = (char*) malloc(50*sizeof(char));
    char *resultado;
    int tamanho, i, j, contador=0;
    int iLinha=0, jColuna=0;

    while (contador < 10){
        resultado = fgets(linhaTexto, 51, arquivo);
        tamanho = strlen(linhaTexto);

        contador++;

        if (resultado != NULL && contador < 9){
            for (i = 1; i < tamanho; i += 4){
                pilhas[iLinha][jColuna] = linhaTexto[i];
                jColuna++;
            }

            iLinha++;
            jColuna = 0;
        }
    }

    char **pilhaInversa = matrizPont(COLUNAS, TAM_STRING);
    iLinha = 0;
    jColuna = 0;

    for (j = 0; j < COLUNAS; j++){
        for (i = (LINHAS - 1); i >= 0; i--){
            if (pilhas[i][j] == ' '){
                continue;
            }
            pilhaInversa[iLinha][jColuna] = pilhas[i][j];
            jColuna++;
        }
        pilhaInversa[iLinha][jColuna] = '\0';
        jColuna = 0;
        iLinha++;
    }

    freeMatriz(pilhas, LINHAS);

    for (i = 0; i < COLUNAS; i++){
        printf("[%s]\n", pilhaInversa[i]);
    }

    int infor, quantidadeMovimento, linhaPerde, linhaRecebe;

    while (!feof(arquivo)){
        resultado = fgets(linhaTexto, 51, arquivo);
        tamanho = strlen(linhaTexto);

        if (resultado != NULL){
            
            infor = lerComando(linhaTexto, tamanho);

            linhaRecebe = infor % 10 - 1;
            infor = infor/10;
            linhaPerde = infor % 10 - 1;
            infor = infor/10;
            quantidadeMovimento = infor;

            for (i = 0; i < quantidadeMovimento; i++){
                moverLetra(pilhaInversa, linhaPerde, linhaRecebe);
            }
        }else{

        }
    }
    
    printf("\n");
    for (i = 0; i < COLUNAS; i++){
        printf("%d - [%s]\n", i+1, pilhaInversa[i]);
    }
    
    printf("\n");
    for (i = 0; i < COLUNAS; i++){
        printf("%c", pilhaInversa[i][strlen(pilhaInversa[i])-1]);
    }

    fclose(arquivo);
    return 0;
}