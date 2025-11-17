#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include "funcoesMatriz.h"
#include "menu.h"

int main()
{  
    setlocale(LC_ALL, "");

    int mat_criada = 0;
    int texto_pronto = 0;
    int texto_cifrado = 0; 
   
    char texto_original[MAX_TEXTO] = ""; // Texto de entrada
    int mat_M_numerica[MAX_TEXTO];      // Guarda os números do texto (ex: 16, 12, 1, 14...)
    int mat_N_criptografada[MAX_TEXTO]; // Guarda os números criptografados (ex: 61, 65, 4, 45...)
    int num_colunas_M = 0;              // Guarda o número de colunas da matriz M
    
    int mat[2][2],opcao,det;
    float matInv[2][2],matAdj[2][2];
    char str_menu[] =    "\n========== MENU ==========\n"
                         "\n1. Criar uma matriz de criptografia.\n"
                         "2. Digitar um texto para ser criptografado.\n"
                         "3. Criptografar Texto.\n"
                         "4. Descriptografar Texto.\n"
                         "5. Sair.\n"
                         "\nDigite a opção desejada: ";


    do {
        mostraMenu(str_menu);
        opcao = obterOpcao(5);
        switch(opcao)
        {
            case 1:
                printf("\n--- 1. Criar Matriz de Criptografia ---\n");
                gerarMat(mat);
                det = calcDet(mat);
                calcMatAdj(mat, matAdj);
                calcMatInv(matAdj, matInv, det);    
                mat_criada = 1;
                texto_cifrado = 0;
                 printf("\nMatriz de criptografia e inversa criadas com sucesso!\n");
                break;
            case 2: 
                printf("\n--- 2. Criar Texto Original ---\n");
                printf("\nDigite o texto (máx. %d caracteres): ", MAX_TEXTO - 1);
                lerTexto(texto_original, MAX_TEXTO);
                if (strlen(texto_original) > 0) 
                {
                    texto_pronto = 1;
                    texto_cifrado = 0; // Invalida criptografia anterior
                    printf("\nTexto original definido (pré-processado): %s\n", texto_original);
                    printf("\nTamanho do texto: %zu\n", strlen(texto_original));
                } 
                else 
                {
                    texto_pronto = 0;
                    printf("\nTexto não definido ou inválido.\n");
                }               
                break;
            case 3:
                if (mat_criada == 0)
                {
                    printf("\nVocê precisa criar uma matriz de criptografia primeiro!\n");
                    break; // Volta ao menu
                } 
                else if (texto_pronto == 0) 
                {
                    printf("\nVocê precisa digitar um texto para ser criptografado primeiro!\n");
                    break; // Volta ao menu
                }
                else 
                {
                    printf("\n--- 3. Criptografando Texto ---\n");
                    
                    // Converte o texto (string) para a matriz M (números)
                    // Também adiciona o '#' (padding) se necessário.
                    num_colunas_M = textoParaMatriz(texto_original, mat_M_numerica);

                    // Multiplica A * M = N
                    multiplicarMatrizes(mat, mat_M_numerica, mat_N_criptografada, num_colunas_M);

                    // Mostra os resultados
                    printf("\nTexto Original: %s\n", texto_original);
                    
                    printf("\nTexto Criptografado (Matriz N): ");
                    int tamanho_N = num_colunas_M * 2; // O vetor N tem o dobro de colunas
                    for (int i = 0; i < tamanho_N; i++) 
                    {
                        printf("%d", mat_N_criptografada[i]);
                        if (i < tamanho_N - 1) 
                        {
                            printf(", "); // Adiciona vírgulas
                        }
                    }
                    printf("\n");
                    texto_cifrado = 1; // Sinaliza que o texto foi criptografado
                }
                break;
            case 4:
                if (mat_criada == 0)
                {
                    printf("\nVocê precisa criar uma matriz de criptografia primeiro!\n");
                    break; // Volta ao menu
                }
                else if (texto_cifrado == 0)
                {
                    printf("\nVocê precisa criptografar um texto primeiro!\n");
                    break; // Volta ao menu
                }
                else 
                {
                    printf("\n--- 4. Descriptografando Texto ---\n");
                    int tamanho_N = num_colunas_M * 2;
                    
                    // Cria buffers para a descriptografia
                    float mat_M_temporaria[tamanho_N];
                    int mat_M_decodificada[tamanho_N];
                    char texto_decodificado[tamanho_N + 1]; // +1 para o '\0'

                    // Multiplica A^-1 * N = M (com floats)
                    multiplicarMatrizInversa(matInv, mat_N_criptografada, mat_M_temporaria, num_colunas_M);

                    // Arredonda os floats para inteiros
                    // Isso corrige pequenos erros de precisão (ex: 15.999 vira 16)
                    for (int i = 0; i < tamanho_N; i++) 
                    {
                        mat_M_decodificada[i] = round(mat_M_temporaria[i]);
                    }

                    // Converte a matriz de números M de volta para texto
                    matrizParaTexto(mat_M_decodificada, texto_decodificado, tamanho_N);

                    // Mostra os resultados
                    printf("\nTexto Criptografado (Matriz N): ");
                    for (int i = 0; i < tamanho_N; i++) 
                    {
                        printf("%d", mat_N_criptografada[i]);
                        if (i < tamanho_N - 1) 
                        {
                            printf(", ");
                        }
                    }
                    printf("\n");

                    printf("\nTexto Descriptografado: %s\n", texto_decodificado);
                }
                break;
            case 5:
                printf("\nFim do programa\n");
                break;
        }    
    } while (opcao !=5);

    return 0;
}
