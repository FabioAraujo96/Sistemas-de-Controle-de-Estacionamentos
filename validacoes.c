
char  cadastro_cliente_convenio(){
    
printf("------Cadastro cliente convênio-------\n");
  char escolha,nome[50],rua[50],bairro[50],cidade[50],estado[50], tipoveiculo[50], modeloveiculo[50],placa;
  int cpf, indentidade,numeroCasa;

  printf("\n Nome: ");
  scanf("%c",&nome);

  printf("\n CPF: ");
  scanf("%d",&cpf);

  printf("\n Indentidade: ");
  scanf("%d", &indentidade);

  printf("\n Rua: ");
  scanf("%c", &rua);

  printf("\n Bairro: ");
  scanf("%c", &bairro);

  printf("\n Cidade: ");
  scanf("%c", &cidade);

  printf("\n Estado: ");
  scanf("%c", &estado);

  printf("\n Número da casa: ");
  scanf("%c", &numeroCasa);



  printf("\n Tipo de veículo(Carro/Moto): ");
  scanf("%c", &tipoveiculo);

  printf("\n Modelo do veículo: ");
  scanf("%c", &modeloveiculo);
  
  printf("Placa do veículo: ");
  scanf("%c", &placa);
  return escolha;
}