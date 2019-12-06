#include <stdio.h>                       //printf funções de entrada e  saida
#include <stdlib.h>                      //malloc alocação de memória 
#include <string.h>                      // copiar strings 
#include <time.h>                        // pega data e hora automática
#include <ctype.h>                       //uso para tranformar letras maiculas em minusculas 
#include "validacoes.h"                 // minha biblioteaca de assinaturas referentes  as minhas validações
#include "menus.h"                      //minha biblioteca de assinaturas referentes as funções de menus 

//===============================CADASTRANDO  CLIENTE CONVÊNIO ===============================================================

void cadastro_cliente_convenio(void){
    
    Clientecon* clienteC;
    char escolha, op;

      printf("==============================================\n");
      printf("------||| Cadastro cliente convênio |||-------\n");
      printf("==============================================\n");
      clienteC = (Clientecon*) malloc(sizeof(Clientecon));
      printf("\n Nome: ");
      scanf(" %49[^\n]", clienteC->nome);
      while(!(validaNome(clienteC->nome))){
        printf("Nome  inválido. Digite novamente: ");
        scanf(" %49[^\n]", clienteC->nome);
      }

      printf("\n CPF: ");
      scanf(" %12[^\n]", clienteC->cpf);
      while(!(validacpf(clienteC->cpf))){
        printf("CPF inválido. Digite novamente: ");
        scanf(" %12[^\n]", clienteC->cpf);
      }
      printf("\n Email: ");
      scanf(" %39[^\n]", clienteC->email);
        while(!(validaEmail(clienteC->email))){
        printf("Email inválido. Digite novamente: ");
        scanf(" %39[^\n]", clienteC->email);
      }
      
      printf("\n Rua: ");
      scanf(" %39[^\n]", clienteC->rua);
      while(!(validaNome(clienteC->rua))){
        printf("Nome  inválido. Digite novamente: ");
        scanf(" %39[^\n]", clienteC->rua);
      }
      
      printf("\n Bairro: ");
      scanf(" %39[^\n]", clienteC->bairro);
      
      
  
      printf("\n Cidade: ");
      scanf(" %39[^\n]", clienteC->cidade);
      while(!(validaNome(clienteC->cidade))){
        printf("Cidade inválido. Digite novamente: ");
        scanf(" %39[^\n]", clienteC->cidade);
      }
      
      printf("\n Estado: ");
      scanf(" %29[^\n]", clienteC->estado);
      while(!(validaNome(clienteC->estado))){
        printf("Estado inválido. Digite novamente: ");
        scanf(" %29[^\n]", clienteC->estado);
      }
      
      printf("\n Número da casa: ");
      scanf("%d", &clienteC->numeroCasa);
      
      printf("\n Tipo de veículo(Carro/Moto): ");
      scanf(" %19[^\n]", clienteC->tipoveiculo);
      
      printf("\n Modelo do veículo: ");
      scanf(" %39[^\n]", clienteC->modeloveiculo);
      
    
      printf("\n Placa do veículo: ");
      scanf(" %19[^\n]", clienteC->placa);
      clienteC->preco_acumulado=0;
      clienteC->status = '1';
      printf("\n");
      printf("===============================\n");
      exibe_convenio(clienteC);
      printf("===============================\n");
      gravaclicon(clienteC);
      printf("\n...Cliente cadastrado com sucesso...\n ");
      printf("Click >> V << para voltar: ");
      scanf("%s", &op);

}

//============================= cadastro entrada e saida do cliente avulso=====================================================

void cadastro_avulso_entrada() {
    char op;
    Contacon* contaCO;
    struct tm *hora;     
    time_t segundos;
    time(&segundos);   
    hora = localtime(&segundos);  

    printf("==============================================\n");
    printf("------------|||     ENTRADA ||| --------------\n");
    printf("==============================================\n");
    contaCO = (Contacon*) malloc(sizeof(Contacon));
    printf("\n Placa do veículo(LLL-NNNN): ");
    scanf(" %9[^\n]", contaCO->placa);
    contaCO-> dia= hora -> tm_mday;//dia
    contaCO->mes= hora ->tm_mon+1; //mês
    contaCO->ano= hora ->tm_year+1900; //ano
    contaCO-> horaEntrada= hora ->tm_hour; 
    contaCO-> minutoEntrada= hora ->tm_min; 
    contaCO-> horaSaida = 0;
    contaCO-> minutoSaida = 0;
    contaCO-> saiu = 'n';
    contaCO -> status = '1';
    printf("\n");
    grava_conta_convenio(contaCO);
    printf("\n... Registrado com sucesso...\n ");
    printf("Click >> V << para voltar: ");
    scanf("%s", &op);
    
}



void cadastro_avulso_saida(void) {
    char op;
    FILE* fp;
    int achou;
    char resp;
    char procurado[15];
     Contacon* contaCO;
     struct tm *hora;     

    time_t segundos;
    time(&segundos);   
    hora = localtime(&segundos);  
    

    printf("==============================================\n");
    printf("------------   ||| SAÍDA |||    --------------\n");
    printf("==============================================\n");
    
  fp = fopen("ContaConvenio.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("Informe o nome da placa do veículo: ");
  scanf(" %14[^\n]", procurado);
  contaCO = (Contacon*) malloc(sizeof(Contacon));
  achou = 0;
  while((!achou) && (fread(contaCO, sizeof(Contacon), 1, fp))) {
   if ((strcmp(contaCO->placa, procurado) == 0) && (contaCO->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {

    contaCO-> horaSaida = hora ->tm_hour;
    contaCO-> minutoSaida = hora ->tm_min;

    contaCO-> saiu = 's';
  
    
      contaCO->status = '1';
      fseek(fp, (-1)*sizeof(Contacon), SEEK_CUR);
      fwrite(contaCO, sizeof(Contacon), 1, fp);
  } else {
    printf("O Cliente não foi encontrado...\n");
  }
  free(contaCO);
  fclose(fp);
  
  float preco = calculapreco(contaCO ->horaEntrada,contaCO ->minutoEntrada,contaCO -> horaSaida, contaCO ->minutoSaida);
    printf("==============================\n");
    printf("%d/%d/%d\n", contaCO->dia, contaCO->mes,contaCO->ano);
    printf("o cliente entrou às %d:%d\n", contaCO->horaEntrada, contaCO->minutoEntrada);
    printf("saiu às %d:%d\n", contaCO->horaSaida, contaCO->minutoSaida);
    printf("Total a pagar: R$ %.2f\n",preco);
    printf("===============================\n");
    grava_conta_convenio(contaCO);
    printf("\n...Ticket cadastrado com sucesso...\n ");
    printf("Click >> V << para voltar: ");
    scanf("%s", &op);

 
}


//=============================================================================================================================================


//======================================== CÓDIGO DE ENTRADA DE CONVÊNIO ======================================================================
void cadastro_convenio_entrada(void) {
    char op;
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;
    Clientecon* clienteC;
    Contacon* contaCO;
    Contrato* cliente;
    struct tm *hora;     
    time_t segundos;
    time(&segundos);   
    char procurando [12];
    int achou=0, achou2=0;
    char placa[9];
    hora = localtime(&segundos);  
    fp1 = fopen("ClienteConvenio.dat", "rb");
    fp2 = fopen("ContaConvenio.dat", "r+b");
    fp3 = fopen("Contrato.dat","ab");

    if ((fp1 == NULL) && (fp2 == NULL) && (fp3 ==NULL)) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    printf("==============================================\n");
    printf("------------|||  ENTRADA ||| --------------\n");
    printf("==============================================\n");
    printf("\n Por Favor Digite o CPF do Cliente: ");
    scanf(" %15[^\n]", procurando);

    clienteC= (Clientecon*)malloc(sizeof(Clientecon));
    contaCO = (Contacon*) malloc(sizeof(Contacon));
    cliente = (Contrato*) malloc(sizeof(Contrato));

    while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp1))) {
      if((strcmp(clienteC->cpf, procurando) == 0) && (clienteC->status == '1')) {
            achou = 1;
        }
    }
    
    if (achou){

      while((!achou2) && (fread(contaCO, sizeof(Contacon), 1, fp2))) {
        if((strcmp(contaCO->cpf, clienteC->cpf) == 0) && (contaCO->status == '1')) {
            achou2 = 1;
        }

      }
    }

    if(achou2) {

        contaCO-> horaSaida = 0;
        contaCO-> minutoSaida = 0;

       contaCO-> horaEntrada= hora ->tm_hour; 
       contaCO-> minutoEntrada= hora ->tm_min; 
       
       contaCO-> dia= hora -> tm_mday;//dia
       contaCO->mes= hora ->tm_mon+1; //mês
       contaCO->ano= hora ->tm_year+1900; //ano
       contaCO-> horaEntrada= hora ->tm_hour; 
       contaCO-> minutoEntrada= hora ->tm_min; 
       contaCO-> saiu = 'n'; 

       fseek(fp2, (-1)*sizeof(Contacon), SEEK_CUR);
        fwrite(contaCO, sizeof(Contacon), 1, fp2);

       printf("\n... Registrado com sucesso...\n ");
       printf("Click >> V << para voltar: ");
       scanf("%s", &op);
    
    } else {

       strcpy(contaCO->cpf, clienteC->cpf);
       strcpy(contaCO->nome, clienteC->nome);
       strcpy(contaCO->placa, clienteC->placa);

        contaCO-> horaSaida = 0;
        contaCO-> minutoSaida = 0;

       contaCO-> horaEntrada= hora ->tm_hour; 
       contaCO-> minutoEntrada= hora ->tm_min; 
       
       contaCO-> dia= hora -> tm_mday;//dia
       contaCO->mes= hora ->tm_mon+1; //mês
       contaCO->ano= hora ->tm_year+1900; //ano
       contaCO-> horaEntrada= hora ->tm_hour; 
       contaCO-> minutoEntrada= hora ->tm_min; 
       contaCO-> saiu = 'n';
       contaCO -> status = '1';
       printf("\n");
       grava_conta_convenio(contaCO);
       strcpy(cliente->cpf, contaCO->cpf);
       strcpy(cliente->nome, contaCO->nome);
       strcpy(cliente->placa, contaCO->placa);
       gravacontrato(cliente);
       printf("\n... Registrado com sucesso...\n ");
       printf("Click >> V << para voltar: ");
       scanf("%s", &op);
      }  
      
fclose(fp1);
fclose(fp2);
fclose(fp3);
free(clienteC);
free(contaCO);
free(cliente);

}


//====================================CÓDIGO DE SAIDA DO CONVÊNIO =====================================
    
void cadastro_convenio_saida() {
    char op;
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;
    Clientecon* clienteC;
    Contrato* cliente;
    Contacon* contaCO;
    struct tm *hora;     
    time_t segundos;
    time(&segundos);   
    char procurando [12];
    int achou=0, achou2=0, achou3=0;
    char placa[9];
    hora = localtime(&segundos);  
    fp1 = fopen("ClienteConvenio.dat", "r+b");
    fp2 = fopen("ContaConvenio.dat", "r+b");
    fp3 = fopen("Contrato.dat","r+b");
    if ((fp1 == NULL) && (fp2 == NULL)&&(fp3 == NULL)) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }  

    printf("==============================================\n");
    printf("------------   ||| SAÍDA |||    --------------\n");
    printf("==============================================\n");
    printf("\n Por Favor Digite o CPF do Cliente: ");
    scanf(" %15[^\n]", procurando);
    clienteC= (Clientecon*)malloc(sizeof(Clientecon));
    contaCO = (Contacon*) malloc(sizeof(Contacon));
    cliente = (Contrato*) malloc(sizeof(Contrato));

    while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp1))) {
      if((strcmp(clienteC->cpf, procurando) == 0) && (clienteC->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
      while((!achou2) && (fread(contaCO, sizeof(Contacon), 1, fp2))) {
        if((strcmp(contaCO->cpf, clienteC->cpf) == 0) && (contaCO->status == '1')) {
            achou2 = 1;
        }
        if (achou2){ 

          contaCO-> horaSaida = hora ->tm_hour;
          contaCO-> minutoSaida = hora ->tm_min;
          contaCO-> saiu = 's';
          contaCO->status = '1';
          fseek(fp2, (-1)*sizeof(Contacon), SEEK_CUR);
          fwrite(contaCO, sizeof(Contacon), 1, fp2);
        
          float preco = calculapreco(contaCO ->horaEntrada,contaCO ->minutoEntrada,contaCO -> horaSaida, contaCO ->minutoSaida);
          clienteC->preco_acumulado += preco;
          printf("==============================\n");
          printf("%d/%d/%d\n", contaCO->dia, contaCO->mes,contaCO->ano);
          printf("o cliente entrou às %d:%d\n", contaCO->horaEntrada, contaCO->minutoEntrada);
          printf("saiu às %d:%d\n", contaCO->horaSaida, contaCO->minutoSaida);
          printf("Total a pagar: R$ %.2f\n",preco);
          printf("===============================\n");
          fseek(fp1, (-1)*sizeof(Clientecon), SEEK_CUR);
          fwrite(clienteC, sizeof(Clientecon), 1, fp1);
          printf("\n...Ticket cadastrado com sucesso...\n ");
          printf("Click >> V << para voltar: ");
          scanf("%s", &op);
          while((!achou3) && (fread(cliente, sizeof(Contrato), 1, fp3))) {
            if((strcmp(cliente->cpf, contaCO->cpf) == 0) && (cliente->status == '1')) {
             achou3 = 1;
            }
          }
        if (achou3){ 

          cliente->preco_acumulado = clienteC->preco_acumulado;
          fseek(fp3, (-1)*sizeof(Contrato), SEEK_CUR);
          fwrite(cliente, sizeof(Contrato), 1, fp3);
        }
        else{printf("\nO o cliente não foi encontrado\n ");
       }   
     }
    }
 }   
   
fclose(fp1);
fclose(fp2);
fclose(fp3);
free(clienteC);
free(contaCO);
free(cliente);
}



  
//=================================================================================================================================================================



char convenio_login(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("==== MENU USUARIO CONVÊNIO ====\n");
    printf("-------------------------------\n");
    printf("\n A- Cadastrar Cliente        \n");
    printf("\n B- Alterar dados            \n");
    printf("\n C- Retirar ticket           \n");
    printf("\n D- Exibir Cliente           \n");
    printf("\n V- Voltar                   \n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return toupper(escolha);
}

char op_menu_cliente(void){
   char op;
    printf("-------------------------------\n");
    printf("========= MENU CLIENTE ========\n");
    printf("-------------------------------\n");
    printf("\n A- Avulso\n");
    printf("\n B- Convênio\n");
    printf("\n V- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &op);

    return toupper(op);//
}


//funções que irão para o main

//Referente a cliente
char cliente_menu(void){
    char escolha;
    system("clear");
    

    do{
        switch(escolha=op_menu_cliente()){
            case 'A':
                cliente_menu_avulso();
            
                break;

            case 'B':
                cliente_menu_convenio();
            
                char op;
                break;

            default:

			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(escolha!='V');

        return escolha;
}
//===========================================================================================//

char cliente_menu_avulso(void){
    char escolha;
    system("clear");
    

    do{
        switch(escolha=avulso_menu()){
            case 'A':
                cadastro_avulso_entrada();
            
                break;

            case 'B':
                cadastro_avulso_saida();
            
                char op;
                break;
             case 'C':
                printf("implementando");
            
                break;    


			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(escolha!='V');

        return escolha;
}

char cliente_menu_convenio(void){
    char escolha;
    system("clear");
    

    do{
        switch(escolha=convenio_menu()){
            case 'A':
                cadastro_cliente_convenio();
            
                break;

            case 'B':
              altera_convenio();
             
                break;


            case 'C':
              cadastro_convenio_entrada();

                 break;
            case 'D':
              cadastro_convenio_saida();

                 break;
            case 'E':
                pagamento_cliete_convenio();
                printf("\nDigite Enter para Continuar: ");
                getchar();
                getchar();

                 break;
            case 'F':
                excluirconvenio();

                 break;
            case 'V':

                break;
            default:

			       printf("\n");
			       printf(">>>Opção errada. Digite uma opção válida: ");
			       printf("\n");
             break;

    

        }
        getchar();
    }     
    while(escolha!='V');

    return escolha;
}



// menu empresa 
char empresa_menu(void){
    char escolha;
    system("clear");
    printf("---------------------------------------\n");
    printf("============== MENU EMPRESA ===========\n");
    printf("---------------------------------------\n");
    printf("\n A- Lista Direta Clientes\n");
    printf("\n B- Lista Indireta Clientes\n");
    printf("\n C- Lista Ordenada Clientes\n");
    printf("\n D- Exibir Clientes\n");
    printf("\n E- Registro de Atividade (dia,Mês,Ano)\n");
    printf("\n V- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:   \n");
    scanf(" %c", &escolha);


    return toupper(escolha);
}

char convenio_menu(void){
    char escolha;
    system("clear");
    printf("---------------------------------------\n");
    printf("=========== CLIENTE CONVÊNIO ==========\n");
    printf("---------------------------------------\n");
    printf("\n A- Cadastrar\n");
    printf("\n B- Alterar\n");
    printf("\n C- Entrada\n");
    printf("\n D- Saída\n");
    printf("\n E- Pagamento\n");
    printf("\n F- Excluir\n");
    printf("\n V- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:   \n");
    scanf(" %c", &escolha);
 
    return toupper(escolha);
}

char avulso_menu(void){
    char escolha;
    system("clear");
    printf("---------------------------------------\n");
    printf("============= CLIENTE AVULSO ==========\n");
    printf("---------------------------------------\n");
    printf("\n A- Entrada\n");
    printf("\n B- Saída\n");
    printf("\n V- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:   \n");
    scanf(" %c", &escolha);


    return toupper(escolha);
}




//Referente a empresa 
char administrador_menu(){
    char escolha;
    UsClientecon* lista;
    system("clear");
    
    comparando_loginadm();
    do{
        switch(escolha=empresa_menu()){
            case 'A':
               lista = listaDiretaclientes();
               exibeLista(lista);
               printf("\nDigite Enter para Continuar: ");
               getchar();
               getchar();
  
                break;

            case 'B':

              listaInvertidaconvenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();

                
                break;
            case 'C':
              
              listaOrdenadaconvenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
               
                break;

            case 'D':

            exibir_cliente_convenio();

              

                break;

            case 'E':

            cliente_empresa_relatorio();
              

                break;
            
    

            default:

			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(escolha!='V');

        return escolha;
}



// navegação para relatório de clientes

char cliente_empresa_relatorio(void){
    char escolha;
    system("clear");
    

    do{
        switch(escolha=regristroAtividade()){
            case 'A':
              lista_dia_convenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
            
                break;

            case 'B':
              lista_mes_convenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
            
             
                break;


            case 'C':
              lista_ano_convenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
            


                 break;
           
     

            default:

			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(escolha!='V');

        return escolha;
}

//====================================================================================================//

// navegação para relatório de clientes

char cliente_empresa_lucro(void){
    char escolha;
    system("clear");
    

    do{
        switch(escolha=lucro()){
            case 'A':
              lista_dia_convenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
            
                break;

            case 'B':
              printf("em construção");
             
                break;


            case 'C':
                printf("em construção");

                 break;
           
     

            default:

			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(escolha!='V');

        return escolha;
}

//====================================================================================================//



//=======================================T ELAS DE MENU ================================================
char imp_menu(void){
    char escolha;

    system("clear");
    printf("------------------------------\n");
    printf("======  MENU PRINCIPAL =======\n");
    printf("------------------------------\n");
    printf("\n A- Cliente \n ");
    printf("\n B- Empresa \n");
    printf("\n C- Sobre \n");
    printf("\n S- Sair \n");
    printf("------------------------------\n");
    printf("Por favor digite sua escolha: \n");
    scanf(" %c", &escolha);

    return toupper(escolha);
}
 
//login principal(esta tela será o login funcionário e administrador do programa)

void comparando_loginfun(void){ 
  FILE* fp;
  Loginfun* login;
  fp = fopen("LoginFuncionario.dat", "r+b");
  if (fp == NULL) {
     imp_login();
  }
  else {
    login_cadastrado_fun();
    
  }

}

void comparando_loginadm(void){ 
  FILE* fp;
  Loginfun* login;
  fp = fopen("LoginAdministrador.dat", "r+b");
  if (fp == NULL) {
     adm_login();
  }
  else {
    login_cadastrado_adm();
    
  }
  
}


char imp_login(){
    char escolha;
    Loginfun* login;

    system("clear");
    printf("-------------------------------------------\n");
    printf("======== BEM VINDO(A) AO CARS FLOW ========\n");
    printf("-------------------------------------------\n");
    login = (Loginfun*) malloc(sizeof(Loginfun));
    printf("ATENÇÃO usuario: admin , senha: admin\n");
    printf("Por favor para continuar faça login : \n");
    printf("Usuário: \n");
    scanf(" %49[^\n]", login->usuario);
    printf("Senha: \n");
    scanf(" %29[^\n]", login->senha);
    login_funcionario();
  
    return escolha;

}

//função criada para quando o arquivo funcionário ja tiver algo cadastrado 
char login_cadastrado_fun(void){
    char escolha;
    Loginfun* login;
    char usuario[50];
    char senha[30];
    system("clear");
    printf("-------------------------------------------\n");
    printf("======== BEM VINDO(A) AO CARS FLOW ========\n");
    printf("-------------------------------------------\n");
    login = (Loginfun*) malloc(sizeof(Loginfun));
    printf("Por favor para continuar faça login : \n");
    printf("Usuário: \n");
    scanf("%49[^\n]", usuario);
    printf("Senha: \n");
    scanf(" %29[^\n]", senha);
    
    return escolha;

}


char adm_login(){
    char escolha;
    LoginAdmin* login;

    system("clear");
    printf("-------------------------------------------\n");
    printf("======== LOGIN ADMINISTRADOR ========\n");
    printf("-------------------------------------------\n");
    login = (LoginAdmin*) malloc(sizeof(LoginAdmin));
    printf("ATENÇÃO usuario: admin , senha: admin\n");
    printf("Por favor para continuar faça login : \n");
    printf("Usuário: \n");
    scanf(" %49[^\n]", login->usuario);
    printf("Senha: \n");
    scanf(" %29[^\n]", login->senha);
    login_administrador();
  
    return escolha;

}


//função criada para quando o arquivo administrador ja tiver algo cadastrado 
char login_cadastrado_adm(void){
    char escolha;
    LoginAdmin* login;
    char usuario[50];
    char senha[30];
    system("clear");
    printf("-------------------------------------------\n");
    printf("======== BEM VINDO(A) AO CARS FLOW ========\n");
    printf("-------------------------------------------\n");
    login = (LoginAdmin*) malloc(sizeof(LoginAdmin));
    printf("Por favor para continuar faça login : \n");
    printf("Usuário: \n");
    scanf(" %49[^\n]", login->usuario);
    printf("Senha: \n");
    scanf(" %29[^\n]", login->senha);
    
  
    return escolha;

}

//================================================== FUNÇÃO QUE MOSTRA O SOBRE =====================================================//

void sobre_menu(void){
  system("clear");
    printf("------------------------------------------------------------------------------------\n");
    printf("================================       SOBRE        ================================\n");
    printf("------------------------------------------------------------------------------------\n"); 
    printf("UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE\n");
    printf(">>> Sistema de controle de Estacionamentos <<<\n");
    printf("Nome: Cars Flow\n"); 
    printf("Criador: Fábio Araújo \n");
    printf("Contato:(84) 9 8819-5543\n"); 
    printf("Email: fabioaraujo.js@hotmail.com\n");
    printf("Endereço do Git:https://github.com/FabioAraujo96\n");
    printf("O Cars Flow é um programa criado por um aluno do 2º periodo de sistemas de Informação\n");
    printf("Professor orientador: Flávius Gorgônio\n");
    printf("Disciplina: Programação\n");
    printf("-------------------------------------------------------------------------------------\n"); 
    
}


//=======================================================================================================================================

//segundas telas de empresa  >>em construção<




// função para menu de registro de atividades da empresa 
char regristroAtividade(void){
    char escolha;
    system("clear");
    printf("---------------------------------\n");
    printf("== MENU REGISTRO DE ATIVIDADES ==\n");
    printf("---------------------------------\n");
    printf("\n A- Dia\n");
    printf("\n B- Mês\n");
    printf("\n C- Ano\n");
    printf("\n V- Voltar\n");
    printf("---------------------------------\n");
    printf("Por favor digite sua escolha:    \n");
    scanf(" %c", &escolha);

    return toupper(escolha);

}

// função de menu para lucro da empresa
char lucro(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("========== MENU LUCRO =========\n");
    printf("-------------------------------\n");
    printf("\n A- Dia\n");
    printf("\n B- Mês\n");
    printf("\n C- Ano\n");
    printf("\n V- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return toupper(escolha);
    
}

//===================================FUNÇÃO PARA EDIÇÃO DE CLIENTE CONVÊNIO=====================================
void altera_convenio(void) {
  FILE* fp;
  Clientecon* clienteC;
  int achou;
  char resp;
  char procurado[15];
  fp = fopen("ClienteConvenio.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("Informe o nome CPF do veículo: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->cpf, procurado) == 0) && (clienteC->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibe_convenio(clienteC);
    printf("Deseja realmente Alterar este Cliente (s/n)? ");
    scanf(" %c", &resp);
    if (resp == 's' || resp == 'S') {
      printf("\n Nome: ");
      scanf(" %49[^\n]", clienteC->nome);
      while(!(validaNome(clienteC->nome))){
        printf("Nome inválido. Digite novamente: ");
        scanf(" %49[^\n]", clienteC->nome);
      }
      printf("\n CPF: ");
      scanf(" %15[^\n]", clienteC->cpf);
      while(!(validacpf(clienteC->cpf))){
        printf("CPF inválido. Digite novamente: ");
        scanf(" %15[^\n]", clienteC->cpf);
      }
      printf("\n Email: ");
      scanf(" %39[^\n]", clienteC->email);
      while(!(validaEmail(clienteC->email))){
        printf("Email inválido. Digite novamente: ");
        scanf(" %39[^\n]", clienteC->email);
      }
      
      printf("\n Rua: ");
      scanf(" %39[^\n]", clienteC->rua);
      while(!(validaNome(clienteC->rua))){
        printf("Nome inválido. Digite novamente: ");
        scanf(" %39[^\n]", clienteC->rua);
      }
     
      printf("\n Bairro: ");
      scanf(" %39[^\n]", clienteC->bairro);
      while(!(validaNome(clienteC->bairro))){
      printf("Nome inválido. Digite novamente: ");
      scanf(" %39[^\n]", clienteC->bairro);
      }
     
  
      printf("\n Cidade: ");
      scanf(" %39[^\n]", clienteC->cidade);
      while(!(validaNome(clienteC->cidade))){
        printf("Cidade  inválida. Digite novamente: ");
        scanf(" %39[^\n]", clienteC->cidade);
      }
      
      printf("\n Estado: ");
      scanf(" %29[^\n]", clienteC->estado);
      while(!(validaNome(clienteC->estado))){
        printf("Estado inválido. Digite novamente: ");
        scanf(" %49[^\n]", clienteC->estado);
      }
      
      printf("\n Número da casa: ");
      scanf("%d", &clienteC->numeroCasa);
      
      printf("\n Tipo de veículo(Carro/Moto): ");
      scanf(" %19[^\n]", clienteC->tipoveiculo);
      
      
      printf("\n Modelo do veículo: ");
      scanf(" %39[^\n]", clienteC->modeloveiculo);
      
      printf("\n Placa do veículo: ");
      scanf(" %19[^\n]", clienteC->placa);
      clienteC->status = '1';
      fseek(fp, (-1)*sizeof(Clientecon), SEEK_CUR);
      fwrite(clienteC, sizeof(Clientecon), 1, fp);
      printf("\nCliente Alterado  com sucesso!!!\n");

    } else {
      printf("\nOk, os dados não foram alterados\n");
    }
  } else {
    printf("O Cliente  %s não foi encontrado...\n", procurado);
  }
  free(clienteC);
  fclose(fp);
  
}

// funções de exibição 
// exibe cliente convênio
void exibe_convenio(Clientecon* clienteC) {
  
  printf("Nome: %s\n", clienteC->nome);
  printf("CPF: %s\n", clienteC->cpf);
  printf("Email: %s\n", clienteC->email);
  printf("Rua: %s\n", clienteC->rua);
  printf("Bairro: %s\n", clienteC->bairro);
  printf("Cidade: %s\n", clienteC->cidade);
  printf("Estado: %s\n", clienteC->estado);
  printf("Número da casa:%d\n", clienteC->numeroCasa);
  printf("Tipo de Veículo: %s\n", clienteC->tipoveiculo);
  printf("Modelo do Veículo %s\n", clienteC->modeloveiculo);
  printf("Placa do  Veículo: %s\n", clienteC->placa);
  printf("Status: %c\n", clienteC->status);
  printf("\n");
  

  printf("\n");
}


void exibe_conta_convenio(Contacon* contaCO) {
  printf("Placa do  Veículo: %s\n", contaCO->placa);
  printf("==============================\n");
  printf("%d/%d/%d\n", contaCO->dia, contaCO->mes,contaCO->ano);
  printf("o cliente entrou às %d:%d\n", contaCO->horaEntrada, contaCO->minutoEntrada);
  printf("saiu às %d:%d\n", contaCO->horaSaida, contaCO->minutoSaida);
  printf("===============================\n");
  printf("Status: %c\n", contaCO->status);
  printf("\n");
  
}

// função exibir cliente
void exibir_cliente_convenio(void) {
  FILE* fp;
  Clientecon* clienteC;
  int achou;
  char procurado[15];
  fp = fopen("ClienteConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("================================\n");
  printf("==== EXIBE CLIENTE CONVÊNIO ====\n");
  printf("================================\n");
  printf("Informe o CPF do Cliente: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->cpf, procurado) == 0) && (clienteC->status == '1')) {
     achou = 1;
   }
  }
  fclose(fp);
  if (achou) {
    exibe_convenio(clienteC);
    printf("Digite Enter para sair");
    getchar();
    getchar();
  
  } else {
    printf("O CPF  %s não foi encontrado...\n", procurado);
  }
  free(clienteC);
}

//listar clientes

void lista_clientecon(void) {
  FILE* fp;
  Clientecon* clienteC;
  fp = fopen("ClienteConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  
  printf("===== CLIENTES CONVÊNIO=====\n");
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  while(fread(clienteC, sizeof(Clientecon), 1, fp)) {
    if (clienteC->status == '1') {
      exibe_convenio(clienteC);
    }
  }
  fclose(fp);
  free(clienteC);
  
}

//===============================================================================================================
  
//=======================================função para pegar a hora e a data====================================
void data_hora(void) {

  struct tm *hora;     
  time_t segundos;
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  hora = localtime(&segundos);  
  
  printf("%d/", hora->tm_mday);//dia
  printf("%d/",hora->tm_mon+1); //mês
  printf("%d\n",hora->tm_year+1900); //ano



  printf("%d:",hora->tm_hour);//hora   
  printf("%d:",hora->tm_min);//minuto


}

//=================================================================================================================

// função calcula valor estacionamento
float calculapreco(int horaEntrada,int minutoEntrada,int horaSaida,int minutoSaida){

int difHoras= horaSaida - horaEntrada;
int difminutos = minutoSaida - minutoEntrada;

float precominuto = 0.05 * difminutos;
float precoHora = (difHoras * 60) *0.05;

float precototal = precominuto + precoHora;

return precototal;

}

//=================================================================================================================


//===============================FUNÇÃO PARA EXCLUIR PESSOA CADASTRADA=============================================
void excluirconvenio(void) {
  FILE* fp;
  Clientecon* clienteC;
  int achou;
  char resp;
  char procurado[15];
  fp = fopen("ClienteConvenio.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("----------------------- \n");
  printf("    EXCLUIR CLIENTE      \n");
  printf("------------------------\n");
  printf("Informe o CPF do cliente a ser ecluido: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->cpf, procurado) == 0) && (clienteC->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibe_convenio(clienteC);
    getchar();
    printf("Deseja realmente excluir este cliente (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      clienteC->status = '0';
      fseek(fp, (-1)*sizeof(Clientecon), SEEK_CUR);
      fwrite(clienteC, sizeof(Clientecon), 1, fp);
      printf("\nCliente  excluído com sucesso!!!\n");
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O CPF %s não foi encontrado...\n", procurado);
  }
  free(clienteC);
  fclose(fp);
  getchar();
  getchar();
}

//========================FUNÇÃO PARA PAGAMENTO ===================================================
void pagamento_cliete_convenio(void) {
    char op;
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;
    Clientecon* clienteC;
    Contrato* cliente;
    Contacon* contaCO;
    struct tm *hora;     
    time_t segundos;
    time(&segundos);   
    char procurando [12];
    int achou=0, achou2=0, achou3=0;
    char placa[9];
    hora = localtime(&segundos);  
    fp1 = fopen("ClienteConvenio.dat", "r+b");
    fp2 = fopen("ContaConvenio.dat", "r+b");
    fp3 = fopen("Contrato.dat","r+b");
    if ((fp1 == NULL) && (fp2 == NULL) && (fp3 == NULL)) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }  

    printf("==============================================\n");
    printf("------------   ||| PAGAMENTO |||    --------------\n");
    printf("==============================================\n");
    printf("\n Por Favor Digite o CPF do Cliente: ");
    scanf(" %15[^\n]", procurando);

    clienteC= (Clientecon*)malloc(sizeof(Clientecon));
    contaCO = (Contacon*) malloc(sizeof(Contacon));
    cliente = (Contrato*) malloc(sizeof(Contrato));

    while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp1))) {
      if((strcmp(clienteC->cpf, procurando) == 0) && (clienteC->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
      while((!achou2) && (fread(contaCO, sizeof(Contacon), 1, fp2))) {
        if((strcmp(contaCO->cpf, clienteC->cpf) == 0) && (contaCO->status == '1')) {
            achou2 = 1;
         }
        }
      
    }
        if (achou2){ 
          while((!achou3) && (fread(cliente, sizeof(Contrato), 1, fp3))) {
            if((strcmp(cliente->cpf, contaCO->cpf) == 0) && (cliente->status == '1')) {
              achou3 = 1;

            }
          }

        }

          if (achou3){ 

            printf("==============================\n");
            printf("Nome do Cliente: %s\n", clienteC->nome);
            printf("CPF do cliente: %s\n", clienteC->cpf);
            printf("Total a pagar: R$ %.2f\n",cliente->preco_acumulado);
            printf("===============================\n");
            printf("valor pago\n");
            clienteC-> preco_acumulado = 0;
            contaCO ->preco_acumulado = 0;
            
            cliente->preco_acumulado = 0;
            fseek(fp1, (-1)*sizeof(Clientecon), SEEK_CUR);
            fwrite(clienteC, sizeof(Clientecon), 1, fp1);

            fseek(fp2, (-1)*sizeof(Contacon), SEEK_CUR);
            fwrite(contaCO, sizeof(Contacon), 1, fp2);

            fseek(fp3, (-1)*sizeof(Contrato), SEEK_CUR);
            fwrite(cliente, sizeof(Contrato), 1, fp3);
          
          } 
          else{
            printf("\nO o cliente não foi encontrado\n ");
          }      
   
fclose(fp1);
fclose(fp2);
fclose(fp3);
free(clienteC);
free(contaCO);
free(cliente);
}

//=======================================================================================================

//==========================FUNÇÕES DE GRAVAÇÃO DE ARQUIVOS===============================================

//FUNÇÃO QUE GRAVA LOGIN FUNCIONÁRIO 
void gravaLoginfun(Loginfun* clienteC) {
  FILE* fp;
  fp = fopen("ClienteConvenio.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(clienteC, sizeof(Clientecon), 1, fp);
  fclose(fp);
}

//=======================FUNÇÃO QUE GRAVA CLIENTE CONVÊNIO ============================================
void gravaclicon(Clientecon* clienteC) {
  FILE* fp;
  fp = fopen("ClienteConvenio.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(clienteC, sizeof(Clientecon), 1, fp);
  fclose(fp);
}



//============================FUNÇAO QUE GRAVA CONTRATO==================================================
void gravacontrato(Contrato* cliente) {
  cliente->status = '1';
  FILE* fp;
  fp = fopen("Contrato.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(cliente, sizeof(Contrato), 1, fp);
  fclose(fp);
}

//=========================FUNÇÃO QUE GRAVA CONTA CONVÊNIO==================================================
void grava_conta_convenio(Contacon* contaCO) {
  FILE* fp;
  fp = fopen("ContaConvenio.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(contaCO, sizeof(Contacon), 1, fp);
  fclose(fp);
}

//==========================FUNÇÃO QUE GRAVA=================================>>>>ICOMPRIENSÃO<<<<<
void gravafun(Loginfun* login) {
  FILE* fp;
  fp = fopen("LoginFuncionario.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(login, sizeof(Loginfun), 1, fp);
  fclose(fp);
}


//======================== FUNÇÃO QUE GRAVA LOGIN ADMINISTRADOR =====================================
void gravaadm(LoginAdmin* login) {
  FILE* fp;
  fp = fopen("LoginAdministrador.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(login, sizeof(LoginAdmin), 1, fp);
  fclose(fp);
}

//===================função para registrar usuario e senha de funcionáro==============================
void login_funcionario(void){
  Loginfun* login;
  printf("--Por favor crie seu usuario e senha--\n");
  login = (Loginfun*) malloc(sizeof(Loginfun));
  printf("Usuário: \n");
  scanf(" %49[^\n]", login->usuario);
  printf("Senha: \n");
  scanf(" %29[^\n]", login->senha);
  login->status = '1';
  printf("===============================\n");
  gravafun(login);
  printf("\n...usuaŕio e senha cadastrado com sucesso...\n ");
  getchar();
  printf("aperte ENTER para continuar");
}

//=====================função para registrar usuario e senha do administrador ==========================
void login_administrador(void){
  LoginAdmin* login;
  printf("--Por favor crie seu usuario e senha--\n");
  login = (LoginAdmin*) malloc(sizeof(LoginAdmin));
  printf("Usuário: \n");
  scanf(" %49[^\n]", login->usuario);
  printf("Senha: \n");
  scanf(" %29[^\n]", login->senha);
  login->status = '1';
  printf("===============================\n");
  gravaadm(login);
  printf("\n...usuaŕio e senha cadastrado com sucesso...\n ");
  getchar();
  printf("aperte ENTER para continuar");

}


//======================FUNÇÕES PARA LISTA DE CLIENTES POR DATA(DIA,MÊS,ANO)========================================================
void lista_dia_convenio(void) {
  FILE* fp;
  Contacon* contaCO;
  int achou;
  int diaProcurando;
  int mesProcurando;
  int anoProcurando;
  fp = fopen("ContaConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("================================\n");
  printf("====    CLIENTES POR DIA    ====\n");
  printf("================================\n");
  printf("Informe a data nesse formato (__/__/__): ");
  scanf(" %d/%d/%d", &diaProcurando,&mesProcurando,&anoProcurando);
  contaCO = (Contacon*) malloc(sizeof(Contacon));
  while(fread(contaCO, sizeof(Contacon), 1, fp)) {
    
     if (diaProcurando == contaCO ->dia && mesProcurando == contaCO -> mes && anoProcurando == contaCO -> ano && contaCO->status == '1') {
          exibe_conta_convenio(contaCO);
     }
      else {
      printf("Data inválida(ou não existe ou o usuario digitou errado)  %d/%d/%d \n", diaProcurando,mesProcurando,anoProcurando);}
  }
  fclose(fp); 
  free(contaCO);
}


//lista cliente mês
void lista_mes_convenio(void) {
  FILE* fp;
  Contacon* contaCO;
  int achou;
  int diaProcurando;
  int mesProcurando;
  int anoProcurando;
  fp = fopen("ContaConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("================================\n");
  printf("====    CLIENTES POR MÊS    ====\n");
  printf("================================\n");
  printf("Informe apenas o mês e o ano (__/__): ");
  scanf(" %d/%d", &mesProcurando,&anoProcurando);
  contaCO = (Contacon*) malloc(sizeof(Contacon));
  while(fread(contaCO, sizeof(Contacon), 1, fp)) {
    
     if (mesProcurando == contaCO -> mes && anoProcurando == contaCO -> ano && contaCO->status == '1'){ 
            exibe_conta_convenio(contaCO);
     }
      else 
          {printf("Data inválida(ou não existe ou o usuario digitou errado) %d/%d \n",mesProcurando,anoProcurando); }
  }
  
  fclose(fp); 
  free(contaCO);
  }


// lista clirnte ano
void lista_ano_convenio(void) {
  FILE* fp;
  Contacon* contaCO;
  int achou;
  int diaProcurando;
  int mesProcurando;
  int anoProcurando;
  fp = fopen("ContaConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("================================\n");
  printf("====    CLIENTES POR ANO    ====\n");
  printf("================================\n");
  printf("Informe apenas  o ano : ");
  scanf(" %d",&anoProcurando);
  contaCO = (Contacon*) malloc(sizeof(Contacon));
  while(fread(contaCO, sizeof(Contacon), 1, fp)) {
    
     if ( anoProcurando == contaCO -> ano && contaCO->status == '1') {
        exibe_conta_convenio(contaCO);
     } 
     else {
        printf("Data inválida(ou não existe ou o usuario digitou errado) %d \n",anoProcurando);
      } 
  }
    
  fclose(fp); 
  free(contaCO);
}

//======================================================================================================================================

//=================================LISTAS DINÂMICAS=====================================================================================
UsClientecon* listaInvertidaconvenio(void) {
  FILE* fp;
  Clientecon* clienteC;
  UsClientecon* usclientecon;
  UsClientecon* lista;

  lista = NULL;
  fp = fopen("ClienteConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  while(fread(clienteC, sizeof(Clientecon), 1, fp)) {
    if (clienteC->status == '1') {
      usclientecon = (UsClientecon*) malloc(sizeof(UsClientecon));
      strcpy(usclientecon->nome, clienteC->nome);
      strcpy(usclientecon->cpf, clienteC->cpf);
      strcpy(usclientecon->email, clienteC->email);
      strcpy(usclientecon->rua, clienteC->rua);
      strcpy(usclientecon->bairro, clienteC->bairro);
      strcpy(usclientecon->cidade, clienteC->cidade);
      strcpy(usclientecon->estado, clienteC->estado);
      usclientecon->numeroCasa = clienteC->numeroCasa;
      strcpy(usclientecon->tipoveiculo, clienteC->tipoveiculo);
      strcpy(usclientecon->modeloveiculo, clienteC->modeloveiculo);
      strcpy(usclientecon->placa, clienteC->placa);
      usclientecon->status = clienteC->status;
      usclientecon->prox = lista;
      lista = usclientecon;
    }
  }
  fclose(fp);
  exibeLista(lista);
  free(clienteC);
  liberaLista(lista);
}


UsClientecon* listaOrdenadaconvenio(void) {
  FILE* fp;
  Clientecon*clienteC ;
  UsClientecon* usclientecon;
  UsClientecon* lista;

  lista = NULL;
  fp = fopen("ClienteConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  clienteC= (Clientecon*) malloc(sizeof(Clientecon));
  while(fread(clienteC, sizeof(Clientecon), 1, fp)) {
    if (clienteC->status == '1') {
      usclientecon = (UsClientecon*) malloc(sizeof(UsClientecon));
      strcpy(usclientecon->nome, clienteC->nome);
      strcpy(usclientecon->cpf, clienteC->cpf);
      strcpy(usclientecon->email, clienteC->email);
      strcpy(usclientecon->rua, clienteC->rua);
      strcpy(usclientecon->bairro, clienteC->bairro);
      strcpy(usclientecon->cidade, clienteC->cidade);
      strcpy(usclientecon->estado, clienteC->estado);
      usclientecon->numeroCasa = clienteC->numeroCasa;
      strcpy(usclientecon->tipoveiculo, clienteC->tipoveiculo);
      strcpy(usclientecon->modeloveiculo, clienteC->modeloveiculo);
      strcpy(usclientecon->placa, clienteC->placa);
      usclientecon->status = clienteC->status;
      if (lista == NULL) {
        lista = usclientecon;
        usclientecon->prox = NULL;
      } else if (strcmp(usclientecon->nome,lista->nome) < 0) {
        usclientecon->prox = lista;
        lista = usclientecon;
      } else {
        UsClientecon* anter = lista;
        UsClientecon* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,usclientecon->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = usclientecon;
        usclientecon->prox = atual;
      }
    }
  }
  fclose(fp);
  exibeLista(lista);
  free(clienteC);
  liberaLista(lista);
}


 


// criando lista dinâmica em ordem direta 
UsClientecon* listaDiretaclientes(void) {
  FILE* fp;
  Clientecon* clienteC;
  UsClientecon* usclientecon;
  UsClientecon* lista;
  UsClientecon* ultimo;

  lista = NULL;
  fp = fopen("ClienteConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  while(fread(clienteC, sizeof(Clientecon), 1, fp)) {
    if (clienteC->status == '1') {
      usclientecon = (UsClientecon*) malloc(sizeof(UsClientecon));
      strcpy(usclientecon->nome, clienteC->nome);
      strcpy(usclientecon->cpf, clienteC->cpf);
      strcpy(usclientecon->email, clienteC->email);
      strcpy(usclientecon->rua, clienteC->rua);
      strcpy(usclientecon->bairro, clienteC->bairro);
      strcpy(usclientecon->cidade, clienteC->cidade);
      strcpy(usclientecon->estado, clienteC->estado);
      usclientecon->numeroCasa = clienteC->numeroCasa;
      strcpy(usclientecon->tipoveiculo, clienteC->tipoveiculo);
      strcpy(usclientecon->modeloveiculo, clienteC->modeloveiculo);
      strcpy(usclientecon->placa, clienteC->placa);
      usclientecon->status = clienteC->status;
      usclientecon->prox = NULL;
      if (lista == NULL) {
        lista = usclientecon;
      } else {
        ultimo->prox = usclientecon;
      }
      ultimo = usclientecon;
    }
  }
  fclose(fp);
  free(clienteC);
  return lista;
}




// função exibe lista dinamica direta//
void exibeLista(UsClientecon* lista) {
  printf("\n\n");
  printf("=========================== \n");
  printf("==   CLIENTES CONVÊNIO   == \n");
  printf("=========================== \n");
  while (lista != NULL) {
    printf("Nome: %s\n", lista->nome);
    printf("CPF: %s\n", lista->cpf);
    printf("Email:%s\n", lista->email);
    printf("Rua: %s\n", lista->rua);
    printf("Bairro: %s\n", lista->bairro);
    printf("Cidade: %s\n", lista->cidade);
    printf("Estado: %s\n", lista->estado);
    printf("Número da casa:%d\n", lista->numeroCasa);
    printf("Tipo de Veículo: %s\n", lista->tipoveiculo);
    printf("Modelo do Veículo %s\n", lista->modeloveiculo);
    printf("Placa do  Veículo: %s\n", lista->placa);
    printf("Status: %c\n", lista->status);
    printf("\n");
    lista = lista->prox;
  }
}

void liberaLista(UsClientecon* lista){
  UsClientecon* aux = lista;
  while (lista != NULL) {
		lista = lista->prox;
		free(aux);
		aux = lista;
	}
}

//=====================================================================================================================================
