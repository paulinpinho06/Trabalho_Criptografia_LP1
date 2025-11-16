#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
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

int textoParaMatriz(char* texto, int mat_M[])
{
    int tamanho_texto = strlen(texto);
    int i; // Contador para o texto
    int j = 0; // Contador para a matriz M

    // Loop para converter cada caractere
    for (i = 0; i < tamanho_texto; i++)
    {
        char c = texto[i];
        
        if (c == '#') {
            mat_M[j] = 29; 
        } else {
           
            mat_M[j] = (c - 'A') + 1;
        }
        j++; // Avança para a próxima posição da matriz M
    }

    // Verifica o "Padding" 
    // Se o tamanho do texto (j) for ímpar, precisamos adicionar um '#' no final
    if (j % 2 != 0)
    {
        mat_M[j] = 29; // Adiciona o '#'
        j++;          
    }

    //Retorna o número de colunas da matriz M
    return j / 2;
}

void multiplicarMatrizes(int mat_A[MAX][MAX], int mat_M[], int mat_N[], int col_M)
{
    int i_vetor_M = 0; // Índice para percorrer o vetor M (anda de 2 em 2)

    // O loop 'c' itera por cada COLUNA da matriz M
    for (int c = 0; c < col_M; c++)
    {
        // Pega os dois números da coluna atual de M
        int m1 = mat_M[i_vetor_M];     // Linha 0
        int m2 = mat_M[i_vetor_M + 1]; // Linha 1

        // Agora, faz a multiplicação da Matriz A por esta coluna [m1, m2] 
        int n1 = (mat_A[0][0] * m1) + (mat_A[0][1] * m2);
        int n2 = (mat_A[1][0] * m1) + (mat_A[1][1] * m2);

        // Salva o resultado na matriz N
        mat_N[i_vetor_M] = n1;
        mat_N[i_vetor_M + 1] = n2;

        // Avança o índice do vetor por 2 (pois processamos 1 coluna = 2 elementos)
        i_vetor_M += 2;
    }
}

void multiplicarMatrizInversa(float mat_Inv[MAX][MAX], int mat_N[], float mat_M_temp[], int col_N)
{
    int i_vetor = 0; // Índice para percorrer os vetores (anda de 2 em 2)

    // O loop 'c' itera por cada COLUNA da matriz N
    for (int c = 0; c < col_N; c++)
    {
        // Pega os dois números da coluna atual de N
        int n1 = mat_N[i_vetor];
        int n2 = mat_N[i_vetor + 1];

        // Faz a multiplicação da Matriz Inversa por esta coluna [n1, n2]
        // O resultado é float, pois mat_Inv é float
        float m1_float = (mat_Inv[0][0] * n1) + (mat_Inv[0][1] * n2);
        float m2_float = (mat_Inv[1][0] * n1) + (mat_Inv[1][1] * n2);

        // Salva o resultado na matriz M temporária
        // (Não podemos salvar como int ainda, pois perdemos precisão)
        mat_M_temp[i_vetor] = m1_float;
        mat_M_temp[i_vetor + 1] = m2_float;

        // Avança o índice do vetor por 2
        i_vetor += 2;
    }
}

void matrizParaTexto(int mat_M[], char* texto, int tamanho_M)
{
    int i;
    for (i = 0; i < tamanho_M; i++)
    {
        int num = mat_M[i];
        
        if (num == 29) {
            texto[i] = '#'; // 29 é #
        } else {
            // Converte 1 para 'A', 2 para 'B', etc.
            // (num - 1) dá a posição (0-25)
            // Somamos 'A' para ter o caractere ASCII
            texto[i] = (num - 1) + 'A';
        }
    }
    // Adiciona o caractere nulo no final para fechar a string
    texto[i] = '\0';
}