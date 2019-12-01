#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include "validacoes.h"
#include "menus.h"




//telas referentes ao menu principal 

void cadastro_cliente_convenio(){
    Clientecon* clienteC;
    char escolha, op;

      printf("==============================================\n");
      printf("------||| Cadastro cliente convênio |||-------\n");
      printf("==============================================\n");
      clienteC = (Clientecon*) malloc(sizeof(Clientecon));
      printf("\n Nome: ");
      scanf(" %49[^\n]", clienteC->nome);
      printf("\n CPF: ");
      scanf(" %15[^\n]", clienteC->cpf);
      printf("\n Celular: ");
      scanf("%d", &clienteC->celular);
      printf("\n Rua: ");
      scanf(" %29[^\n]", clienteC->rua);
      printf("\n Bairro: ");
      scanf(" %29[^\n]", clienteC->bairro);
      printf("\n Cidade: ");
      scanf(" %29[^\n]", clienteC->cidade);
      printf("\n Estado: ");
      scanf(" %29[^\n]", clienteC->estado);
      printf("\n Número da casa: ");
      scanf("%d", &clienteC->numeroCasa);
      printf("\n Tipo de veículo(Carro/Moto): ");
      scanf(" %19[^\n]", clienteC->tipoveiculo);
      printf("\n Modelo do veículo: ");
      scanf(" %19[^\n]", clienteC->modeloveiculo);
      printf("\n Placa do veículo: ");
      scanf(" %19[^\n]", clienteC->placa);
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
//=================== cadastro entrada e saida do cliente avulso ===============================

void cadastro_avulso_entrada() {
    char op;
     Contaavul* contaAV;
     struct tm *hora;     
     
      
     
     
    time_t segundos;
    time(&segundos);   
    hora = localtime(&segundos);  

    printf("==============================================\n");
    printf("------------|||     ENTRADA ||| --------------\n");
    printf("==============================================\n");
    contaAV = (Contaavul*) malloc(sizeof(Contaavul));
    printf("\n Placa do veículo(LLL-NNNN): ");
    scanf(" %9[^\n]", contaAV->placa);
    contaAV-> dia= hora -> tm_mday;//dia
    contaAV->mes= hora ->tm_mon+1; //mês
    contaAV->ano= hora ->tm_year+1900; //ano
    contaAV-> horaEntrada= hora ->tm_hour; 
    contaAV-> minutoEntrada= hora ->tm_min; 
    contaAV-> horaSaida = 0;
    contaAV-> minutoSaida = 0;

    contaAV-> saiu = 'n';
    contaAV -> status = '1';
    contaAV->status = '1';
    printf("\n");
    printf("===============================\n");
    exibe_conta_avulso(contaAV);
    printf("===============================\n");
    grava_conta_avulso(contaAV);
    printf("\n... Registrado com sucesso...\n ");
    printf("Click >> V << para voltar: ");
    scanf("%s", &op);

  
    
}

void cadastro_avulso_saida() {
    char op;
    FILE* fp;
    int achou;
    char resp;
    char procurado[15];
     Contaavul* contaAV;
     struct tm *hora;     

    time_t segundos;
    time(&segundos);   
    hora = localtime(&segundos);  
    

    printf("==============================================\n");
    printf("------------   ||| SAÍDA |||    --------------\n");
    printf("==============================================\n");
    
  fp = fopen("ContaAvulso.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("Informe o nome da placa do veículo: ");
  scanf(" %14[^\n]", procurado);
  contaAV = (Contaavul*) malloc(sizeof(Contaavul));
  achou = 0;
  while((!achou) && (fread(contaAV, sizeof(Contaavul), 1, fp))) {
   if ((strcmp(contaAV->placa, procurado) == 0) && (contaAV->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibe_conta_avulso(contaAV);

    contaAV-> horaSaida = hora ->tm_hour;
    contaAV-> minutoSaida = hora ->tm_min;

    contaAV-> saiu = 's';
  
    
      contaAV->status = '1';
      fseek(fp, (-1)*sizeof(Contaavul), SEEK_CUR);
      fwrite(contaAV, sizeof(Contaavul), 1, fp);
  } else {
    printf("O Cliente não foi encontrado...\n");
  }
  free(contaAV);
  fclose(fp);
  
  float preco = calculapreco(contaAV ->horaEntrada,contaAV ->minutoEntrada,contaAV -> horaSaida, contaAV ->minutoSaida);
    printf("==============================\n");
    printf("%d/%d/%d\n", contaAV->dia, contaAV->mes,contaAV->ano);
    printf("o cliente entrou às %d:%d\n", contaAV->horaEntrada, contaAV->minutoEntrada);
    printf("saiu às %d:%d\n", contaAV->horaSaida, contaAV->minutoSaida);
    printf("Total a pagar: R$ %.2f\n",preco);
    printf("===============================\n");
    grava_conta_avulso(contaAV);
    printf("\n...Ticket cadastrado com sucesso...\n ");
    printf("Click >> V << para voltar: ");
    scanf("%s", &op);

  

 
}

//=============================================================================================================================================


//========================== cadastro entrada e saida cliente convenio =================================================================
void cadastro_convenio_entrada(void) {
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
    contaCO ->preco_acumulado = 0;


    contaCO-> saiu = 'n';
    contaCO->status = '1';
    printf("\n");
    printf("===============================\n");
    exibe_conta_convenio(contaCO);
    printf("===============================\n");
    grava_conta_convenio(contaCO);
    printf("\n... Registrado com sucesso...\n ");
    printf("Click >> V << para voltar: ");
    scanf("%s", &op);

    
  
}

// funao para saida do convênio\\

void cadastro_convenio_saida(void) {
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
    //exibe_convenio(contaCO);

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
  contaCO ->preco = calculapreco(contaCO ->horaEntrada,contaCO ->minutoEntrada,contaCO -> horaSaida, contaCO ->minutoSaida);
  contaCO ->valortotal =contaCO->preco_acumulado += contaCO ->preco;
    printf("==============================\n");
    printf("%d/%d/%d\n", contaCO->dia, contaCO->mes,contaCO->ano);
    printf("o cliente entrou às %d:%d\n", contaCO->horaEntrada, contaCO->minutoEntrada);
    printf("saiu às %d:%d\n", contaCO->horaSaida, contaCO->minutoSaida);
    printf("Total a pagar: R$ %.2f\n",contaCO ->preco);
    printf("===============================\n");
    grava_conta_convenio(contaCO);
    printf("\n...Ticket cadastrado com sucesso...\n ");
    printf("Click >> V << para voltar: ");
  
    scanf("%s", &op);

  
    
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

            case'B':
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

            case'B':
                cadastro_avulso_saida();
            
                char op;
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
    

    do{https:
        switch(escolha=convenio_menu()){
            case 'A':
                cadastro_cliente_convenio();
            
                break;

            case'B':
              altera_convenio();
             
                break;


            case'C':
                cadastro_convenio_entrada();

                 break;
            case'D':
                cadastro_convenio_saida();

                 break;
            case'E':
                pagamento_cliete_convenio();
                printf("\nDigite Enter para Continuar: ");
                getchar();
                getchar();

                 break;
            case'F':
                excluirconvenio();

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




// menu empresa 
char empresa_menu(void){
    char escolha;
    system("clear");
    printf("---------------------------------------\n");
    printf("============== MENU EMPRESA ===========\n");
    printf("---------------------------------------\n");
    printf("\n A- Listar Clientes \n");
    printf("\n B- Exibir Clientes\n");
    printf("\n C- Registro de Atividade (dia,Mês,Ano)\n");
    printf("\n D- Lucro(Dia,Mês,Ano\n");
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

            case'B':
              exibir_cliente_convenio();
               
                
                break;
            case 'C':
               cliente_empresa_relatorio();
                break;

            case 'D':
              cliente_empresa_lucro();

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
    

    do{https:
        switch(escolha=regristroAtividade()){
            case 'A':
              lista_dia_convenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
            
                break;

            case'B':
              lista_mes_convenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
            
             
                break;


            case'C':
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
    

    do{https:
        switch(escolha=lucro()){
            case 'A':
              lista_dia_convenio();
              printf("\nDigite Enter para Continuar: ");
              getchar();
              getchar();
            
                break;

            case'B':
              printf("em construção");
             
                break;


            case'C':
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










//menu principal
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

    system("clear");
    printf("-------------------------------------------\n");
    printf("======== BEM VINDO(A) AO CARS FLOW ========\n");
    printf("-------------------------------------------\n");
    login = (Loginfun*) malloc(sizeof(Loginfun));
    printf("Por favor para continuar faça login : \n");
    printf("Usuário: \n");
    scanf(" %49[^\n]", login->usuario);
    printf("Senha: \n");
    scanf(" %29[^\n]", login->senha);
  
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

    system("clear");
    printf("-------------------------------------------\n");
    printf("======== BEM VINDO(A) AO CARS FLOW ========\n");
    printf("-------------------------------------------\n");
    login = (LoginAdmin*) malloc(sizeof(LoginAdmin));
    printf("Por favor para continuar faça login : \n");
    printf("Usuário: \n");
    scanf(" %49[^\n]", login->usuario);https:
    printf("Senha: \n");
    scanf(" %29[^\n]", login->senha);
  
    return escolha;

}

//===============================================================================================================================//

char sobre_menu(void){
    char valor;
    printf("-----------------------------------------------------------------------\n");
    printf("==========================       SOBRE        =========================\n");
    printf("-----------------------------------------------------------------------\n"); 
    printf(">>> Sistema de controle de Estacionamentos <<<.\n Nome: Cars Flow.\n Criador: Fábio Araújo, Contato:(84) 9 8819-5543 ).\n email: fabioaraujo.js@hotmail.com\n");
    printf("-----------------------------------------------------------------------\n"); 
    printf("Digite >> V << para voltar:  \n");
    // valor = getchar();
    printf("Digite sua opção");
    scanf(" %c",&valor);
   return valor;//mudar esse retorno
}


//----------------------------------------------------------------------//

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
//funçoes de gravar em arquivo
//grava cliente convenio
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


// função de edição

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
  printf("Informe o nome da placa do veículo: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->placa, procurado) == 0) && (clienteC->status == '1')) {
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
      printf("\n CPF: ");
      scanf(" %15[^\n]", clienteC->cpf);
      printf("\n Celular: ");
      scanf("%d", &clienteC->celular);
      printf("\n Rua: ");
      scanf(" %29[^\n]", clienteC->rua);
      printf("\n Bairro: ");
      scanf(" %29[^\n]", clienteC->bairro);
      printf("\n Cidade: ");
      scanf(" %29[^\n]", clienteC->cidade);
      printf("\n Estado: ");
      scanf(" %29[^\n]", clienteC->estado);
      printf("\n Número da casa: ");
      scanf("%d", &clienteC->numeroCasa);
      printf("\n Tipo de veículo(Carro/Moto): ");
      scanf(" %19[^\n]", clienteC->tipoveiculo);
      printf("\n Modelo do veículo: ");
      scanf(" %19[^\n]", clienteC->modeloveiculo);
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
  printf("Celular:%d\n", clienteC->celular);
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

//exibe conta clientes avuslso
void exibe_conta_avulso(Contaavul* contaAV) {
  printf("Placa do  Veículo: %s\n", contaAV->placa);
  printf("==============================\n");
  printf("%d/%d/%d\n", contaAV->dia, contaAV->mes,contaAV->ano);
  printf("o cliente entrou às %d:%d\n", contaAV->horaEntrada, contaAV->minutoEntrada);
  printf("saiu às %d:%d\n", contaAV->horaSaida, contaAV->minutoSaida);
  printf("===============================\n");
  printf("Status: %c\n", contaAV->status);
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
  printf("Informe a placa do Cliente: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->placa, procurado) == 0) && (clienteC->status == '1')) {
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
    printf("O Cliente  %s não foi encontrado...\n", procurado);
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
  // lista clientes avulso
  void lista_clienteavul(void) {
  FILE* fp;
  Contaavul* contaAV;
  fp = fopen("ContaAvulso.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  
  printf("===== CLIENTES AVULSO=====\n");
  contaAV = (Contaavul*) malloc(sizeof(Contaavul));
  while(fread(contaAV, sizeof(Contaavul), 1, fp)) {
    if (contaAV->status == '1') {
      exibe_conta_avulso(contaAV);
    }
  }
  fclose(fp);
  free(contaAV);
  }

  //função para pegar a hora e a data
void data_hora(void) {

  struct tm *hora;     
  
  
  time_t segundos;
  

  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  hora = localtime(&segundos);  
  
  printf("   %d/", hora->tm_mday);//dia
  printf("%d/",hora->tm_mon+1); //mês
  printf("%d\n\n",hora->tm_year+1900); //ano



  printf("%d:",hora->tm_hour);//hora   
  printf("%d:",hora->tm_min);//minuto


}

// função calcula valor estacionamento
float calculapreco(int horaEntrada,int minutoEntrada,int horaSaida,int minutoSaida){

int difHoras= horaSaida - horaEntrada;
int difminutos = minutoSaida - minutoEntrada;

float precominuto = 0.05 * difminutos;
float precoHora = (difHoras * 60) *0.05;

float precototal = precominuto + precoHora;

return precototal;

}



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
  printf("============================\n");
  printf("= Excluir Cliente Convênio =\n");
  printf("============================\n");
  printf("Por favor digite a Placa do cliente que deseja excluir: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->placa, procurado) == 0) && (clienteC->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibe_convenio(clienteC);
    getchar();
    printf("Deseja realmente Excluir este Cliente (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      clienteC->status = '0';
      fseek(fp, (-1)*sizeof(Clientecon), SEEK_CUR);
      fwrite(clienteC, sizeof(Clientecon), 1, fp);
      printf("\nCliente excluído com sucesso!!!\n");
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O cliente %s não foi encontrado...\n", procurado);
  }
  free(clienteC);
  fclose(fp);
}

void pagamento_cliete_convenio(void) {
  FILE* fp;
  Contacon* contaCO;
  int achou;
  char procurado[15];
  fp = fopen("ContaConvenio.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("================================\n");
  printf("====        PAGAMENTO       ====\n");
  printf("================================\n");
  printf("Informe a placa do cliente: ");
  scanf(" %14[^\n]", procurado);
  contaCO = (Contacon*) malloc(sizeof(Contacon));
  achou = 0;
  while((!achou) && (fread(contaCO, sizeof(Contacon), 1, fp))) {
   if ((strcmp(contaCO->placa, procurado) == 0) && (contaCO->status == '1')) {
     achou = 1;
   }
  }
  fclose(fp);
  if (achou) {
    exibe_conta_convenio(contaCO);
    printf("Total a pagar: R$ %.2f\n",contaCO->valortotal);
    
  
  } else {
    printf("O Cliente  %s não foi encontrado...\n", procurado);
  }
  free(contaCO);
}



//grava login funcionário
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

//grava login administrador
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

// grava conta convênio
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


//grava conta  avulso
void grava_conta_avulso(Contaavul* contaAV) {
  FILE* fp;
  fp = fopen("ContaAvulso.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(contaAV, sizeof(Contaavul), 1, fp);
  fclose(fp);
}


//função para registrar usuario e senha de funcionárop
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

//função para registrar usuario e senha do administrador
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
      usclientecon->celular = clienteC->celular;
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
    printf("Celular:%d\n", lista->celular);
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

// FUNÇÕES PARA LISTA DE CLIENTES POR DATA(DIA,MÊS,ANO)
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
  while((!achou) && (fread(contaCO, sizeof(Contacon), 1, fp))) {
    
     if (diaProcurando == contaCO ->dia && mesProcurando == contaCO -> mes && anoProcurando == contaCO -> ano && contaCO->status == '1') 

    {
     achou = 1;
   }
  }
  fclose(fp); 
  if (achou) {
    exibe_conta_convenio(contaCO);
  
  } else {
    printf("Data inválida(ou não existe ou o usuario digitou errado)  %d/%d/%d \n", diaProcurando,mesProcurando,anoProcurando);
  }
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
  while((!achou) && (fread(contaCO, sizeof(Contacon), 1, fp))) {
    
     if (mesProcurando == contaCO -> mes && anoProcurando == contaCO -> ano && contaCO->status == '1') 

    {
     achou = 1;
   }
  }
  fclose(fp); 
  if (achou) {
    exibe_conta_convenio(contaCO);
  
  } else {
    printf("Data inválida(ou não existe ou o usuario digitou errado) %d/%d \n",mesProcurando,anoProcurando);
  }
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
  while((!achou) && (fread(contaCO, sizeof(Contacon), 1, fp))) {
    
     if ( anoProcurando == contaCO -> ano && contaCO->status == '1') 

    {
     achou = 1;
   }
  }
  fclose(fp); 
  if (achou) {
    exibe_conta_convenio(contaCO);
  
  } else {
    printf("Data inválida(ou não existe ou o usuario digitou errado) %d \n",anoProcurando);
  }
  free(contaCO);
}

//======================================================================================================================









