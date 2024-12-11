#include <stdio.h>  // Biblioteca para entrada e sa�da padr�o
#include <stdlib.h> // Biblioteca para comandos do sistema
#include <locale.h> // Biblioteca para suporte a idiomas com acentos
#include <string.h> // Biblioteca para cuidar das strings

int registrar()
{
	char arquivo [11];
	char cpf [11];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado (sem pontua��o): ");
	scanf("%s", cpf);
	
	strcopy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", cpf);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", cpf);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cpf);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);	
	
	
	
	
	
	
	
	
	
	
	
	
}

int consultar()
{
	printf("Voc� escolheu consultar nomes. Realizando a busca...\n");
    system("pause");
}

int deletar()
{
	printf("Voc� escolheu deletar nomes. Verifique as informa��es antes de prosseguir.\n");
    system("pause");
}

int erro()
{
	printf("Op��o inv�lida. Por favor, escolha uma das op��es dispon�veis.\n");
    system("pause");
}

int main() 
{
    // Vari�veis principais
    int opcao = 0;
    int laco = 1;

    // Loop principal do programa
    for (laco = 1; laco == 1;) 
    {
        system("cls");
        setlocale(LC_ALL, "Portuguese");

        // Menu principal
        printf("==========================================\n");
        printf("\tBem Vindo ao Cart�rio EBAC\n");
        printf("==========================================\n\n");
        printf("Selecione a op��o desejada:\n\n");
        printf("   [1] Registrar nomes\n");
        printf("   [2] Consultar nomes\n");
        printf("   [3] Deletar nomes\n\n");
        printf("Digite sua escolha: ");

        // Captura da escolha do usu�rio
        scanf("%d", &opcao);
        
 		// Limpa a tela novamente para exibir a escolha
		system("cls");
		
        // Processa a escolha do usu�rio
        switch(opcao) 
        {
            case 1:
                registrar();
                break;
            
            case 2:
                consultar();
                break;
            
            case 3:
                deletar();
                break;
            
            default:
                erro();
                break;
        }
    }
}

/*
+--------------------------------------------------------------+
�                      DETALHES DO SISTEMA                    �
+--------------------------------------------------------------+

1. PROP�SITO
   - Este programa simula um sistema simples de cart�rio para gerenciar registros.

2. FUNCIONALIDADES
   - Registrar novos nomes.
   - Consultar nomes j� registrados.
   - Deletar nomes do sistema.

3. COMO FUNCIONA
   - O menu principal utiliza um loop que mant�m o sistema ativo at� o usu�rio encerrar.
   - As escolhas s�o tratadas por um bloco `switch`, garantindo organiza��o e clareza no fluxo.
   - As op��es inv�lidas s�o identificadas e retornam o usu�rio ao menu principal.

4. BIBLIOTECAS
   - `stdio.h`: Gerencia as entradas e sa�das do programa.
   - `stdlib.h`: Fornece fun��es �teis como `system` para limpar a tela e pausar.
   - `locale.h`: Permite o uso de caracteres acentuados.

--------------------------------------------------------------
*/

