#include <stdio.h>
#include <stdlib.h>

struct Livro {

    char titulo[100];
    char autor[100];
    int num_paginas;


    void ler() {

        system("cls");
        printf("\nCadastro de Livro\n");
        printf("\n");

        printf("Digite o titulo do livro: ");
        scanf(" %[^\n]%*c", titulo);

        printf("Digite o autor do livro: ");
        scanf(" %[^\n]%*c", autor);

        printf("Digite o numero de paginas: ");
        scanf("%d%*c", &num_paginas);

    }

    void imprimir() {

        printf("Titulo: %s\n", titulo);
        printf("Autor: %s\n", autor);
        printf("Numero de paginas: %d\n", num_paginas);
        printf("\n");

    }
};

struct Biblioteca {

    Livro livros[10];
    int qtd_livros;


    void lerNovoLivro() {

        if (qtd_livros < 10) {
            livros[qtd_livros].ler();
            qtd_livros++;
            printf("\nO livro foi cadastrado!\n");

        } else {
            system("cls");
            printf("Nao e possivel cadastrar mais livros, limite atingido!\n");

        }
    }


    void imprimirTodosLivros() {

        system("cls");

        if (qtd_livros == 0) {
            printf("Nenhum livro foi cadastrado!\n");

        } else {

            printf("\nLista de Livros\n");

            for (int i = 0; i < qtd_livros; i++) {
                printf("\nLivro %d:\n", i + 1);
                livros[i].imprimir();

            }
        }
    }


    void imprimirMaiorLivro() {

        system("cls");

        if (qtd_livros == 0) {
            printf("Nenhum livro foi cadastrado!\n");
            return;

        }

        Livro maior_livro = livros[0];

        for (int i = 1; i < qtd_livros; i++) {
            if (livros[i].num_paginas > maior_livro.num_paginas) {
                maior_livro = livros[i];
            }
        }

        printf("Livro com maior numero de paginas:\n");
        maior_livro.imprimir();
    }
};


void exibirMenu() {
    printf("\nMenu\n");
    printf("1  Cadastrar livro\n");
    printf("2  Listar livros\n");
    printf("3  Imprimir livro com maior numero de paginas\n");
    printf("0  Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {

    Biblioteca biblioteca;
    biblioteca.qtd_livros = 0;

    int opcao;

    do {

        exibirMenu();
        scanf("%d%*c", &opcao);

        switch (opcao) {
            case 1:

                biblioteca.lerNovoLivro();

                break;

            case 2:

                biblioteca.imprimirTodosLivros();

                break;

            case 3:

                biblioteca.imprimirMaiorLivro();

                break;

            case 0:

                system("cls");
                printf("Programa encerrado!\n");

                break;

            default:

                system("cls");
                printf("Selecione uma opcao correta!\n");

                break;
        }

    } while (opcao != 0);

    return 0;
}
