#include <stdio.h>
#include <stdlib.h>

struct Conjunto {
    int elementos[20];
    int tamanho;

    void criarConjuntoVazio() {
        tamanho = 0;
    }

    void lerConjunto() {
        printf("Digite o numero de elementos do conjunto maximo 20: ");
        scanf("%d", &tamanho);

        if (tamanho > 20) {
            printf("Limite de elementos atingido!\n");
            tamanho = 20;
        }

        for (int i = 0; i < tamanho; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &elementos[i]);
        }
    }

    Conjunto uniao(Conjunto outroConjunto) {
        Conjunto resultado;
        resultado.criarConjuntoVazio();

        for (int i = 0; i < tamanho; i++) {
            resultado.elementos[resultado.tamanho++] = elementos[i];
        }

        for (int i = 0; i < outroConjunto.tamanho; i++) {
            int existe = 0;
            for (int j = 0; j < resultado.tamanho; j++) {
                if (outroConjunto.elementos[i] == resultado.elementos[j]) {
                    existe = 1;
                    break;
                }
            }

            if (!existe) {
                resultado.elementos[resultado.tamanho++] = outroConjunto.elementos[i];
            }
        }

        return resultado;

    }

    Conjunto intersecao(Conjunto outroConjunto) {
        Conjunto resultado;
        resultado.criarConjuntoVazio();

        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < outroConjunto.tamanho; j++) {
                if (elementos[i] == outroConjunto.elementos[j]) {
                    int existe = 0;

                    for (int k = 0; k < resultado.tamanho; k++) {
                        if (resultado.elementos[k] == elementos[i]) {
                            existe = 1;

                            break;
                        }
                    }


                    if (!existe) {
                        resultado.elementos[resultado.tamanho++] = elementos[i];
                    }

                    break;
                }
            }
        }

        return resultado;
    }

    void imprimirConjunto() {

        if (tamanho == 0) {
            printf("Conjunto vazio!\n");

        } else {
            printf("Conjunto: ");

            for (int i = 0; i < tamanho; i++) {
                printf("%d ", elementos[i]);
            }

            printf("\n");
        }
    }
};

void exibirMenu() {
    printf("\nMenu de Opcoes\n");
    printf("1 - Ler Conjunto\n");
    printf("2 - Fazer Uniao de Conjuntos\n");
    printf("3 - Fazer Intersecao de Conjuntos\n");
    printf("4 - Imprimir Conjuntos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {

    Conjunto A, B, uniaoAB, intersecaoAB;
    int opcao;

    A.criarConjuntoVazio();
    B.criarConjuntoVazio();
    uniaoAB.criarConjuntoVazio();
    intersecaoAB.criarConjuntoVazio();

    do {

        exibirMenu();
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {

            case 1:

                printf("Ler Conjunto A:\n");
                A.lerConjunto();
                system("cls");
                printf("Ler Conjunto B:\n");
                B.lerConjunto();
                system("cls");
                printf("Conjuntos A e B foram lidos.\n");

                break;

            case 2:

                uniaoAB = A.uniao(B);
                printf("Uniao de A e B: ");
                uniaoAB.imprimirConjunto();

                break;

            case 3:

                intersecaoAB = A.intersecao(B);
                printf("Intersecao de A e B: ");
                intersecaoAB.imprimirConjunto();

                break;

            case 4:

                printf("Imprimir Conjunto A:\n");
                A.imprimirConjunto();
                printf("Imprimir Conjunto B:\n");
                B.imprimirConjunto();

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
