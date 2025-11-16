#ifndef FUNCOESMATRIZ_H
#define FUNCOESMATRIZ_H
#define MAX_TEXTO 100000
#define MAX 2

void gerarMat(int mat[MAX][MAX]);
int calcDet(int mat[MAX][MAX]);
void calcMatAdj(int mat[MAX][MAX], float matAdj[MAX][MAX]);
void calcMatInv(float matAdj[MAX][MAX], float matInv[MAX][MAX], int det);
void ler_e_pre_processar_texto(char* texto_buffer, int tamanho_max);

#endif // FUNCOESMATRIZ_H
