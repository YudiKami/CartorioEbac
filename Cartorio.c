#include <stdio.h> //bliblioteca de comunicação com  o usuário
#include <stdlib.h> //bliblioteca de alocação de espaço em memória
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{ 
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infomação do usuário
	scanf("%s",cpf); //%s refese-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significica escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significica atualizar
	fprintf(file,","); //cria a separação com ","
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando infomação do usuário
	scanf("%s",nome); //%s refese-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,","); //cria a separação com ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando infomação do usuário
	scanf("%s",sobrenome); //%s refese-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf); 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando infomação do usuário
	scanf("%s",cpf); //%s refese-se a string
	
	remove(cpf); //remove o arquivo "cpf"
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
    { 
	int opcao=0; //Defindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	  
	  printf("### Cartório do Crubland ###\n\n"); //Inicio do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("Opção: ");
	  
	  scanf("%d", &opcao); //armazenando a escolha do usuário
	  
	  system("cls"); //responsável por limpar a tela
	  
	  
	  switch(opcao) //incio da seleção do menu
	  {
	  		case 1:
	  		registro(); //chamada de funções
	  	    break;
	  	    
	  	    case 2:
			consulta(); //chamada de funções
	  	    break;
	  	    
	  	    case 3:
			deletar(); //chamada de funções
      	    break;
      	    
      	    default:
      	    printf("Essa opção não está disponivel!\n");
	   	    system("pause");
	   	    break;
	   		//fim fa seleção do menu    
	  }

	}
}
