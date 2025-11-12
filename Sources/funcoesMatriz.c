#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoesMatriz.h"

void gerarMat(int mat[MAX][MAX])
{
    srand(time(NULL));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mat[i][j] = rand() % 10; // Gera números aleatórios entre 0 e 9
        }
    }
}

int calcDet(int mat[MAX][MAX])
{
    int det;

    det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

    while (det == 0)
    {
        printf("Determinante é zero, gerando nova matriz...\n");
        gerarMat(mat);
        det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }

    return det;
}

void calcMatAdj(int mat[MAX][MAX], int matAdj[MAX][MAX])
{
    matAdj[0][0] = mat[1][1];
    matAdj[0][1] = -mat[0][1];
    matAdj[1][0] = -mat[1][0];
    matAdj[1][1] = mat[0][0];
}

void calcMatInv(int matAdj[MAX][MAX], int matInv[MAX][MAX], int det)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matInv[i][j] = matAdj[i][j]/det;
        }
    }
}