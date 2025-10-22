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
    // Dois horizontais/verticais + dois diagonais

    // Navio horizontal
    int linhaH = 1, colH = 2;
    for (j = 0; j < 3; j++) {
        if (colH + j < 10)
            tabuleiro[linhaH][colH + j] = 3;
    }

    // Navio vertical
    int linhaV = 5, colV = 7;
    for (i = 0; i < 3; i++) {
        if (linhaV + i < 10)
            tabuleiro[linhaV + i][colV] = 3;
    }

    // Navio diagonal principal (↘)
    int linhaD1 = 3, colD1 = 3;
    for (i = 0; i < 3; i++) {
        if (linhaD1 + i < 10 && colD1 + i < 10)
            if (tabuleiro[linhaD1 + i][colD1 + i] == 0)
                tabuleiro[linhaD1 + i][colD1 + i] = 3;
    }

    // Navio diagonal secundária (↙)
    int linhaD2 = 2, colD2 = 8;
    for (i = 0; i < 3; i++) {
        if (linhaD2 + i < 10 && colD2 - i >= 0)
            if (tabuleiro[linhaD2 + i][colD2 - i] == 0)
                tabuleiro[linhaD2 + i][colD2 - i] = 3;
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
