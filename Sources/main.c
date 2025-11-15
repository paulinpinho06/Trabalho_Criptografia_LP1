#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Headers/funcoesMatriz.h"
#include "../Headers/menu.h"

int main()
{
    int mat[2][2],opcao,det;
    float matInv[2][2],matAdj[2][2];
    char str_menu[] =    "Digite a opcao desejada\n"
                         "1. Criar uma matriz de criptografia.\n"
                         "2. Digitar um texto para ser criptografado.\n"
                         "3. Criptografar Texto.\n"
                         "4. Descriptografar Texto.\n"
                         "5. Sair.\n";

    int matrizPronta = 0;
    int textoCriptografado = 0;
    do{
        mostra_menu(str_menu);
        opcao = obter_opcao(5);
        switch(opcao){
            case 1:
                gerarMat(mat);
                det = calcDet(mat);
                calcMatAdj(mat, matAdj);
                calcMatInv(matAdj, matInv, det);    
                matrizPronta = 1;
                textoCriptografado = 0;
            break;
            case 2:

            break;
            case 3:
                if (matrizPronta == 0){
                    printf("Voce precisa criar uma matriz de criptografia primeiro!\n");
                    break; // Volta ao menu
                
                } else {
                    //chamar funcao de criptografar (FALTA FAZER)
                    textoCriptografado = 1; // Sinaliza que o texto foi criptografado
                }
            break;
            case 4:
                if (matrizPronta == 0){
                    printf("Voce precisa criar uma matriz de criptografia primeiro!\n");
                    break; // Volta ao menu
                }
                else if(textoCriptografado == 0){
                    printf("Voce precisa criptografar um texto primeiro!\n");
                    break; // Volta ao menu
                }
                else {
                    //chamar funcao de descriptografar (FALTA FAZER)
                }
            break;
            case 5:
                printf("fim do programa\n");
            break;
        }  
    
    }while(opcao !=5);
    
return 0;
}