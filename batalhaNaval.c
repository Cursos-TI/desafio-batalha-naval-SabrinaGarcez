#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5  // tamanho do tabuleiro
#define NAVIOS 3 // quantidade de navios

void mostrarTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("  ");
    for(int i=0;i<TAM;i++) printf("%d ", i);
    printf("\n");
    for(int i=0;i<TAM;i++) {
        printf("%d ", i);
        for(int j=0;j<TAM;j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int navios[NAVIOS][2], linha, coluna;

    // Inicializa tabuleiro
    for(int i=0;i<TAM;i++)
        for(int j=0;j<TAM;j++)
            tabuleiro[i][j] = '~';

    srand(time(NULL));
    // Posiciona navios aleatoriamente
    for(int i=0;i<NAVIOS;i++) {
        navios[i][0] = rand() % TAM;
        navios[i][1] = rand() % TAM;
    }

    printf("Batalha Naval - Tente acertar os navios!\n");
    int acertos = 0;

    while(acertos < NAVIOS) {
        mostrarTabuleiro(tabuleiro);
        printf("Digite linha e coluna: ");
        scanf("%d %d", &linha, &coluna);

        int hit = 0;
        for(int i=0;i<NAVIOS;i++) {
            if(linha == navios[i][0] && coluna == navios[i][1] && tabuleiro[linha][coluna] != 'X') {
                printf("Acertou um navio!\n");
                tabuleiro[linha][coluna] = 'X';
                acertos++;
                hit = 1;
            }
        }
        if(!hit && tabuleiro[linha][coluna] != 'X') {
            printf("Errou!\n");
            tabuleiro[linha][coluna] = 'O';
        }
    }
    printf("Parabéns! Todos os navios foram afundados!\n");
    return 0;
}