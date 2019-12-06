#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "validacoes.h"
#include "menus.h"
#include <regex.h>



//=================================================     VALIDAÇÃO PARA LETRAS   ==================================================


int validaNome(char nome[100]) {

    regex_t reg;

    if((strlen(nome)) > 100) {

        return 0;

    } else {

        if(regcomp(&reg, RE_NAME, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, nome, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}




//================================================================ VALIDAÇÃO DE CPF ===================================================\\

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



int validaEmail(char* email) {

  int tam = strlen(email);
  int arroba = 0, ponto = 0, Aponto = 0, Dponto = 0, i;

  for (i = 0; i < tam; i++){
    char c = email[i];

    if(c == '@'){
      if (arroba)
        break;
      arroba = 1;
      if (i < 3)
        break;
    }
    else if (arroba){ 
      if (ponto){ 
        Dponto++;
      }
      else if (c == '.'){
        ponto = 1;
        if (Aponto < 3){
          break;
        }
      }
      else{
        Aponto++;
      }
    }
  } 

  if (i == tam && Dponto > 1)
    return 1;
  else
    return 0;
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



int validanumero(char* numero) {

    regex_t reg;

    if(strlen(numero) > 2) {

        return 0;

    }

    else {

        if(regcomp(&reg, RE_NUMBER, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, numero, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}
