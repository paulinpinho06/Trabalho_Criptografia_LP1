#ifndef FUNCOESMATRIZ_H
#define FUNCOESMATRIZ_H

#define MAX 2

void gerarMat(float mat[MAX][MAX]);
int calcDet(float mat[MAX][MAX]);
void calcMatAdj(float mat[MAX][MAX], float matAdj[MAX][MAX]);
void calcMatInv(float matAdj[MAX][MAX], float matInv[MAX][MAX], int det);

#endif // FUNCOESMATRIZ_H