#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Headers/funcoesMatriz.h"
#include "../Headers/menu.h"

int main()
{  
    int mat_criada = 0;
    int texto_pronto = 0;
    int texto_cifrado = 0; 
   
    char texto_original[MAX_TEXTO] = ""; // Texto de entrada
    char texto_crip[MAX_TEXTO] = ""; // Texto de saída
    
    int mat[2][2],opcao,det;
    float matInv[2][2],matAdj[2][2];
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
                texto_cifrado = 0;
                 printf("Matriz de criptografia e inversa criadas com sucesso!\n");
            break;
            case 2: 
                 printf("\n--- 2. Criar Texto Original ---\n");
                printf("Digite o texto (max %d caracteres): ", MAX_TEXTO - 1);
               ler_e_pre_processar_texto(texto_original, MAX_TEXTO);
                if (strlen(texto_original) > 0){
                   
                    texto_pronto = 1;
                    texto_cifrado = 0; // Invalida criptografia anterior
                    printf("Texto original definido (pré-processado): %s\n", texto_original);
                    printf("Tamanho do texto: %zu\n", strlen(texto_original));
                } else {
                    texto_pronto = 0;
                    printf("Texto não definido ou inválido.\n");
                }
                
            break;
            case 3:
                if (mat_criada == 0){
                    printf("Voce precisa criar uma matriz de criptografia primeiro!\n");
                    break; // Volta ao menu
                } 
                else if(texto_pronto == 0){
                    printf("Voce precisa digitar um texto para ser criptografado primeiro!\n");
                    break; // Volta ao menu 

                }
                else {
                    //chamar funcao de criptografar (FALTA FAZER)
                    texto_cifrado = 1; // Sinaliza que o texto foi criptografado
                }
            break;
            case 4:
                if (mat_criada == 0){
                    printf("Voce precisa criar uma matriz de criptografia primeiro!\n");
                    break; // Volta ao menu
                }
                else if(texto_cifrado == 0){
                    printf("Voce precisa criptografar um texto primeiro!\n");
                    break; // Volta ao menu
                }
                else {
                    //chamar funcao de descriptografar (FALTA FAZER)
                }
            break;
            case 5:
                printf("Fim do programa\n");
            break;
        }  
    
    }while(opcao !=5);
    
return 0;
}
