#include <stdio.h>

#define TAMANHO 7
#define PINO     1
#define VAZIO    0
#define INVALIDO -1

int tabuleiro[TAMANHO][TAMANHO] = {
    {-1, -1,  1,  1,  1, -1, -1},
    {-1, -1,  1,  1,  1, -1, -1},
    { 1,  1,  1,  1,  1,  1,  1},
    { 1,  1,  1,  0,  1,  1,  1},  // centro vazio
    { 1,  1,  1,  1,  1,  1,  1},
    {-1, -1,  1,  1,  1, -1, -1},
    {-1, -1,  1,  1,  1, -1, -1}
};

// Imprime o tabuleiro no terminal
void imprimirTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == INVALIDO)
                printf("  ");       // espaço para posições inválidas
            else if (tabuleiro[i][j] == PINO)
                printf("● ");       // pino
            else
                printf("○ ");       // vazio
        }
        printf("\n");
    }
}

int main() {
    imprimirTabuleiro();
    return 0;
}
