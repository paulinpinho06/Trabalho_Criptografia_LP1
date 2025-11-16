#ifndef FUNCOESMATRIZ_H
#define FUNCOESMATRIZ_H
#define MAX_TEXTO 100000
#define MAX 2

void gerarMat(int mat[MAX][MAX]);
int calcDet(int mat[MAX][MAX]);
void calcMatAdj(int mat[MAX][MAX], float matAdj[MAX][MAX]);
void calcMatInv(float matAdj[MAX][MAX], float matInv[MAX][MAX], int det);
void ler_e_pre_processar_texto(char* texto_buffer, int tamanho_max);
int textoParaMatriz(char* texto, int mat_M[]);
void multiplicarMatrizes(int mat_A[MAX][MAX], int mat_M[], int mat_N[], int col_M);
void multiplicarMatrizInversa(float mat_Inv[MAX][MAX], int mat_N[], float mat_M_temp[], int col_N);
void matrizParaTexto(int mat_M[], char* texto, int tamanho_M); //Inverso de textoParaMatriz

#endif // FUNCOESMATRIZ_H
