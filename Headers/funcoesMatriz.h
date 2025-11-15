#ifndef FUNCOESMATRIZ_H
#define FUNCOESMATRIZ_H
#define max_texto 100000
#define MAX 2

void gerarMat(int mat[MAX][MAX]);
int calcDet(int mat[MAX][MAX]);
void calcMatAdj(int mat[MAX][MAX], float matAdj[MAX][MAX]);
void calcMatInv(float matAdj[MAX][MAX], float matInv[MAX][MAX], int det);

#endif // FUNCOESMATRIZ_H
