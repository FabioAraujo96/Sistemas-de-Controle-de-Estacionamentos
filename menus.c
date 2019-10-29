#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include "validacoes.h"
#include "menus.h"



typedef struct clientecon Clientecon;

struct clientecon {

  char nome[50];
  char rua[30];
  char bairro[30];
  char cidade[30];
  char estado[30];
  char email[50];
  char tipoveiculo[20];
  char modeloveiculo[20];
  char placa[20];
  int identidade;
  int numeroCasa;
  int data;
  char status;
};
void gravaclicon( Clientecon*);
void exibe_convenio(Clientecon*);

typedef struct clienteavul Clienteavul;

struct clienteavul {

  char nome[50];
  char tipoveiculo[20];
  char email[50];
  char modeloveiculo[20];
  char placa[20];
  int identidade;
  int data;

  char status;
};
void gravacliavul(Clienteavul*);
void exibe_avulso(Clienteavul*);
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
      printf("\n Identidade: ");
      scanf("%d", &clienteC->identidade);
      printf("\n Email: ");
      scanf(" %49[^\n]", clienteC->email);
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
      printf("Cliente cadastrado em: ");
      printf("===============================\n");
      exibe_convenio(clienteC);
      printf("===============================\n");
      gravaclicon(clienteC);
      printf("\n...Cliente cadastrado com sucesso...\n ");
      printf("Click >> V << para voltar: ");
      scanf("%s", &op);

}
void cadastro_avulso_composto() {
    char op;
     Clienteavul* clienteA;
    printf("==============================================\n");
    printf("-------||| RETIRAR TICKET AVULSO ||| ---------\n");
    printf("==============================================\n");
    clienteA = (Clienteavul*) malloc(sizeof(Clienteavul));
    printf("\n Nome: ");
    scanf(" %49[^\n]", clienteA->nome);
    int i = 0;
    while (clienteA->nome[i] != '\0')
    {
        valid_alfabetica(clienteA->nome[i]);
        ++i;
        
    }
    
    printf("\n Identidade: ");
    scanf("%d", &clienteA->identidade);
    printf("\n Email: ");
    scanf(" %49[^\n]", clienteA->email);
    printf("\n Tipo de veículo(Carro/Moto): ");
    scanf(" %19[^\n]", clienteA->tipoveiculo);
    printf("\n Modelo do veículo: ");
    scanf(" %19[^\n]", clienteA->modeloveiculo);
    printf("\n Placa do veículo(LLL-NNNN): ");
    scanf(" %9[^\n]", clienteA->placa);
    clienteA->status = '1';
    printf("===============================\n");
    exibe_avulso(clienteA);
    printf("===============================\n");
    gravacliavul(clienteA);
    printf("\n...Cliente cadastrado com sucesso...\n ");
    printf("Click >> V << para voltar: ");
    scanf("%s", &op);

  
    //return toupper(escolha);
}

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
                cadastro_avulso_composto();
            
                break;

            case'B':
                escolha_navegacao_convenio();
            
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


char escolha_navegacao_convenio(void){
    char op;
    system("clear");
    

    do{
        switch(op=convenio_login()){
            case 'A':
                cadastro_cliente_convenio();
            
                break;

            case'B':
                altera_convenio();
            
                break;
                
            case 'C':
                preco_convenio();
                

                break;   

            case 'D':
               exibir_cliente_convenio();
              
               
                break;   
        

            default:

			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(op!='V');

        return op;
}
// menu empresa 
char empresa_menu(void){
    char escolha;
    system("clear");
    printf("---------------------------------------\n");
    printf("============== MENU EMPRESA ===========\n");
    printf("---------------------------------------\n");
    printf("\n A- Exibir Clientes\n");
    printf("\n B- Listar Clientes\n");
    printf("\n C- Lucro (dia,Mês,Ano)\n");
    printf("\n D- Registro de Atividade (dia,Mês,Ano)\n");
    printf("\n V- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:   \n");
    scanf(" %c", &escolha);


    return toupper(escolha);
}
//Referente a empresa 
char administrador_menu(){
    char escolha;
    system("clear");
    

    do{
        switch(escolha=empresa_menu()){
            case 'A':
                lista_clientecon();
                lista_clienteavul();
                printf("\nDigite Enter para Continuar: ");
                getchar();
                getchar();
  

            
                break;

            case'B':

                printf("em construção(arquivar)");
                
                break;
            case 'C':
                printf("em construção(arquivar)");

                break;

            case 'D':
                printf("em construção(arquivar)");

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
void preco_avulso(void){
    char escolha_horario;
    printf("------------------------------\n");
    printf("===== OPÇÃO DE SERVIÇO =======\n");
    printf("------------------------------\n");
    printf("\nA- Até 30 minutos (R$7,OO)\n");
    printf("\nB- Até 2 horas (R$20,OO)\n");
    printf("\nC- Até 5 horas (R$45,OO)\n");
    printf("\nD- Até 12 horas (R$110,OO)\n");
    printf("\nEscolha uma opção de horário acima: \n"); 
    scanf("%s", &escolha_horario);
    if (escolha_horario!= ('V' | 'v')){
      if (escolha_horario == ('A' | 'a')){
        printf("sua opção desejada foi até 30 minutos (R$7,OO), obrigado pela escolha.");

      }
      else if(escolha_horario == ('B' | 'b')){
        printf("sua opção desejada  foi até 2 horas (R$20,OO), obrigado pela escolha.");

      }
      else if(escolha_horario == ('C' | 'c')){
        printf("sua opção desejada  foi até 5 horas (R$45,OO), obrigado pela escolha.");

      }
      else if(escolha_horario == ('D' | 'd')){
        printf("sua opção desejada  foi até 12 horas (R$110,OO), obrigado pela escolha.");


      }
    }
    
}

void preco_convenio(void){
    char escolha_horario;
    printf("------------------------------------------------\n");
    printf("Clientes convênio paga um valor fixo Mensalmente. \n");
    printf("Esse valor é R$100,00\n");
    printf("-------------------------------------------------\n");
    
    printf("\n\n");
    printf("=======================\n");
    printf("RETIRAR TICKET CONVÊNIO\n");
    printf("=======================\n");
    exibir_cliente_convenio();
    printf("Valor da mensalidade: R$100,00\n");
    printf("\nDigite Enter para Continuar: ");
    getchar();
    getchar();
    
  }

//menu principal
char imp_menu(void){
    char escolha;// declarando variavel 

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
 
/*>>em construção,
login principal(esta tela será o login admin do programa)*/

char imp_login(void){ //falta colocar a identidade em menus.h
    char escolha;
    char usuario[50];
    int senha;

    system("clear");
    printf("-------------------------------------------\n");
    printf("======== BEM VINDO(A) AO CARS FLOW ========\n");
    printf("-------------------------------------------\n");
    printf("Por favor para continuar faça login : \n");
    printf("Usuário: \n");
    scanf(" %49[^\n]", usuario);
    printf("Senha: \n");
    scanf("%d",&senha);    
    return escolha;

}

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


//em construção >>referente ao menu empresa
char visualizarClientes(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("== MENU INFORMAÇÕES CLIENTES ==\n");
    printf("-------------------------------\n");
    printf("\n A- Listar todos os clientes \n");
    printf("\n B- Exibir dados do cliente  \n");
    printf("\n V- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}

//em construção >>referente ao menu empresa,
// nessa função sera feita todo o calculo sem precisar de navegação
char regristroAtividade(void){
    char escolha;
    system("clear");
    printf("---------------------------------\n");
    printf("== MENU REGISTRO DE ATIVIDADES ==\n");
    printf("---------------------------------\n");
    printf("\n A- Dia\n");
    printf("\n B- Mês\n");
    printf("\n C- Ano\n");
    printf("---------------------------------\n");
    printf("Por favor digite sua escolha:    \n");
    scanf(" %c", &escolha);

    return escolha;
}
//em construção >>referente ao menu empresa
//mostrar sem precisar de criar novas telas de navegação
char lucro(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("========== MENU LUCRO =========\n");
    printf("-------------------------------\n");
    printf("\n A- Dia\n");
    printf("\n B- Mês\n");
    printf("\n C- Ano\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}
//funçoes de gravar em arquivo
//grava cliente convenio
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
// grava cliente Avulso

void gravacliavul(Clienteavul* clienteA) {
  FILE* fp;
  fp = fopen("ClienteAvulso.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(clienteA, sizeof(Clienteavul), 1, fp);
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
  printf("Informe o nome do cliente que deseja alterar: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->nome, procurado) == 0) && (clienteC->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibe_convenio(clienteC);
    printf("Deseja realmente Alterar este Cliente (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      printf("\n Nome: ");
      scanf(" %49[^\n]", clienteC->nome);
      printf("\n Identidade: ");
      scanf("%d", &clienteC->identidade);
      printf("\n Email: ");
      scanf(" %49[^\n]", clienteC->email);
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
  getchar()
}

// funções de exibição 
// exibe cliente convênio
void exibe_convenio(Clientecon* clienteC) {
  
  printf("Nome: %s\n", clienteC->nome);
  printf("Identidade:%d\n", clienteC->identidade);
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

//exibe cliente avulso
void exibe_avulso(Clienteavul* clienteA) {
  printf("Nome: %s\n", clienteA->nome);
  printf("Identidade: %d\n", clienteA->identidade);
  printf("Email: %s\n", clienteA->email);
  printf("Tipo de Veículo: %s\n", clienteA->tipoveiculo);
  printf("Modelo do Veículo %s\n", clienteA->modeloveiculo);
  printf("Placa do  Veículo: %s\n", clienteA->placa);
  printf("Status: %c\n", clienteA->status);
  printf("\n");
  

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
  printf("Informe o nome do Cliente: ");
  scanf(" %14[^\n]", procurado);
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  achou = 0;
  while((!achou) && (fread(clienteC, sizeof(Clientecon), 1, fp))) {
   if ((strcmp(clienteC->nome, procurado) == 0) && (clienteC->status == '1')) {
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
  
  printf("===== CLIENTES AVULSO=====\n");
  clienteC = (Clientecon*) malloc(sizeof(Clientecon));
  while(fread(clienteC, sizeof(Clientecon), 1, fp)) {
    if (clienteC->status == '1') {
      exibe_convenio(clienteC);
    }
  }
  fclose(fp);
  free(clienteC);
  
}

  void lista_clienteavul(void) {
  FILE* fp;
  Clienteavul* clienteA;
  fp = fopen("ClienteAvulso.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  
  printf("===== CLIENTES AVULSO=====\n");
  clienteA = (Clienteavul*) malloc(sizeof(Clienteavul));
  while(fread(clienteA, sizeof(Clienteavul), 1, fp)) {
    if (clienteA->status == '1') {
      exibe_avulso(clienteA);
    }
  }
  fclose(fp);
  free(clienteA);
  }

  //função para pegar a hora e a data
void data_hora(void) {

  struct tm *data_hora_atual;     
  
  
  time_t segundos;
  

  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);  
  
  printf("   %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1); //mês
  printf("%d\n\n",data_hora_atual->tm_year+1900); //ano



  printf("%d:",data_hora_atual->tm_hour);//hora   
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d",data_hora_atual->tm_sec);//segundo  
  

  

}