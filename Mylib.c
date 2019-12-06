#include <stdio.h>                       //printf funções de entrada e  saida
#include <stdlib.h>                      //malloc alocação de memória 
#include <string.h>                      // copiar strings 
#include <time.h>                        // pega data e hora automática
#include <ctype.h>                       //uso para tranformar letras maiculas em minusculas 
#include "validacoes.h"                 // minha biblioteaca de assinaturas referentes  as minhas validações
#include "menus.h"                      //minha biblioteca de assinaturas referentes as funções de menus 

//===================================== MENU PTOGRAMA PRINCIPAL =================================================
int main (void){
	
    char menu_principal;
	char escolha;
	comparando_loginfun();
	do {

		switch(menu_principal = imp_menu()) {
			
			case 'A':
				cliente_menu();
				break;
			case 'B':
				administrador_menu();
				break;
			case 'C':
				sobre_menu();
				getchar();
				getchar();
				break;
			case 'S':
				printf("\n");
				printf(" Obrigado por ultilizar nossos serviços.Volte sempre.\n");
				printf("\n");
				break;
			default:
			    printf("\n");
				printf(">>>Opção errada. Digite uma opção válida: ");
				printf("\n");
		}
    }		
	while(menu_principal != 'S');
	return 0;
}




    


