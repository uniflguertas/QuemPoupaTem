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

// Função de listagem dos clientes cadastrados:
void listarCliente(Cliente clientes[], int numClientes) {
    // Se número de clientes cadastrados > 0, mostrar lista.
    if (numClientes > 0) {
        printf("======================================================\n");
        printf("\nLista de Clientes:\n");
        printf("\n======================================================\n");
        // Formato de amostragem dos clientes.
        for (int i = 0; i < numClientes; i++) {
            printf("\nCliente %d:\n", i + 1);
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Tipo de Conta: %s\n", clientes[i].tipo_conta);
            printf("Capital: R$%.2lf\n", clientes[i].valor_inicial);
            printf("\n======================================================\n");
            printf("\n");
        }
        printf("======================================================\n");
    }
        // Se não houver clientes cadastrados, retornar mensagem.
    else {
        printf("==========================================================\n");
        printf("\n(ERRO: Nenhum cliente cadastrado)\n");
        printf("\n==========================================================\n");
    }
}

// Função para deleção de clienes existentes:
void deletarCliente(Cliente clientes[], int *numClientes) {
    char verificaCpf[12];
    char verificaSenha[100];

    printf("======================================================\n");

    printf("\nDeletar Cliente Existente:\n");
    printf("\nDigite aqui o CPF: ");
    scanf("%s", verificaCpf);
    printf("Digite aqui a senha: ");
    scanf("%s", verificaSenha);
 // Se o número de clientes cadastrados > 0, executar a deleção.
    if (*numClientes > 0) {
     // Laço de repetição para percorrer os clientes cadastrados
        for (int i = 0; i < *numClientes; i++) {
            // Realiza o string compare (comparação de strings) para encontrar o cliente desejado para deleção, e assim atribuir nova numeração ao respectivo cliente de acordo com a ocorrência de deleções.
            if (strcmp(verificaCpf, clientes[i].cpf) == 0 && strcmp(verificaSenha, clientes[i].senha) == 0) {
                for (int numero = i; numero < *numClientes - 1; i++) {
                    clientes[i] = clientes[i + 1];
                }
                // Deleta cliente em seu respectivo endereço atribuído.
                (*numClientes)--;
                printf("\nCliente deletado com sucesso!\n");
                printf("======================================================\n");
            } else {
                printf("\n(ERRO: CPF ou senha inválidos. Cliente não encontrado)\n");
                printf("======================================================\n");
            }
        }
    }

 // Se não houver clientes cadastrados, retornar mensagem.
    else {
        printf("\n(ERRO: Nenhum cliente cadastrado)\n");
        printf("======================================================\n");
    }
}

//Função para realização de débitos:
void debitoCliente (Cliente clientes[], int *numClientes) {
 // Declaração de Variáveis.
    double valorDebito;
    char verificaCpf[12];
    char verificaSenha[100];

    printf("======================================================\n");

 // Pedido ao usuário das informações necessárias (CPF e senha).
    printf("\nRealizar Novo Débito:\n");
    printf("\nDigite aqui o CPF: ");
    scanf("%s", verificaCpf);
    printf("Digite aqui a senha: ");
    scanf("%s", verificaSenha);
    printf("Digite aqui o valor do débito: R$");
    scanf("%lf", &valorDebito);

 // Se o número de clientes > 0, executa a função.
    if (*numClientes > 0) {
     // Laço de repetição para percorrer os clientes
        for (int i = 0; i < *numClientes; i++) {
         // String compare das informações fornecidas: se CPF e senha conferem para algum cliente, realiza o depósito.
            if (strcmp(verificaCpf, clientes[i].cpf) == 0 && strcmp(verificaSenha, clientes[i].senha) == 0) {
             // Condicional de acordo com o tipo de conta do usuário: se a conta é comum, aplica taxa de 5%, se plus, aplica taxa de 3%.
                if (strcmp("comum", clientes[i].tipo_conta) == 0) {
                    clientes[i].valor_inicial -= valorDebito + (valorDebito * 0.05);

                    printf("\nDébito realizado com sucesso!\n");
                    printf("======================================================\n");
                }
                else if (strcmp("plus", clientes[i].tipo_conta) == 0) {
                    clientes[i].valor_inicial -= valorDebito + (valorDebito * 0.03);
                }
            }

         // Se as informações não coincidirem com nenhum cliente, retorna erro.
            else {
                printf("\n(ERRO: CPF ou senha inválidos. Cliente não encontrado)\n");
                printf("======================================================\n");
            }
        }
    }

 // Se não houver clientes cadastrados, retornar mensagem.
    else {
        printf("\n(ERRO: Nenhum cliente cadastrado)\n");
        printf("======================================================\n");
    }
}
