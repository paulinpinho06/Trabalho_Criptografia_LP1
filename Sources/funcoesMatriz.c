#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "../Headers/funcoesMatriz.h"

void gerarMat(int mat[MAX][MAX])
{
    int det = 0;
    srand(time(NULL));
    while (det != 1 && det != -1)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                mat[i][j] = rand() % 10; // Gera números aleatórios entre 0 e 9
            }
        }
        det = calcDet(mat);
        if(det !=1 && det != -1){
            printf("Determinante é %d. Gerando nova matriz (buscando det 1 ou -1)...\n", det);
        }
        
    }
    printf("Matriz Original:\n"); 
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int calcDet(int mat[MAX][MAX])
{
    int det;
    det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

return det;
}

void calcMatAdj(int mat[MAX][MAX], float matAdj[MAX][MAX])
{
    matAdj[0][0] = mat[1][1];
    matAdj[0][1] = -mat[0][1];
    matAdj[1][0] = -mat[1][0];
    matAdj[1][1] = mat[0][0];

    printf("Matriz Adjacente:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.1f ", matAdj[i][j]);
        }
        printf("\n");
    }
}

void calcMatInv(float matAdj[MAX][MAX], float matInv[MAX][MAX], int det)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matInv[i][j] = matAdj[i][j]/det;
        }
    }

    printf("Matriz Inversa:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.1f ", matInv[i][j]);
        }
        printf("\n");
    }
}

void ler_e_pre_processar_texto(char* texto_buffer, int tamanho_max) {

    int c_lixo;
    while ((c_lixo = getchar()) != '\n' && c_lixo != EOF); // Limpa o buffer de entrada

    if(fgets(texto_buffer, tamanho_max, stdin) == NULL) // Lê a linha inteira do usuário (seguro contra overflow)
    {
        texto_buffer[0] = '\0'; // Em caso de erro, define o texto como vazio
        return;
    }

    texto_buffer[strcspn(texto_buffer, "\n")] = '\0'; // Remove a nova linha lida pelo fgets
    
    for (int i = 0, j = 0; texto_buffer[i] != '\0'; i++){

        char c = texto_buffer[i];

        c = toupper (c); // Converte para maiúscula

        if (c >= 'A' && c <= 'Z'){ // Verifica se é uma letra maiúscula
            texto_buffer[i] = c; // Mantém apenas letras maiúsculas
        }
        else {
            texto_buffer[i] = '#'; // Substitui caracteres não alfabéticos por '#'
        }
    }
}