#include <stdio.h>
#include "proj.h"
#include "string.h"

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
};

// Função para cadastro de novas clientes:
void cadastrarCliente(Cliente clientes[], int *numClientes) {
 // Se o número de clientes é menor que 1000, executar o cadastro.
    if (*numClientes < 1000) {
        Cliente novoCliente;
        printf("======================================================\n");
        printf("\nCadastrar Novo Cliente:\n");
     // Pede o CPF do cliente.
        printf("\nCPF: ");
     // Guarda valor do CPF em novoCliente.
        scanf(" %s", novoCliente.cpf);
        limpaBuffer();
        // Pede o nome do cliente.
        printf("Nome: ");
     // Guarda valor do nome do cliente no endereço de "novoCliente"
        scanf("%[^\n]", &novoCliente.nome);
        limpaBuffer();
     // Pede o tipo de conta entre Comum e Plus.
        printf("Tipo de conta: \n"
               "Nosso banco possui dois tipos de conta: \n "
               "1. Comum: \n"
               "Cobra taxa de 5 porcento a cada débito realizado; \n "
               "Permite saldo negativo de até R$1.000,00. \n "
               "2. Plus: \n "
               "Cobra 3 porcento a cada débito realizado; \n"
               "Permite um saldo negativo de até R$5.000,00. \n"
               "Digite aqui (AVISO: NÃO ESCREVA O TIPO DESEJADO EM CAIXA ALTA!): ");
     // Guarda valor do tipo de conta em novoCliente.
        scanf(" %s", &novoCliente.tipo_conta);
        limpaBuffer();
     // Pede o valor inicial de capital presente na conta.
        printf("Digite o capital inicial presente na conta: R$");
     // Guarda o valor do capital inicial presente na conta em novoCliente.
        scanf(" %lf", &novoCliente.valor_inicial);
        limpaBuffer();
     // Pede o valor da senha da conta.
        printf("Digite a senha da conta: ");
     // Guarda o valor da senha da conta em novoCliente.
        scanf(" %s", &novoCliente.senha);
        limpaBuffer();

     // O novo cliente acresce o número de clientes em 1.
        clientes[*numClientes] = novoCliente;
        (*numClientes)++;

        printf("\nCliente cadastrado com sucesso!");
        printf("======================================================\n");

        printf("\n");
    }
 // Se número de clientes > 1000, retorna erro.
    else {
        printf("O limite de clientes atingido. Não é possível cadastrar mais clientes.\n");
    }
}
