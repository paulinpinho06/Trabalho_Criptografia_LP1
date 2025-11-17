#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void mostraMenu(char str_menu[])
{
    printf("%s", str_menu);
}

int obterOpcao(int n_opcoes) 
{
  int opcao, check;
  check = 0;
  do 
  {
    scanf("%d", &opcao);
    if (opcao <= 0 || opcao > n_opcoes) 
    {
      printf("\nEscolha inválida, por favor escolha um número presente no menu\n");
      check = 1;
    } 
    else
    {
      check=0;
    }
  } while (check);
    
  return opcao;
}