#include <stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Cliente {
    char nome[100];
    struct Data nascimento;
    char sexo;
    int idade;
};


int calcularIdade(struct Data nascimento) {
    int idade = 2024 - nascimento.ano;


    if (nascimento.mes > 9 || (nascimento.mes == 9 && nascimento.dia > 25)) {
        idade--;
    }

    return idade;
}

void cadastrarCliente(struct Cliente* cliente) {
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente->nome);
    printf("Digite o dia de nascimento: ");
    scanf("%d", &cliente->nascimento.dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &cliente->nascimento.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &cliente->nascimento.ano);
    printf("Digite o sexo (M ou F): ");
    scanf(" %c", &cliente->sexo);


    cliente->idade = calcularIdade(cliente->nascimento);
}

void listarClientes(struct Cliente clientes[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\nCliente %d\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Data de Nascimento: %02d/%02d/%04d\n", clientes[i].nascimento.dia, clientes[i].nascimento.mes, clientes[i].nascimento.ano);
        printf("Sexo: %c\n", clientes[i].sexo);
        printf("Idade: %d anos\n", clientes[i].idade);
    }
}

int main() {
    struct Cliente clientes[50];
    int quantidadeClientes = 0;
    int opcao = 1;

    while (opcao != 0) {

        printf("\nMenu:\n");
        printf("Digite 1 para cadastrar um cliente\n");
        printf("Digite 2 para listar clientes\n");
        printf("Digite 0 para sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);


        if (opcao == 1) {
            if (quantidadeClientes < 50) {
                cadastrarCliente(&clientes[quantidadeClientes]);
                quantidadeClientes++;
            } else {
                printf("Limite de clientes atingido!\n");
            }
        } else if (opcao == 2) {
            if (quantidadeClientes == 0) {
                printf("Nenhum cliente cadastrado.\n");
            } else {
                listarClientes(clientes, quantidadeClientes);
            }
        } else if (opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
