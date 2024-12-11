#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para registrar informações de um usuário
void registrar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char nome[60];
    char sobrenome[60];
    char cargo[60];
    char arquivo[40];
    char linha[200];

    printf("==========================================\n");
    printf("       Registro de Novo Usuário           \n");
    printf("==========================================\n\n");

    printf("Digite o CPF (apenas números, sem pontuação): ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    strcpy(arquivo, cpf);

    // Verificar se o CPF já existe
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
        printf("\nO usuário %s cujo CPF é %s já está cadastrado!\n\n", nome, cpf);
        system("pause");
        return;
    }

    // Criar novo registro
    file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("\nErro: Não foi possível criar o registro.\n\n");
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

// Função para consultar registros
void consultar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("==========================================\n");
    printf("            Consulta de Usuário           \n");
    printf("==========================================\n\n");

    printf("Digite o CPF para consulta: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("\nRegistro não encontrado. Verifique o CPF digitado.\n\n");
        system("pause");
        return;
    }

    printf("\nInformações do Usuário:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }

    fclose(file);
    printf("\nConsulta concluída com sucesso!\n\n");
    system("pause");
}

// Função para deletar registros
void deletar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char linha[200];
    char nome[60] = "desconhecido";

    printf("==========================================\n");
    printf("            Exclusão de Registro          \n");
    printf("==========================================\n\n");

    printf("Digite o CPF do usuário a ser deletado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("\nRegistro não encontrado. Verifique o CPF digitado.\n\n");
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
        printf("\nO usuário %s, cujo CPF é %s, foi deletado com sucesso!\n\n", nome, cpf);
    } else {
        printf("\nErro ao tentar deletar o registro. Tente novamente.\n\n");
    }

    system("pause");
}

// Função para tratar opções inválidas
void erro() {
    printf("\nOpção inválida. Por favor, escolha uma opção válida do menu.\n\n");
    system("pause");
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    while (1) {
        system("cls");
        printf("==========================================\n");
        printf("            Cartório Digital EBAC         \n");
        printf("==========================================\n\n");
        printf("Selecione uma opção do menu:\n");
        printf("   [1] Registrar novo usuário\n");
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
                printf("\nObrigado por usar o Cartório Digital EBAC! Até breve!\n");
                exit(0);
            default:
                erro();
        }
    }
    return 0;
}


/*
+--------------------------------------------------------------+
¦                      DETALHES DO SISTEMA                    ¦
+--------------------------------------------------------------+

1. PROPÓSITO
   - Este programa simula um sistema simples de cartório para gerenciar registros.

2. FUNCIONALIDADES
   - Registrar novos nomes.
   - Consultar nomes já registrados.
   - Deletar nomes do sistema.

3. COMO FUNCIONA
   - O menu principal utiliza um loop que mantém o sistema ativo até o usuário encerrar.
   - As escolhas são tratadas por um bloco `switch`, garantindo organização e clareza no fluxo.
   - As opções inválidas são identificadas e retornam o usuário ao menu principal.

4. BIBLIOTECAS
   - `stdio.h`: Gerencia as entradas e saídas do programa.
   - `stdlib.h`: Fornece funções úteis como `system` para limpar a tela e pausar.
   - `locale.h`: Permite o uso de caracteres acentuados.

--------------------------------------------------------------
*/

