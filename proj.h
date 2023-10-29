// struct "Cliente" que define as informações do cliente e seus componentes:
typedef struct {
    char nome[1000];
    char cpf[12];
    char tipo_conta[6];
    double valor_inicial;
    char senha[100];
} Cliente;

// Declaração das funções do "proj.c":
void cadastrarCliente(Cliente clientes[], int *numClientes);
void listarCliente(Cliente clientes[], int numClientes);
