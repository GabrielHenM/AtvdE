#include <stdio.h>
#include <stdlib.h>

struct Data {

    int dia, mes, ano;

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
        scanf("%d/%d/%d%*c", &dataNascimento.dia, &dataNascimento.mes, &dataNascimento.ano);

        calcularIdade();

    }

    void imprimir() {

        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Data de nascimento: %02d/%02d/%04d\n", dataNascimento.dia, dataNascimento.mes, dataNascimento.ano);
        printf("Idade: %d anos\n", idade);

    }

    void calcularIdade() {

        struct Data dataAtual = {24, 9, 2024};

        idade = dataAtual.ano - dataNascimento.ano;

        if (dataNascimento.mes > dataAtual.mes ||
           (dataNascimento.mes == dataAtual.mes && dataNascimento.dia > dataAtual.dia)) {
            idade--;

        }
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
