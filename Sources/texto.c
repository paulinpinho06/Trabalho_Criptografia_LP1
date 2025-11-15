#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/texto.h"
#include "../Headers/menu.h"

int le_texto(int *n_caracteres, int matriz_texto[2][100]){
    int opcao;
    char texto[100];
    char str_menu[] =    "Digite a opcao desejada\n"
                         "1. Digitar um texto.\n"
                         "2. Digitar uma matriz para ser descriptografada.\n"
                         "3. Sair.\n";
    
    do{
        mostra_menu(str_menu);
        opcao=obter_opcao(3);
        getchar();
        switch(opcao){
            case 1:
                printf("Digite o texto: ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = '\0';
                *n_caracteres = strlen(texto);
                converte_minuscula(texto);
                converte_texto(texto, &*n_caracteres, matriz_texto);
                return 0;   
            case 2:
                printf("\nDigite o numero de colunas da matriz: ");
                scanf("%d", &*n_caracteres);
                *n_caracteres = (*n_caracteres)*2;
                for(int i=0;i<2;i++){
                    for(int j=0;j<*n_caracteres/2;j++){
                        printf("Digite o valor da linha %d na coluna %d da matriz A\n", i+1, j+1);
                        scanf("%d", &matriz_texto[i][j]);             
                    }
                }
                return 1;   
            case 3:
            printf("\n Retornando ao menu");
            break;
        }
    }while (opcao!=3);    
return 0;            
}

void converte_minuscula (char *frase)
{
    for(int t=0; frase[t]; ++t)
    {
    frase[t]=(tolower(frase[t]));
    }
}

void converte_texto(char texto[], int *n_caracteres, int matriz_texto[2][100])
{
    char tabela_alfabeto[] = "abcdefghijklmnopqrstuvwxyz.,#";
    int k;
    k = 0;

    for (int i = 0; texto[i]; i++){
        if (texto[i] == ' '){
            texto[i] = '#';
        }
    }

    if(*n_caracteres % 2 != 0){
        texto[*n_caracteres] = '#';
        texto[*n_caracteres + 1] = '\0';
        (*n_caracteres)++;
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<*n_caracteres/2;j++){          
            for(int l=0; l < 30 ;l++){
                if(texto[k]==tabela_alfabeto[l]){
                    matriz_texto[i][j] = l;
                    break;
                }
            }
            k++;
        } 
            
    }

}