#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoesMatriz.h"

void main()
{
    int mat[2][2], matAdj[2][2], matInv[2][2];
    gerarMat(mat);
    int det = calcDet(mat);
    calcMatAdj(mat, matAdj);
    calcMatInv(matAdj, matInv, det);

    printf("Matriz Original:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Determinante: %d\n", det);

    printf("Matriz Adjacente:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", matAdj[i][j]);
        }
        printf("\n");
    }
    
    printf("Matriz Inversa:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", matInv[i][j]);
        }
        printf("\n");
    }
}