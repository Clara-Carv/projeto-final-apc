#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definição da estrutura (Global)
struct Produto {
    int id;
    char nome[30];
    int qtd;
    float preco;
};

// Protótipos das Funções (Isso garante o requisito do item 2 do PDF)
void cabecalho();
void cadastrar(struct Produto estoque[], int *total);
void listar(struct Produto estoque[], int total);

int main() {
    setlocale(LC_ALL, "Portuguese"); // Para aceitar acentos
    struct Produto estoque[100]; // Capacidade para 100 produtos
    int totalProdutos = 0;
    int opcao = 0;

    do {
        cabecalho(); // Chama a função de desenho
        printf("\n1 - Cadastrar Produto");
        printf("\n2 - Listar Estoque");
        printf("\n0 - Sair");
        printf("\n\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar(estoque, &totalProdutos);
                break;
            case 2:
                listar(estoque, totalProdutos);
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
        system("pause"); // Pausa para ler antes de limpar
        system("cls");   // Limpa a tela (Windows)

    } while (opcao != 0);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

void cabecalho() {
    // Aqui entra o requisito de "melhorar a aparência" 
    printf("========================================\n");
    printf("   SISTEMA DE ESTOQUE - LIVROS UNB      \n");
    printf("========================================\n");
    printf("      ___   _      _                    \n");
    printf("     / _ \\ | |    | |                   \n");
    printf("    / /_\\ \\| | ___| |__                 \n");
    printf("    |  _  || |/ _ \\ '_ \\                \n");
    printf("    | | | || |  __/ |_) |               \n");
    printf("    \\_| |_/|_|\\___|_.__/                \n");
    printf("========================================\n");
}

void cadastrar(struct Produto estoque[], int *total) {
    // Lógica simples de cadastro
    printf("\n--- NOVO CADASTRO ---\n");
    estoque[*total].id = *total + 1;
    
    printf("Nome do produto: ");
    fflush(stdin); // Limpa buffer teclado
    gets(estoque[*total].nome); 
    
    printf("Quantidade: ");
    scanf("%d", &estoque[*total].qtd);
    
    printf("Preço: ");
    scanf("%f", &estoque[*total].preco);
    
    (*total)++; // Incrementa o contador de produtos
    printf("\nSucesso! Produto cadastrado.\n");
}

void listar(struct Produto estoque[], int total) {
    // Mostra como no exemplo do PDF 
    printf("\nID\tNome\t\tQtd\tPreço\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < total; i++) {
        printf("%d\t%s\t\t%d\tR$ %.2f\n", 
            estoque[i].id, 
            estoque[i].nome, 
            estoque[i].qtd, 
            estoque[i].preco);
    }
    printf("----------------------------------------\n");
}1