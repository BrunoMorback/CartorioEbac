#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloc��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar da sting

int registro() // fun��o responsavel por cadastro
{
	// inicio de cria�ao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // abre o arquivo "w" � para escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf (file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo as linguagens
    
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("n�o localizado.");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as infos do us�ario: \n");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
}
	


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls"); //limpar tela
	  
	  setlocale(LC_ALL, "Portuguese"); // Definindo as linguagens
	
	
	  
	  printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	  printf("Escolha a op��o desejada do menu\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("\t4 - Sair do sistema\n\n");
	  printf("Op��o: "); // Fim do menu
	
	  scanf("%d", &opcao); // Armazenado escolha do usuario
	
	  system("cls"); //limpar tela
	  
	  switch(opcao)
	  {
	  	case 1:
	  	registro(); // chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
	    printf("Obrigado por ultilizar o sistema!");
	    return 0;
	    break;
		
		default:
		printf("Essa op��o n�o esta disponivel!\n");
		break; // fim da sele��o
			
			
	  		
	}
}
}
