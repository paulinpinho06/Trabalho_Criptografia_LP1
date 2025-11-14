#include <stdio.h>
#include <stdlib.h>

void mostra_menu(char str_menu[]){
    printf("%s", str_menu);
}

int obter_opcao(int n_opcoes){
    int opcao,check;
    check = 0;
  do{
    scanf("%d", &opcao);
    if(opcao<=0 || opcao>n_opcoes){
        printf("\nescolha invalida, por favor escolha um numero presente no menu\n");
    check = 1;
    }else
        check=0;
  }while(check);
    
return opcao;
}