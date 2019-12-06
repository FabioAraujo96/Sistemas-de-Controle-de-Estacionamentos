#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "validacoes.h"


#include "menus.h"
//programa principal
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




    


