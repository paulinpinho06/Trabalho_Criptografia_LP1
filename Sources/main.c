#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Headers/funcoesMatriz.h"
#include "../Headers/menu.h"
#include max_texto
int main()
{   
    int mat_criada = 0;
    int texto_pronto = 0;
    int texto_cifrado = 0;
    int mat[2][2],opcao,det;
    float matInv[2][2],matAdj[2][2];
    char texto_original[max_texto] = ""; // Texto de entrada
    char texto_crip[max_texto] = ""; // Texto de saída
    char str_menu[] =    "Digite a opcao desejada\n"
                         "1. Criar uma matriz de criptografia.\n"
                         "2. Digitar um texto para ser criptografado.\n"
                         "3. Criptografar Texto.\n"
                         "4. Descriptografar Texto.\n"
                         "5. Sair.\n";


    do{
        mostra_menu(str_menu);
        opcao = obter_opcao(5);
        switch(opcao){
            case 1:
                printf("\n--- 1. Criar Matriz de Criptografia ---\n");
                gerarMat(mat);
                det = calcDet(mat);
                calcMatAdj(mat, matAdj);
                calcMatInv(matAdj, matInv, det);
                mat_criada = 1;
                printf("Matriz de criptografia e inversa criadas com sucesso!\n");
            break;
            case 2:
                printf("\n--- 2. Criar Texto Original ---\n");
                printf("Digite o texto (max %d caracteres): ", max_texto - 1);
                scanf("%s", texto_original);
                texto_pronto = 1;
                texto_cifrado = 0;
                printf("Texto original definido: %s\n", texto_original);

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:
                printf("fim do programa\n");
            break;
        }  
    
    }while(opcao !=5);
    
return 0;
}
