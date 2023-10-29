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
