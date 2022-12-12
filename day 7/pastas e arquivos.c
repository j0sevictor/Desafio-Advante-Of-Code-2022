#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_PACOTE 50

void tabs(int quantidade){
    int i;
    for (i = 0; i < quantidade; i++){
        printf("   ");
    }
}

int tipoDoComando(char *comando, int tamanho){
    int i, j, k, contador=0;
    char listComandos[4][2] = {{'.', '.'}, {' ', '/'}, {'c', 'd'}, {'l', 's'}};
    /*
        1 - cd ..
        2 - cd /
        3 - cd
        4 - ls
        
        0:
            dir
            1232 arq
    */
    for (j = 0; j < 4; j++){
        for (i = 0; i < tamanho; i++){
            if (comando[i] == listComandos[j][contador]){
                contador++;
                if (contador == 2){
                    return j + 1;
                }
            }else if (comando[i] == listComandos[j][0]){
                contador = 1;
            }else{
                contador = 0;
            }
        }
    }

    return 0;
}


int main(){
    FILE *arquivo = fopen("input.txt", "r");
    char *comando = (char*) malloc(TAM_PACOTE*sizeof(char));
    char *resultado;
    int tamanho, dentroDe=0, tipoComando;
    int contador = 0;

    while (!feof(arquivo)){
        resultado = fgets(comando, TAM_PACOTE, arquivo);
        tamanho = strlen(comando);

        if (resultado != NULL){
            tipoComando = tipoDoComando(comando, tamanho);
            
            switch (tipoComando){
                case 1: 
                    dentroDe--;
                    tabs(dentroDe); 
                    printf("- %s", comando);
                break;
                
                case 2:
                    dentroDe = 1;
                    printf("- %s", comando);
                break;
                
                case 3:
                    dentroDe++;
                    tabs(dentroDe); 
                    printf("- %s", comando);
                break;
  
                case 0:
                    tabs(dentroDe); 
                    printf("- %s", comando);
                break;
            }
        }
     
    }

    fclose(arquivo);
    return 0;
}
