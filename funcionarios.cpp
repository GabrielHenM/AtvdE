#include <stdio.h>
#include <stdlib.h>


struct Funcionario {

    char nome[100];
    char cargo[100];
    double salario_base;
    double beneficios;
    double descontos;
    double salario_liquido;

    void ler() {
        printf("Digite o nome do funcionario: ");
        scanf(" %[^\n]%*c", nome);

        printf("Digite o cargo do funcionario: ");
        scanf(" %[^\n]%*c", cargo);

        printf("Digite o salario base do funcionario: ");
        scanf("%lf%*c", &salario_base);

        printf("Digite o valor dos beneficios: ");
        scanf("%lf%*c", &beneficios);

        printf("Digite o valor dos descontos: ");
        scanf("%lf%*c", &descontos);

        salario_liquido = salario_base + beneficios - descontos;
    }

    void imprimir() {

        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salario base: R$%.2lf\n", salario_base);
        printf("Beneficios: R$%.2lf\n", beneficios);
        printf("Descontos: R$%.2lf\n", descontos);
        printf("Salario liquido: R$%.2lf\n", salario_liquido);
        printf("\n");

    }
};

struct Loja {

    int qtd;
    Funcionario funcionarios[10];
    double media_salarial;
    Funcionario maior_salario;

    void cadastrarFuncionario() {

        if (qtd >= 10) {
            printf("Limite de 10 funcionarios atingido!\n");
            return;

        }

        printf("\nCadastro do funcionario %d:\n", qtd + 1);
        funcionarios[qtd].ler();
        qtd++;

        calcularMediaSalarial();
        encontrarMaiorSalario();

    }

    void calcularMediaSalarial() {
        double total = 0;
        for (int i = 0; i < qtd; i++) {
            total += funcionarios[i].salario_liquido;
        }

        media_salarial = total / qtd;
    }

    void encontrarMaiorSalario() {
        maior_salario = funcionarios[0];

        for (int i = 1; i < qtd; i++) {
            if (funcionarios[i].salario_liquido > maior_salario.salario_liquido) {
                maior_salario = funcionarios[i];

            }
        }
    }

    void imprimirFuncionarios() {
        if (qtd == 0) {
            printf("Nenhum funcionario cadastrado!\n");
            return;
        }

        system("cls");

        for (int i = 0; i < qtd; i++) {
            printf("Funcionario %d:\n", i + 1);
            funcionarios[i].imprimir();
        }

        printf("Media salarial: R$%.2lf\n", media_salarial);
        printf("Funcionario com maior salario: %s (R$%.2lf)\n", maior_salario.nome, maior_salario.salario_liquido);
    }
};

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Mostrar funcionarios\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {

    Loja l;
    l.qtd = 0;
    int opcao;

    do {

        exibirMenu();
        scanf("%d%*c", &opcao);
        system("cls");

        switch (opcao) {

            case 1:

                l.cadastrarFuncionario();

                break;

            case 2:

                l.imprimirFuncionarios();

                break;

            case 0:

                system("cls");
                printf("Programa encerrado!\n");

                break;

            default:

                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
