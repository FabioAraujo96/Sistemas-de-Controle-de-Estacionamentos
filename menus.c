#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validacoes.h"
#include "menus.h"

//telas referentes ao menu principal 

char  cadastro_cliente_convenio(){
    
  char escolha,nome[100],rua[100],bairro[100],cidade[100],estado[100], email[100], tipoveiculo[100], modeloveiculo[100],placa[100];

  int cpf, numeroCasa, indentidade, op;

      printf("==============================================\n");
      printf("------||| Cadastro cliente convênio |||-------\n");
      printf("==============================================\n");
      printf("\n Nome: ");
      scanf("%s", nome);
      printf("\n CPF: ");
      scanf("%d", &cpf);
      printf("\n Indentidade: ");
      scanf("%d", &indentidade);
      printf("\n Rua: ");
      scanf("%s", rua);
      printf("\n Bairro: ");
      scanf("%s", bairro);
      printf("\n Cidade: ");
      scanf("%s", cidade);
      printf("\n Estado: ");
      scanf("%s", estado);
      printf("\n Número da casa: ");
      scanf("%d", &numeroCasa);
      printf("\n Tipo de veículo(Carro/Moto): ");
      scanf("%s", tipoveiculo);
      printf("\n Modelo do veículo: ");
      scanf("%s", modeloveiculo);
      printf("\n Placa do veículo: ");
      scanf("%s", placa);
      printf("\n Click >> C << para voltar: ");
      scanf("%d", &op);

      return escolha;

}
char cadastro_avulso_composto() {

  char escolha,nome[100], tipo_veiculo[100], modelo_veiculo[100], escolha_horario[100],placa[100];
  int cpf,op;
    printf("==============================================\n");
    printf("-------||| RETIRAR TICKET AVULSO ||| ---------\n");
    printf("==============================================\n");
    printf("\n Nome: ");
    scanf("%s", nome);

    printf("\n CPF: ");
    scanf("%d", &cpf);

    printf("\n Tipo de veículo(Carro/Moto): ");
    scanf("%s", tipo_veiculo);

    printf("\n Modelo do veículo: ");
    scanf("%s", modelo_veiculo);
  
    printf("\n Placa do veículo(LLL-NNNN): ");
    scanf("%s", placa);

    printf("\n >>>>> OPÇÃO DE SERVIÇO <<<<<\n A- Até 30 minutos (R$7,OO)\n B- Até 2 horas (R$20,OO)\n C- Até 5 horas (R$45,OO)\n D- Até 12 horas (R$110,OO)\n Escolha uma opção de horário acima: \n Para voltar digite C: \n");
    scanf("%s ", escolha_horario);


    //restante de código sendo feito
    
    
     

  
    return toupper(escolha);
}

char convenio_login(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("==== MENU USUARIO CONVÊNIO ====\n");
    printf("-------------------------------\n");
    printf("\n A- Exibir dados             \n");
    printf("\n B- Alterar dados            \n");
    printf("\n C- Retirar ticket           \n");
    printf("\n D- Total a pagar            \n");
    printf("\n E- Cadastrar cliente        \n");
    printf("\n F- Voltar                   \n");
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
    printf("\n C- Voltar\n");
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
            
                
                break;

            default:

			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(escolha!='C');

        return escolha;
}
//===========================================================================================//


char escolha_navegacao_convenio(void){
    char op;
    system("clear");
    

    do{
        switch(op=convenio_login()){
            case 'A':
                printf("em construção");
            
                break;

            case'B':
                printf("em construção");
            
                break;
                
            case 'C':
                printf("em construção");

                break;   

            case 'D':
               printf("em construção");

                break;   
            case 'E':
                cadastro_cliente_convenio();

                    
                break;

            default:

			    printf("\n");
			    printf(">>>Opção errada. Digite uma opção válida: ");
			    printf("\n");



        }
    }
    while(op!='F');

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
    printf("\n E- Voltar\n");
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
                printf("em construção(arquivar)");

            
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
    while(escolha!='E');

        return escolha;
}



//====================================================================================================//

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
    printf("\n D- Sair \n");
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
    printf(">>> Sistema de controle de Estacionamentos <<<.\n Nome: Cars Flow.\n Criadores: Fábio Araújo, Marcelo Victor.\n Contato: (84) 9 9932-7654 / (84) 9 8819-5543 ).\n email: marcelovictormelonunes@gmail.com / fabioaraujo.js@hotmail.com\n");
    printf("-----------------------------------------------------------------------\n"); 
    printf("Digite >> C << para voltar:  \n");
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
    printf("\n C- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}

//em construção >>referente ao menu empresa
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
