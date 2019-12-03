#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "validacoes.h"
#include "menus.h"




//===========================      VALIDAÇÃO PARA LETRAS   ==========================\\

int valid_alfabetica(char* nome){
	int tamanho = strlen(nome);
	for(int i = 0; i < tamanho; i++){
		if(!(nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == ' '){
		return 0;
		}
	}
	
return 1;
}

//=============================================== VALIDAÇÃO DE CPF =====================\\

int chartoint(char c){
    return c - '0';
}

char inttochar(int n){
  return n + 48;
}

int cpfJaExiste(char* cpf){
  int encontrado = 0;
  FILE* fp;
  Clientecon* clienteC;
  fp = fopen("ClienteConvenio.dat","rb");
  if(fp == NULL){
    return 0;
  } else{
    clienteC = (Clientecon*) malloc(sizeof(Clientecon));
    while((!encontrado) && (fread(clienteC, sizeof(Clientecon), 1, fp))){
      if((strcmp(clienteC->cpf, cpf) == 0) && (clienteC->status == 'c')){
        encontrado = 1;
      }
    }
    fclose(fp);
    free(clienteC);
    if(encontrado){
      return 1;
    } else{
      return 0;
    }
  }
}

int validacpf(char * cpf){
	int tamanho = strlen(cpf);
	if(tamanho != 11){
    return 0;
  }
  else{
    if(cpfJaExiste(cpf)){
      return 0;
    } else{
      int num;
      int soma1 = 0;
      char digito1, digito2;
      int j = 0;
      for(int i = 10; i >= 2; i--){
        num = chartoint(cpf[j]);
        num *= i;
        soma1 += num;
        j++;
      }
      soma1 = soma1 % 11;
      soma1 = 11 - soma1;
      if(soma1 > 9)
        soma1 = 0;
      digito1 = inttochar(soma1);
      if(digito1 != cpf[9])
        return 0;
      else{
        j = 0;
        soma1 = 0;
        for(int i = 11; i >= 2; i--){
          num = chartoint(cpf[j]);
          num *= i;
          soma1 += num;
          j++;
        }
        soma1 = soma1 % 11;
        soma1 = 11 - soma1;
        if(soma1 > 9)
          soma1 = 0;
        digito2 = inttochar(soma1);
        if(digito2 != cpf[10])
          return 0;
        else
          return 1;
      }
    }
  }
}




int validaloginfunusuario(char* usuario) {
  FILE* fp;
  Loginfun* login;
  int achou = 0;
  
  fp = fopen("LoginFuncionário.dat", "rb");
  if (fp == NULL) {
    return 0;
  }
  login = (Loginfun*) malloc(sizeof(Loginfun));
  while((!achou) && (fread(login, sizeof(Loginfun), 1, fp))) {
    
     if ((strcmp(login->usuario, usuario) == 0) && (login->status == '1'))

    {
     achou = 1;
   }
  }
  fclose(fp); 
  if (achou) {
    return 1;
    
  
  } else {
    return 0;
  }
  free(login);
}



/*int validaloginfunusuario(char* usuario){
  int encontrado = 0;
  FILE* fp;
  Loginfun* login;
  fp = fopen("LoginFuncionario.dat","rb");
  if(fp == NULL){
    return 0;
  } else{
    login = (Loginfun*) malloc(sizeof(Loginfun));
    while((!encontrado) && (fread(login, sizeof(Loginfun), 1, fp))){
      if((strcmp(login->usuario,usuario) && (login->status == '1'))){
        encontrado = 1;
      }
    }
    fclose(fp);
    free(login);
    if(encontrado){
      return 1;
    } else{
      return 0;
    }
  }
}*/