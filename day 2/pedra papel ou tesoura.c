#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int resultadoPartida(char jogador1, char jogador2){
    if (jogador1 == jogador2){
        return -1;
    }

    if (jogador1 == 'A' && jogador2 == 'B'){
        return 1;
    }

    if (jogador1 == 'B' && jogador2 == 'C'){
        return 1;
    }

    if (jogador1 == 'C' && jogador2 == 'A'){
        return 1;
    }

    return 0;
}

char perder(char jogada){
    if (jogada == 'A'){
        return 'C';
    }
    if (jogada == 'B'){
        return 'A';
    }
    if (jogada == 'C'){
        return 'B';
    }
}

char ganhar(char jogada){
    if (jogada == 'A'){
        return 'B';
    }
    if (jogada == 'B'){
        return 'C';
    }
    if (jogada == 'C'){
        return 'A';
    }
}

int main(){
    FILE *partidas = fopen("input.txt", "r");

    char *partida = (char*) malloc(4*sizeof(char));
    char* retorno;
    int resultado, pontuacao = 0;
    char jogada;

    while (!feof(partidas)){
        retorno = fgets(partida, 5, partidas);

        if (retorno != NULL){

            if (partida[2] == 'X'){
                jogada = perder(partida[0]);
            }else if (partida[2] == 'Y'){
                jogada = partida[0];
            }else if (partida[2] == 'Z'){
                jogada = ganhar(partida[0]);
            }

            resultado = resultadoPartida(partida[0], jogada);

            if (resultado == 0){
                pontuacao += (jogada - 64);
            }else if (resultado == 1){
                pontuacao += 6 + (jogada - 64);
            }else{
                pontuacao += 3 + (jogada - 64);
            }
        }else{
            printf("ERRO NA LEITURA");
        }
    }

    printf("SUA PONTUACAO FINAL E: %d", pontuacao);
    
    fclose(partidas);
    return 0;
}