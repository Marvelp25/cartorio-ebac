#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inic�o cria��o de variaveis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final cria��o de variaveis/strings
    
    printf("digite o CPF para ser cadastrado: "); //coletando informa��o do usuario
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualizar arquivo
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file - fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file - fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file - fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //ler arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do us�ario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");



}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
}


int main()
    {
    int opcao=0;
    int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL,"Portuguese");
	
	    printf("\tCart�rio da EBAC\n\n");
	    printf("escolha a op��o do menu\n\n");
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-consultar nomes\n");
	    printf("\t3-deletar nomes\n");
	    printf("\t4-sair do sistema\n\n");
	    printf("op��o: ");
	
	    scanf("%d", &opcao);
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //op��es de menu
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
	        printf("Obrigado por utilizar nosso sistema!\n");
	        return 0;
	        break;
	        
	        default:
	        printf("essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
		}
	
    }
}
