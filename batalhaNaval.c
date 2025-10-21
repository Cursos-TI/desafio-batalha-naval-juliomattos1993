#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas dos navios
    int linhaH = 2, colH = 4;
    int linhaV = 5, colV = 7;

    // Posiciona navio horizontal
    for (j = 0; j < 3; j++) {
        tabuleiro[linhaH][colH + j] = 3;
    }

    // Posiciona navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colV] = 3;
    }

    // Exibe o tabuleiro
    printf("\n     A  B  C  D  E  F  G  H  I  J\n");
    printf("   ---------------------------------\n");

    for (i = 0; i < 10; i++) {
        printf("%2d | ", i + 1);
        for (j = 0; j < 10; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("   ---------------------------------\n");

    return 0;
}
