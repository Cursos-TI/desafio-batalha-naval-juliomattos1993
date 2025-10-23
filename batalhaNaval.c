#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    int tab[N][N];
    int navioAfetado[N][N];
    int i, j;

    // Inicializar tabuleiro
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i][j] = 0; // água
            navioAfetado[i][j] = 0;
        }
    }

    // Navio horizontal
    for(j = 2; j < 5; j++){
        tab[1][j] = 3;
    }

    // Navio vertical
    for(i = 5; i < 8; i++){
        tab[i][7] = 3;
    }

    // Navio diagonal ↘
    for(i = 0; i < 3; i++){
        tab[3 + i][3 + i] = 3;
    }

    // Navio diagonal ↙
    for(i = 0; i < 3; i++){
        tab[2 + i][8 - i] = 3;
    }

    // MATRIZES DE HABILIDADES (5x5)
    int cone[5][5], cruz[5][5], oct[5][5];
    int meio = 2;

    // CONE
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(abs(j - meio) <= i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // CRUZ
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // OCTAEDRO
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(abs(i - meio) + abs(j - meio) <= meio)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }

    // POSIÇÕES DAS HABILIDADES NO TABULEIRO
    int coneL = 0, coneC = 4;
    int cruzL = 4, cruzC = 2;
    int octL = 7, octC = 6;

    // APLICAR CONE
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(cone[i][j] == 1){
                int l = coneL + i;
                int c = coneC - 2 + j;
                if(l >= 0 && l < N && c >= 0 && c < N){
                    if(tab[l][c] == 3)
                        navioAfetado[l][c] = 1;
                    else
                        tab[l][c] = 5;
                }
            }
        }
    }

    // APLICAR CRUZ
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(cruz[i][j] == 1){
                int l = cruzL - 2 + i;
                int c = cruzC - 2 + j;
                if(l >= 0 && l < N && c >= 0 && c < N){
                    if(tab[l][c] == 3)
                        navioAfetado[l][c] = 1;
                    else
                        tab[l][c] = 5;
                }
            }
        }
    }

    // APLICAR OCTAEDRO
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(oct[i][j] == 1){
                int l = octL - 2 + i;
                int c = octC - 2 + j;
                if(l >= 0 && l < N && c >= 0 && c < N){
                    if(tab[l][c] == 3)
                        navioAfetado[l][c] = 1;
                    else
                        tab[l][c] = 5;
                }
            }
        }
    }

    // IMPRIMIR TABULEIRO
    printf("\n     A  B  C  D  E  F  G  H  I  J\n");
    printf("   ---------------------------------\n");
    for(i = 0; i < N; i++){
        printf("%2d | ", i + 1);
        for(j = 0; j < N; j++){
            if(navioAfetado[i][j] == 1)
                printf("X  ");
            else
                printf("%d  ", tab[i][j]);
        }
        printf("\n");
    }
    printf("   ---------------------------------\n");

    // MATRIZES (opcional)
    printf("\nMatriz CONE:\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz CRUZ:\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz OCTAEDRO:\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%d ", oct[i][j]);
        }
        printf("\n");
    }

    return 0;
}
