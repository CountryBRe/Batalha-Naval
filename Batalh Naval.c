#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// Códigos ANSI para cores para melhor visualização
#define AZUL "\033[1;34m"
#define VERDE "\033[1;32m"
#define RESET "\033[0m"

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    int linhaH = 1, colunaH = 2;
    for (int i = 0; i < 3; i++)
        tabuleiro[linhaH][colunaH + i] = 3;

    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < 3; i++)
        tabuleiro[linhaV + i][colunaV] = 3;
}

void mostrarTabuleiro(int tabuleiro[TAM][TAM], int revelado[TAM][TAM]) {
    printf("    ");
    for (int col = 1; col <= TAM; col++)
        printf("%2d ", col);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAM; j++) {
            if (revelado[i][j]) {
                if (tabuleiro[i][j] == 3)
                    printf(VERDE " X " RESET); // Acertou
                else
                    printf(AZUL " O " RESET); // Água
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int revelado[TAM][TAM] = {0};

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    int linha, coluna;

    while (1) {
        system("clear || cls"); // Limpa a tela
        mostrarTabuleiro(tabuleiro, revelado);

        printf("\nEscolha uma posição para atacar (linha 1–10, coluna 1–10): ");
        scanf("%d %d", &linha, &coluna);
        linha -= 1;
        coluna -= 1;

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("⚠️  Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        if (revelado[linha][coluna]) {
            printf("⛔ Você já atacou essa posição! Escolha outra.\n");
            continue;
        }

        revelado[linha][coluna] = 1;

        // Exibe o resultado diretamente no novo tabuleiro
        system("clear || cls");
        mostrarTabuleiro(tabuleiro, revelado);

        if (tabuleiro[linha][coluna] == 3)
            printf(VERDE "\n🎯 ACERTO! Você atingiu um navio!\n" RESET);
        else
            printf(AZUL "\n💦 ÁGUA! Nenhum navio encontrado.\n" RESET);
    }

    return 0;
}