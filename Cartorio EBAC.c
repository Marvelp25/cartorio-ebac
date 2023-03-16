#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() // Função responsavel por cadastrar os usuários no sistema
{
	//inicío criação de variaveis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final criação de variaveis/strings
    
    printf("digite o CPF para ser cadastrado: "); //coletando informação do usuario
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
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usúario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");



}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
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
	
	    printf("\tCartório da EBAC\n\n");
	    printf("escolha a opção do menu\n\n");
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-consultar nomes\n");
	    printf("\t3-deletar nomes\n\n");
	    printf("opção: ");
	
	    scanf("%d", &opcao);
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //opções de menu
	    {
	    	case 1:
	        registro(); // chamada de funções
	        break;
	        
            case 2:
	        consulta();
	        break;
	        
	        case 3:
            deletar();
	        break;
	        
	        default:
	        printf("essa opção não está disponivel!\n");
		    system("pause");
		    break;
		}
	
    }
}
