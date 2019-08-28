#include <stdio.h>
#include <stdlib.h>

//telas referentes ao menu principal 
char imp_menu(void){
    char escolha;// declarando variavel 

    system("clear");
    printf("------------------------------\n");
    printf("======  MENU PRINCIPAL =======\n");
    printf("------------------------------\n");
    printf("\n A- Cliente \n ");
    printf("\n B- Admistrador \n");
    printf("\n C- Sobre \n");
    printf("\n D- Sair \n");
    printf("------------------------------\n");
    printf("Por favor digite sua escolha: \n");
    scanf(" %c", &escolha);

    return escolha;
}


char cliente_menu(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("========= MENU CLIENTE ========\n");
    printf("-------------------------------\n");
    printf("\n A- Avulso\n");
    printf("\n B- Convênio\n");
    printf("\n C- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);
    return escolha;
}

char administrador_menu(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("===== MENU ADMINISTRADOR =====\n");
    printf("------------------------------\n");
    printf("\n A- Login\n");
    printf("\n B- Cadastrar\n");
    printf("\n C- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:   \n");
    scanf(" %c", &escolha);


    return escolha;
}
char sobre_menu(void){
    char escolha;
    printf("-----------------------------------------------------------------------\n");
    printf("==========================       SOBRE        =========================\n");
    printf("-----------------------------------------------------------------------\n"); 
    printf(">>> Sistema de controle de Estacionamentos <<<.\n Nome: Cars Flow.\n Criadores: Fábio Araújo, Marcelo Victor.\n Contato: (84) 9 9932-7654 / (84) 9 8819-5543 ).\n email: marcelovictormelonunes@gmail.com / fabioaraujo.js@hotmail.com\n");
    printf("-----------------------------------------------------------------------\n"); 
    printf("Digite >> C << para voltar:  \n");
    
   return escolha;//mudar esse retorno
}


//----------------------------------------------------------------------//


//telas referentes a menu clientes//

char avulso_cliente(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("=======   MENU AVULSO   =======\n");
    printf("-------------------------------\n");
    printf("\n A- Retirar ticket\n");
    printf("\n B- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}

char convenio_cliente(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("=======  MENU CONVÊNIO  =======\n");
    printf("-------------------------------\n");
    printf("\n A- Login\n");
    printf("\n B- Cad,0astro\n");
    printf("\n C- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}

//segundas telas de clientes (Convenio - login)
char convenio_login(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("==== MENU USUARIO CONVÊNIO ====\n");
    printf("-------------------------------\n");
    printf("\n A- Exibir dados do cliente  \n");
    printf("\n B- Alterar dados do cliente \n");
    printf("\n C- Retirar ticket\n");
    printf("\n D- Total a pagar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}

//telas administrador
char administrador_login(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("== MENU LOGIN ADMINISTRADOR  ==\n");
    printf("-------------------------------\n");
    printf("\n A- Login\n");
    printf("\n B- Cadastrar\n");
    printf("\n C- Voltar\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}


//segundas telas de administrador
char administrador2(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("=====  MENU INFORMAÇÕES  ======\n");
    printf("-------------------------------\n");
    printf("\n A- Visualizar clientes\n");
    printf("\n B- Registro de Atividade\n");
    printf("\n C- Lucro\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}

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

char lucro(void){
    char escolha;
    system("clear");
    printf("-------------------------------\n");
    printf("========== MENU LUCRO =========\n");
    printf("-------------------------------\n");
    printf("\n A- Dia\n");
    printf("\n B- Mês\n");//
    printf("\n C- Ano\n");
    printf("-------------------------------\n");
    printf("Por favor digite sua escolha:  \n");
    scanf(" %c", &escolha);

    return escolha;
}
