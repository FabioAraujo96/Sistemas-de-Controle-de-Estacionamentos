#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include "menus.h"

//programa principal
int main (void){
    char menu_principal;
	char escolha;
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
				break;
			case 'D':
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
	while(menu_principal != 'D');
	return 0;
}




    


