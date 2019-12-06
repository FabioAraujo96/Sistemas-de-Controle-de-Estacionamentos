typedef struct clientecon Clientecon;

struct clientecon {
  char nome[50];
  char rua[30];
  char bairro[40];
  char cidade[40];
  char estado[30];
  char email [40];
  char tipoveiculo[20];
  char modeloveiculo[40];
  char placa[20];
  char cpf [16];
  int numeroCasa;
  float preco_acumulado;
  char status;
};

typedef struct usclientecon UsClientecon;

struct usclientecon {
  char nome[50];
  char rua[30];
  char bairro[40];
  char cidade[40];
  char estado[30];
  char email [40];
  char tipoveiculo[20];
  char modeloveiculo[40];
  char placa[20];
  char cpf [16];
  int numeroCasa;
  float preco_acumulado;
  char status;
  UsClientecon* prox;
};

typedef struct contacon Contacon;

struct contacon {
  char nome[50];
  char placa[20];
  char cpf[16];
  int horaEntrada;
  int minutoEntrada;
  char saiu;
  int horaSaida;
  int minutoSaida;
  int dia;
  int mes;
  int ano;
  float preco_acumulado;

  char status;
};

typedef struct contrato Contrato;

struct contrato {
  char nome[50];
  char placa[20];
  char cpf [16];
  float preco_acumulado;

  char status;
};

//implemnatr uma estrutura apenas para cliente avulso

typedef struct avulso Avulso;

struct avulso {
  char placa[20];
  float avulso_acumulado;
  int horaEntrada;
  int minutoEntrada;
  char saiu;
  int horaSaida;
  int minutoSaida;
  int dia;
  int mes;
  int ano;
  char status;
};



// estrutura criada para logi de funcionarios\\


typedef struct loginfun Loginfun;

struct loginfun {

  char usuario[50];
  char senha [30];
  char status;

};

//================================================\\

// estrutura criada para login de administradores \\



typedef struct loginadmin LoginAdmin;

struct loginadmin {

  char usuario[50];
  char senha [30];
  char status;

};


void exibe_Avulso(Avulso*);//--> criando ainda (não sei se vou ter tempo)
void liberaLista(UsClientecon*);// função para liberar lista
UsClientecon* listaOrdenadaconvenio(void);// função para lista ordenada 
UsClientecon* listaInvertidaconvenio(void);// função  para lista invertida
void gravafun(Loginfun*);//função para gravar login de funcionário
void  grava_conta_convenio(Contacon*);//função para gravar conta convênio
UsClientecon* listaDiretaclientes(void);// função para lista direta de clientes
void exibeLista(UsClientecon*);//função que exibe lista--dinâmica
void gravaadm(LoginAdmin*);//função que grava função para administrador 
void gravaavulso(Avulso*);//f>>>>>unção está sendo implementada<<<<<
void exibe_conta_convenio(Contacon*);//função que exibe valores referente ao uso de estacionamento 
void gravacontrato(Contrato*) ;//função que grava contatro -- função de pagamento dos clientes
void gravaclicon( Clientecon*);// grava cliente convênio
void exibe_convenio(Clientecon*);//função para exibir clientes convênio
char imp_menu(void);//tela menu principal;
char cliente_menu(void);//tela do cliente avulso e Convênio;
char administrador_menu(void);//menu empresa;
void sobre_menu(void);//função mostra uma descrição breve do programa e seus criadores;
char convenio_login(void);//tela de menu da opção convênio;
char visualizarClientes(void);//em construção, referente ao menu empresa;
char regristroAtividade(void);//em construção, referente ao menu empresa;
char lucro(void);//em construção, referente ao menu empresa;
void cadastro_cliente_convenio(void);//função com código pedindo informação do cliente, para função convênio;
void cadastro_avulso_entrada(void);//função com código pedindo informação do cliente, para função avulso;
char empresa_menu(void);//tela de menu da opção empresa
char op_menu_cliente(void);// tela de menu para opção cliente avulso/convenio
void altera_convenio(void); //edita dados do cliente convênio
void exibir_cliente_convenio(void);//função de exibir cliente convenio
void lista_clientecon(void); //lista clientes convenio
void lista_clienteavul(void); //lista clientes avulso
void data_hora(void); // função mostra a data e a hora atual
char cliente_menu_avulso(void); // navehgação de cleinte avulso
void cadastro_avulso_saida(void);// código para função saida
char avulso_menu(void); // menu para avulso
float calculapreco(int,int,int,int);// função para calcular o preço do cliente avulso 
char convenio_menu(void);//função para mostrar o menu convênio
char escolha_navegacao_convenio(void);//função para navegação de telas de convênio
void cadastro_convenio_entrada(void) ;//função para cadastrar entrada de convenio
void cadastro_convenio_saida(void);//função para cadastrar saida de convênio
char cliente_menu_convenio(void);//função de navegação do cliente convênio
void excluirconvenio(void);// função que Exclui cliente Convênio
char imp_login(void);//primeira tela de login Funcionário
char adm_login(void);// primeira tela de login Administrador
void pagamento_cliete_convenio(void);// função para pagamento convênio
void acumula_valor(void);// função para acumular valores de convênio
void login_funcionario(void);//função para criar usuario e senha de funcionário->gravando dados
void login_administrador(void);//// função para criar usuario e senha de funcionário-> gravando dados
void comparando_loginfun(void);//função para fazer comparação se há arquivo registrado em funcionário
void comparando_loginadm(void);//função para fazer comparação se há arquivo registrado em administrador
char login_cadastrado_fun(void);//função para login funcionário, quando ja haver login cadastrado
char login_cadastrado_adm(void);// função para login administrador, quando ja haver login cadastrado
void lista_dia_convenio(void);// funçao para listar cientes por dia(relatório administrador)
char cliente_empresa_relatorio(void); // navegação para relatorio de clientes
char cliente_empresa_lucro(void);// navegação para lucro
void lista_mes_convenio(void); //função para listar clientes por mês(relatório administrador)
void lista_ano_convenio(void);// função para listar clientes por ano(relatório administrador)