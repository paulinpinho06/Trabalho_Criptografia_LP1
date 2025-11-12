#ifndef FUNCOESMATRIZ_H
#define FUNCOESMATRIZ_H

#define MAX 2

void gerarMat(int mat[MAX][MAX]);
int calcDet(int mat[MAX][MAX]);
void calcMatAdj(int mat[MAX][MAX], int matAdj[MAX][MAX]);
void calcMatInv();

#endif // FUNCOESMATRIZ_H