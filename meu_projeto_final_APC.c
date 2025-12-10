#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h> 


void barraCarregamento() {
    system("cls");
    system("color 0A"); 
    
    printf("\n\n\n");
    printf("      [ SISTEMA INICIANDO... ] \n\n");
    printf("      "); 
    
    for (int i = 0; i < 25; i++) {
        printf("=");      
        fflush(stdout);    
        Sleep(60);        
    }
    
    printf("\n\n      >> Modulos carregados com sucesso!");
    Sleep(1000); 
    system("cls");
}


void cabecalho() {
    system("cls");
    printf("==========================================\n");
    printf("  Q U I Z   D A   C O M P U T A Ç Ã O \n");
    printf("==========================================\n");
    printf("         .-------------------. \n");
    printf("         |   APC - QUIZ v1.0 | \n");
    printf("         |                   | \n");
    printf("         |      [ >_ ]       | \n"); 
    printf("         |___________________| \n");
    printf("              |  |   /___\\    \n"); 
    printf("           ___|__|___|   |     \n"); 
    printf("          |______________|     \n"); 
    printf("\n");
}

int fazerPergunta(char enunciado[], char a[], char b[], char c[], char correta){
    char respostaUsuario;
    system("cls");
    cabecalho(); 
    printf("\nPERGUNTA: %s\n", enunciado);
    printf("------------------------------------------\n");
    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", c);
    printf("------------------------------------------\n");
    printf("Sua resposta: ");

    scanf(" %c", &respostaUsuario); 
    fflush(stdin);
     
    respostaUsuario = toupper(respostaUsuario);

    if (respostaUsuario == correta){
        printf("\n>>> RESPOSTA CERTA! (+10 pontos) <<<\n");
        Sleep(1000); 
        return 10;
    } else {
        printf("\n>>> ERROU! A correta era %c <<<\n", correta);
        system("pause"); 
        return 0;
    }
}


int main(){
    system("chcp 65001");
    system("cls");
    
    
    barraCarregamento();

    int opcao = 0;
    int pontuacao = 0;

    do {
        cabecalho(); 
        printf("       1 - INICIAR O DESAFIO\n");
        printf("       2 - COMO JOGAR\n");
        printf("       0 - SAIR\n");
        printf("==========================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao) {
            case 1:
                pontuacao = 0; 
                
                
                pontuacao += fazerPergunta("Qual função imprime na tela?", 
                    "A) scanf", "B) printf", "C) main", 'B');
                
                pontuacao += fazerPergunta("Qual variavel guarda números reais?", 
                    "A) int", "B) char", "C) float", 'C');
                
                pontuacao += fazerPergunta("O que o comando 'break' faz?", 
                    "A) Interrompe o switch", "B) Repete o loop", "C) Apaga a tela", 'A');

                pontuacao += fazerPergunta("Qual laço executa PELO MENOS uma vez?", 
                    "A) for", "B) while", "C) do...while", 'C');

                pontuacao += fazerPergunta("O terminador de string e:", 
                    "A) \\0 (Nulo)", "B) \\n (Enter)", "C) %d (Decimal)", 'A');

                pontuacao += fazerPergunta("Onde fica a função printf?", 
                    "A) stdlib.h", "B) stdio.h", "C) string.h", 'B');
                
                system("cls");
                cabecalho();
                printf("\n       FIM DE JOGO! \n");
                printf("       Sua Pontuacao Final: %d de 60 pontos\n\n", pontuacao);
                
                if(pontuacao == 60) printf("       PERFEITO! VOCÊ É UM MESTRE!\n");
                else if(pontuacao >= 40) printf("       MUITO BEM! QUASE LA.\n");
                else printf("       QUE PENA... ESTUDE MAIS!\n");
                
                system("pause");
                break;

            case 2:
                system("cls");
                cabecalho();
                printf("\n--- INSTRUÇÕES ---\n");
                printf("1. Responda as 6 perguntas.\n");
                printf("2. Digite A, B ou C.\n");
                printf("3. Cada acerto vale 10 pontos.\n\n");
                system("pause");
                break;

            case 0:
                printf("\nSaindo...\n");
                Sleep(1000);
                break;

            default:
                printf("\nOpção inválida!\n");
                Sleep(1000);
        }

    } while (opcao != 0);  

    return 0;
}