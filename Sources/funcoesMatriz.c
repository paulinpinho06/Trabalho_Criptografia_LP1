#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Headers/funcoesMatriz.h"

void gerarMat(int mat[MAX][MAX])
{
    int det = 0;
    srand(time(NULL));
    while (det == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                mat[i][j] = rand() % 10; // Gera números aleatórios entre 0 e 9
            }
        }
        det = calcDet(mat);
        if(det == 0){
            printf("Determinante é zero, gerando nova matriz...\n");  
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