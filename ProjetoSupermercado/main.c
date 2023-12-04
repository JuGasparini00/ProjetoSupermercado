#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 1000    // define a quantidade maxima para a estrutura produto

typedef struct {    // define uma estrutura
    int id;    // define uma variavel de nome "id" como int
    char nome[100];    // define uma variavel vetor com o nome "nome" do tipo char suportando 100 entradas
    float preco;    // define a variavel de nome "preco" como float
    int quantidade;    // deline a variavel com nome "quantidade" como int
} Produto;    // termino da definicao da estrutura e foi nomeada de "Produto"

void adicionarProduto(Produto *produtos, int *totalProdutos, int id);    // iniciacao de uma funcao criada
void alterarPreco(Produto *produtos, int totalProdutos, int id, float novoPreco);    // iniciacao de uma funcao criada
void checarEstoque(Produto *produtos, int totalProdutos, int id);    // iniciacao de uma funcao criada
void listarProdutos(Produto *produtos, int totalProdutos);    // iniciacao de uma funcao criada

void adicionarProduto(Produto *produtos, int *totalProdutos, int id) {    // funcao responsavel por adicionar um produto a uma lista
    for (int i = 0; i < *totalProdutos; i++) {    // uma estrutura de repeticao para conferir disponibilidade de numero de "id"
        if (produtos[i].id == id) {    // funcao responsavel por checar se a condicao de cima eh verdadeira ou nao
            printf("ID ja existente! Atualizando a quantidade.\n");    // funcao responsavel por retornar  uma resposta ao usuario
            printf("Digite a quantidade a ser adicionada ao estoque: ");    // funcao responsavel por retornar  uma resposta ao usuario
            int quantidadeAdicional;
            scanf("%d", &quantidadeAdicional);
            produtos[i].quantidade += quantidadeAdicional;    // funcao responsavel por alterar a quantidade de um item
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }

    if (*totalProdutos >= MAX_ITENS) {    // funcao responsavel por determinar se o usuario passou do limite de produtos
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", produtos[*totalProdutos].nome);

    printf("Digite o preco do produto: ");
    scanf("%f", &produtos[*totalProdutos].preco);

    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d", &produtos[*totalProdutos].quantidade);

    produtos[*totalProdutos].id = id;
    (*totalProdutos)++;
    printf("Produto adicionado com sucesso!\n");
}

void alterarPreco(Produto *produtos, int totalProdutos, int id, float novoPreco) {    // funcao responsavel por alterar o valor de algum produto ja existente
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {   // uma estrutura para procurar o "id" do produto a ter seu valor alterado
            produtos[i].preco = novoPreco;   // substituicao do valor antigo do produto pelo valor novo
            printf("Preco alterado com sucesso!\n");
            return;
        }
    }

    printf("Produto nao encontrado!\n");
}

void checarEstoque(Produto *produtos, int totalProdutos, int id) {    // funcao responsavel por checar o estoque de um determinado item
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
            return;
        }
    }

    printf("Produto nao encontrado!\n");
}

void listarProdutos(Produto *produtos, int totalProdutos) {    // funcao responsavel por montar uma lista com os item ja adicionados contendo seu "id", "nome", "valor" e "quantidade"
    printf("\nListagem de Produtos:\n");
    printf("ID\tNome\t\tPreco\tQuantidade\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("%d\t%-15s\t%.2f\t%d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

int main() {
    Produto produtos[MAX_ITENS];    // define a quantidade maxima para a estrutura produto
    int totalProdutos = 0;    // define uma variavel de nome "totalProdutos" como int
    int escolha;    // define uma variavel de nome "escolha" como int

    do {    // um laco de repeticao o qual cria um menu numerico para o usuario
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Alterar Preco\n");
        printf("3. Checar Estoque\n");
        printf("4. Listar Produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        int id;    // define uma variavel de nome "id" como int
        float novoPreco;    // define uma variavel de nome "novoPreco" como float

        switch (escolha) {    // estrutura condicional de escolhas
            case 1:    // caso o usuario entre com o valor "1"
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                adicionarProduto(produtos, &totalProdutos, id);
                break;
            case 2:    // caso o usuario entre com o valor "2"
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                printf("Digite o novo preco: ");
                scanf("%f", &novoPreco);
                alterarPreco(produtos, totalProdutos, id, novoPreco);
                break;
            case 3:    // caso o usuario entre com o valor "3"
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                checarEstoque(produtos, totalProdutos, id);
                break;
            case 4:    // caso o usuario entre com o valor "4"
                listarProdutos(produtos, totalProdutos);
                break;
            case 0:    // caso o usuario entre com o valor "0"
                printf("Fim do programa...\n");
                break;
            default:    // caso o usuario entre com uma opcao invalida
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (escolha != 0);    // encerramento do laco de repeticao

    return 0;
}