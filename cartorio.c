#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Fun��o para registrar informa��es de um usu�rio
void registrar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char nome[60];
    char sobrenome[60];
    char cargo[60];
    char arquivo[40];
    char linha[200];

    printf("==========================================\n");
    printf("       Registro de Novo Usu�rio           \n");
    printf("==========================================\n\n");

    printf("Digite o CPF (apenas n�meros, sem pontua��o): ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    strcpy(arquivo, cpf);

    // Verificar se o CPF j� existe
    FILE *file = fopen(arquivo, "r");
    if (file != NULL) {
        // CPF encontrado, verificar o nome
        while (fgets(linha, sizeof(linha), file) != NULL) {
            if (strncmp(linha, "Nome: ", 6) == 0) {
                strcpy(nome, linha + 6);
                nome[strcspn(nome, "\n")] = 0; // Remove o newline
                break;
            }
        }
        fclose(file);
        printf("\nO usu�rio %s cujo CPF � %s j� est� cadastrado!\n\n", nome, cpf);
        system("pause");
        return;
    }

    // Criar novo registro
    file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("\nErro: N�o foi poss�vel criar o registro.\n\n");
        system("pause");
        return;
    }

    fprintf(file, "CPF: %s\n", cpf);

    printf("Digite o nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;
    fprintf(file, "Nome: %s\n", nome);

    printf("Digite o sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = 0;
    fprintf(file, "Sobrenome: %s\n", sobrenome);

    printf("Digite o cargo: ");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = 0;
    fprintf(file, "Cargo: %s\n", cargo);

    fclose(file);

    printf("\nRegistro salvo com sucesso!\n\n");
    system("pause");
}

// Fun��o para consultar registros
void consultar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("==========================================\n");
    printf("            Consulta de Usu�rio           \n");
    printf("==========================================\n\n");

    printf("Digite o CPF para consulta: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("\nRegistro n�o encontrado. Verifique o CPF digitado.\n\n");
        system("pause");
        return;
    }

    printf("\nInforma��es do Usu�rio:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }

    fclose(file);
    printf("\nConsulta conclu�da com sucesso!\n\n");
    system("pause");
}

// Fun��o para deletar registros
void deletar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char linha[200];
    char nome[60] = "desconhecido";

    printf("==========================================\n");
    printf("            Exclus�o de Registro          \n");
    printf("==========================================\n\n");

    printf("Digite o CPF do usu�rio a ser deletado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("\nRegistro n�o encontrado. Verifique o CPF digitado.\n\n");
        system("pause");
        return;
    }

    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (strncmp(linha, "Nome: ", 6) == 0) {
            strcpy(nome, linha + 6);
            nome[strcspn(nome, "\n")] = 0;
            break;
        }
    }
    fclose(file);

    if (remove(cpf) == 0) {
        printf("\nO usu�rio %s, cujo CPF � %s, foi deletado com sucesso!\n\n", nome, cpf);
    } else {
        printf("\nErro ao tentar deletar o registro. Tente novamente.\n\n");
    }

    system("pause");
}

// Fun��o para tratar op��es inv�lidas
void erro() {
    printf("\nOp��o inv�lida. Por favor, escolha uma op��o v�lida do menu.\n\n");
    system("pause");
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    while (1) {
        system("cls");
        printf("==========================================\n");
        printf("            Cart�rio Digital EBAC         \n");
        printf("==========================================\n\n");
        printf("Selecione uma op��o do menu:\n");
        printf("   [1] Registrar novo usu�rio\n");
        printf("   [2] Consultar registro\n");
        printf("   [3] Deletar registro\n");
        printf("   [4] Sair do sistema\n\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        system("cls");

        switch (opcao) {
            case 1:
                registrar();
                break;
            case 2:
                consultar();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("\nObrigado por usar o Cart�rio Digital EBAC! At� breve!\n");
                exit(0);
            default:
                erro();
        }
    }
    return 0;
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

