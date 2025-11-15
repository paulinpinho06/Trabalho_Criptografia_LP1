#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Headers/criptografia.h"

void criptografia(int *n_caracteres, float matriz[2][2], int texto_criptografado[2][100], int textoCriptografado){

    int matriz_texto[2][100];
    char tabela_alfabeto[] = "abcdefghijklmnopqrstuvwxyz.,#";

    for(int i=0;i<2;i++){
        for(int j=0;j<*n_caracteres/2;j++){
            matriz_texto[i][j]=texto_criptografado[i][j];
        }
    }

    for (int j = 0; j < *n_caracteres/2; j++) {
        texto_criptografado[0][j] = (int)round(matriz[0][0] * matriz_texto[0][j] + matriz[0][1] * matriz_texto[1][j]);
        texto_criptografado[1][j] = (int)round(matriz[1][0] * matriz_texto[0][j] + matriz[1][1] * matriz_texto[1][j]);
    
    }
    if(textoCriptografado == 0){
        for(int i=0;i<2;i++){
            for(int j=0;j<*n_caracteres/2;j++){
                printf(" %d", texto_criptografado[i][j]+1);
            }
            printf("\n");
        } 
    }
    else{    
        for(int i=0;i<2;i++){
            for(int j=0;j<*n_caracteres/2;j++){
                printf("%c", tabela_alfabeto[texto_criptografado[i][j]]);   
            }
        }
        printf("\n");
    }
       
}