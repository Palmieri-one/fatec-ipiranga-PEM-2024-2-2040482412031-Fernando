/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: ANÁLISE DE CÓDIGO                      *
*                                                              *
* Data: 06/12/2024                                             * 
* Autor: Letícia Sudan Gauy E Fernando Palmieri                *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXPRODUTOS 50

typedef struct {
    int ID;
    char nomeProduto[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

void cadastrarProduto(Produto *listaProdutos, int *contadorProduto);
void alterarProduto(Produto *listaProdutos, int *contadorProduto);
void consultarProduto(Produto *listaProdutos, int contadorProduto);
void excluirProduto(Produto *listaProdutos, int *contadorProduto);
void imprimirDados(Produto *produto);
void venderProduto(Produto *listaProdutos, int *contadorProduto);
void imprimirLista(Produto *listaProdutos, int contadorProduto);
void descontoProduto(Produto *listaProdutos, int *contadorProduto);
void exibirMenu();
int lerInteiro();

void cadastrarProduto(Produto *listaProdutos, int *contadorProduto) {
    Produto *produto = &listaProdutos[*contadorProduto];
    produto->ID = *contadorProduto + 1;

    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]", produto->nomeProduto);

    // Garantir que a quantidade seja um número inteiro
    printf("Digite a quantidade em estoque do produto (Somente numeros naturais): ");
    while (scanf("%d", &produto->quantidadeEmEstoque) != 1 || produto->quantidadeEmEstoque < 0) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! A quantidade deve ser um numero inteiro positivo.\n");
        printf("Digite a quantidade em estoque do produto (Somente numeros naturais): ");
    }

    // Garantir que o valor seja um número flutuante válido
    printf("Digite o valor do produto: ");
    while (scanf("%lf", &produto->valorDoProduto) != 1 || produto->valorDoProduto < 0) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! O valor deve ser um numero valido e positivo.\n");
        printf("Digite o valor do produto: ");
    }

    (*contadorProduto)++;
    printf("Produto adicionado com sucesso!\n\n");
}

void imprimirDados(Produto *produto) {
    printf("\nID: %d\n", produto->ID);
    printf("Nome: %s\n", produto->nomeProduto);
    printf("Quantidade em estoque: %d\n", produto->quantidadeEmEstoque);
    printf("Valor do produto: %.2f\n\n", produto->valorDoProduto);
}

void alterarProduto(Produto *listaProdutos, int *contadorProduto) {
    int ID, i;
    printf("\nDigite o ID do produto que sera alterado: ");
    
    // Verifica se o ID é válido
    while (scanf("%d", &ID) != 1) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! O ID deve ser um numero inteiro.\n");
        printf("Digite o ID do produto que sera alterado: ");
    }

    // Verifica se o ID existe
    for (i = 0; i < *contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            printf("\nDados atuais do produto:\n");
            imprimirDados(&listaProdutos[i]);

            printf("\nDigite o nome do produto: ");
            scanf(" %[^\n]", listaProdutos[i].nomeProduto);

            // Garantir que a quantidade seja um número inteiro
            printf("Digite a quantidade em estoque do produto: ");
            while (scanf("%d", &listaProdutos[i].quantidadeEmEstoque) != 1 || listaProdutos[i].quantidadeEmEstoque < 0) {
                while (getchar() != '\n');  // Limpar o buffer de entrada
                printf("Entrada invalida! A quantidade deve ser um numero inteiro positivo.\n");
                printf("Digite a quantidade em estoque do produto: ");
            }

            // Garantir que o valor seja um número flutuante válido
            printf("Digite o valor do produto: ");
            while (scanf("%lf", &listaProdutos[i].valorDoProduto) != 1 || listaProdutos[i].valorDoProduto < 0) {
                while (getchar() != '\n');  // Limpar o buffer de entrada
                printf("Entrada invalida! O valor deve ser um numero valido e positivo.\n");
                printf("Digite o valor do produto: ");
            }

            printf("Produto alterado com sucesso!\n\n");
            return;
        }
    }

    // Se o ID não for encontrado
    printf("ID nao encontrado!\n\n");
}

void consultarProduto(Produto *listaProdutos, int contadorProduto) {
    int ID, i;
    printf("\nDigite o ID do produto que deseja consultar: ");
    
    // Verifica se o ID é válido
    while (scanf("%d", &ID) != 1) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! O ID deve ser um numero inteiro.\n");
        printf("Digite o ID do produto que deseja consultar: ");
    }

    // Busca o produto com o ID fornecido
    for (i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            imprimirDados(&listaProdutos[i]);
            return;
        }
    }

    // Se o ID não for encontrado
    printf("ID nao encontrado!\n\n");
}

void excluirProduto(Produto *listaProdutos, int *contadorProduto) {
    int ID, i;
    printf("\nDigite o ID do produto que deseja excluir: ");
    
    // Verifica se o ID é válido
    while (scanf("%d", &ID) != 1) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! O ID deve ser um numero inteiro.\n");
        printf("Digite o ID do produto que deseja excluir: ");
    }

    // Busca e exclui o produto com o ID fornecido
    for (i = 0; i < *contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            for (int j = i; j < *contadorProduto - 1; j++) {
                listaProdutos[j] = listaProdutos[j + 1];
            }
            (*contadorProduto)--;
            printf("Produto excluido com sucesso!\n\n");
            return;
        }
    }

    // Se o ID não for encontrado
    printf("ID nao encontrado!\n\n");
}

void venderProduto(Produto *listaProdutos, int *contadorProduto) {
    int ID, quantidade, i;
    printf("\nDigite o ID do produto que deseja vender: ");
    
    // Verifica se o ID é válido
    while (scanf("%d", &ID) != 1) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! O ID deve ser um numero inteiro.\n");
        printf("Digite o ID do produto que deseja vender: ");
    }

    // Busca o produto com o ID fornecido
    for (i = 0; i < *contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            printf("Digite a quantidade que sera vendida: ");
            while (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
                while (getchar() != '\n');  // Limpar o buffer de entrada
                printf("Entrada invalida! A quantidade deve ser um numero inteiro positivo maior que zero.\n");
                printf("Digite a quantidade que sera vendida: ");
            }

            if (listaProdutos[i].quantidadeEmEstoque >= quantidade) {
                listaProdutos[i].quantidadeEmEstoque -= quantidade;
                printf("Produto vendido com sucesso!\n");
                printf("Preco total da venda: %.2f\n\n", listaProdutos[i].valorDoProduto * quantidade);
                return;
            } else {
                printf("Estoque insuficiente!\n\n");
            }
        }
    }

    // Se o ID não for encontrado
    printf("ID nao encontrado!\n\n");
}

void imprimirLista(Produto *listaProdutos, int contadorProduto) {
    printf("\n------------- Lista de todos os produtos cadastrados -------------\n\n");
    for (int i = 0; i < contadorProduto; i++) {
        printf("ID: %d      Nome: %s\n", listaProdutos[i].ID, listaProdutos[i].nomeProduto);
    }
    printf("\n");
}

void descontoProduto(Produto *listaProdutos, int *contadorProduto) {
    int ID, i;
    double desconto;

    printf("\nDigite o ID do produto que recebera desconto: ");
    
    // Verifica se o ID é válido
    while (scanf("%d", &ID) != 1) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! O ID deve ser um numero inteiro.\n");
        printf("Digite o ID do produto que recebera desconto: ");
    }

    // Busca o produto com o ID fornecido
    for (i = 0; i < *contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            printf("Digite o valor do desconto (em porcentagem): ");
            while (scanf("%lf", &desconto) != 1 || desconto < 0 || desconto > 100) {
                while (getchar() != '\n');  // Limpar o buffer de entrada
                printf("Entrada invalida! O desconto deve ser um numero entre 0 e 100.\n");
                printf("Digite o valor do desconto (em porcentagem): ");
            }

            listaProdutos[i].valorDoProduto -= listaProdutos[i].valorDoProduto * (desconto / 100);
            printf("Desconto aplicado com sucesso!\n");
            printf("Novo valor do produto: %.2f\n\n", listaProdutos[i].valorDoProduto);
            return;
        }
    }

    // Se o ID não for encontrado
    printf("ID nao encontrado!\n\n");
}

void exibirMenu() {
    printf("------ * MENU * ------\n");
    printf("1. Cadastrar produto\n");
    printf("2. Alterar dados do produto\n");
    printf("3. Consultar produto\n");
    printf("4. Excluir Produto\n");
    printf("5. Consultar lista de produtos\n");
    printf("6. Vender produto\n");
    printf("7. Dar desconto a um produto\n");
    printf("8. Encerrar o programa\n");
}

int lerInteiro() {
    int numero;
    while (scanf("%d", &numero) != 1) {
        while (getchar() != '\n');  // Limpar o buffer de entrada
        printf("Entrada invalida! Digite um numero valido.\n");
    }
    return numero;
}

int main() {
    Produto listaProdutos[MAXPRODUTOS];
    int contadorProduto = 0;
    int opcao;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        while (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');  // Limpar o buffer de entrada
            printf("Entrada invalida! Digite um numero entre 1 e 8.\n");
            exibirMenu();
            printf("Escolha uma opcao: ");
        }

        switch (opcao) {
            case 1: cadastrarProduto(listaProdutos, &contadorProduto); break;
            case 2: alterarProduto(listaProdutos, &contadorProduto); break;
            case 3: consultarProduto(listaProdutos, contadorProduto); break;
            case 4: excluirProduto(listaProdutos, &contadorProduto); break;
            case 5: imprimirLista(listaProdutos, contadorProduto); break;
            case 6: venderProduto(listaProdutos, &contadorProduto); break;
            case 7: descontoProduto(listaProdutos, &contadorProduto); break;
            case 8: printf("\nObrigado por usar o nosso programa na sua loja!\n"); break;
            default: printf("\nO valor digitado nao e valido. Digite novamente: \n\n"); break;
        }

    } while (opcao != 8);

    return 0;
}