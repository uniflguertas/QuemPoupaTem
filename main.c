#include <stdio.h>
#include "proj.h"

int main(){
//  Limite do número de clientes cadastráveis:
    Cliente clientes[1000];
//  Variável que determina o número de clientes cadastrados:
    int numClientes = 0;
//  Variável usada para detectar qual opção será utilizada:
    int opcao;


//  Algoritmo de escolha de opções:
//  Neste trecho está armazenado o algoritmo onde o computador irá executar suas funcionalidades de acordo com a atividade do usuário.
    do {
     // Menu Principal:
        printf("\nBem-vindo ao Banco QuemPoupaTem!\n");
        printf("\n");
        printf("Qual operação gostaria de realizar hoje?\n");
        printf("1. Novo Cliente\n");
        printf("2. Apagar Cliente\n");
        printf("3. Listar Clientes\n");
        printf("4. Débito\n");
        printf("5. Depósito\n");
        printf("6. Extrato\n");
        printf("7. Transferência Entre Contas\n");
        printf("0. Sair\n");
        printf("\nDigite aqui o algarismo da funcionalidade desejada: ");
        scanf("%d", &opcao);

     // Se o input = 0, encerra o programa.
        if(opcao == 0){
            printf("\n");
            printf("Encerrando Banco...\n");
        }

     // Se o input do usuário = 1, cadastra uma novo cliente.
        else if(opcao == 1){
            cadastrarCliente(clientes, &numClientes);
        }

     // Se o input do usuário = 2, deleta uma tarefa de acordo com seu respectivo número.
        else if(opcao == 2){
            deletarCliente(clientes, &numClientes);
        }

     // Se o input do usuário = 3, listar as tarefas cadastradas.
        else if(opcao == 3){
            listarCliente(clientes, numClientes);
        }

     // Se o input do usuário = 4, realizar um débito.       
        else if(opcao == 4){
            debitoCliente(clientes, &numClientes);
            adicionarTransacao(&clientes[0], 'C', clientes[0].valor_inicial);
        }
            
     // Se o input do usuário = 5, realizar um depósito.       
        else if(opcao == 5){
            depositoCliente(clientes, &numClientes);
            adicionarTransacao(&clientes[0], 'D', clientes[0].valor_inicial);
        }

     // Se o input do usuário = 7, realizar uma tranferência entre contas.
        else if(opcao == 7){
            transferenciaClientes(clientes, &numClientes);
        }

     // Se o input do usuário não for nenhuma das opções acima, retorna erro.
        else{
            printf("\n");
            printf("ERRO: Funcionalidade inexistente.\n");
            printf("==================================\n");
        }
     
    } while (opcao != 0);
//     ^ manter o loop enquanto opção != 0.

 // Comando de escrita no arquivo binário:
    FILE *file = fopen("clientes.bin", "wb");
    if (file) {
        fwrite(clientes, sizeof(Cliente), numClientes, file);
        fclose(file);
    } else {
        printf("Erro ao salvar cliente. Tente novamente ou reinicie o programa.\n");
    }
    
    return 0;
}
