#include <stdio.h>
#include <stdlib.h>
#include <ctime>

struct Data {

    int dia, mes, ano;

    void ler() {

        scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    }

    void imprimir() {

        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }

    int calcularIdade() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        Data hoje;
        hoje.dia = now->tm_mday;
        hoje.mes = now->tm_mon + 1;
        hoje.ano = now->tm_year + 1900;

        int idade = hoje.ano - ano;

        if (mes > hoje.mes || (mes == hoje.mes && dia > hoje.dia)) {
            idade--;
        }

        return idade;
    }
};

struct Cliente {

    char nome[100];
    char sexo;
    int idade;
    struct Data dataNascimento;

    void ler() {

        system("cls");
        printf("\nCadastro de Cliente\n");
        printf("\n");

        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]%*c", nome);

        printf("Digite o sexo (M/F): ");
        scanf("%c%*c", &sexo);

        printf("Digite a data de nascimento (dd/mm/aaaa): ");
        dataNascimento.ler();

        idade = dataNascimento.calcularIdade();
    }

    void imprimir() {

        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Data de nascimento: ");
        dataNascimento.imprimir();
        printf("Idade: %d anos\n", idade);
    }
};

void exibirMenu() {

    printf("\nMenu\n");
    printf("1  Cadastrar cliente\n");
    printf("2  Listar clientes\n");
    printf("0  Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {

    Cliente clientes[50];
    int quantidadeClientes = 0;
    int opcao;

    do {

        exibirMenu();
        scanf("%d%*c", &opcao);
        system("cls");

        switch (opcao) {

            case 1:
                if (quantidadeClientes < 50) {
                    clientes[quantidadeClientes].ler();
                    quantidadeClientes++;
                    printf("\nO cliente foi cadastrado!\n");
                } else {
                    system("cls");
                    printf("Nao e possivel cadastrar mais clientes, limite atingido!\n");
                }

                break;

            case 2:

                system("cls");
                if (quantidadeClientes == 0) {
                    printf("Nenhum cliente foi cadastrado!\n");
                } else {
                    printf("Lista de Clientes\n");
                    for (int i = 0; i < quantidadeClientes; i++) {
                        printf("\nCliente %d:\n", i + 1);
                        clientes[i].imprimir();
                    }
                }

                break;

            case 0:

                system("cls");
                printf("Programa encerrado!\n");

                break;

            default:

                system("cls");
                printf("Selecione uma opcao correta!.\n");

                break;
        }

    } while (opcao != 0);

    return 0;
}
