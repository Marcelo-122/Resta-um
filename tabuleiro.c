/* Integrantes: Marcelo Fernandes de Oliveira Junior */
#include <stdio.h>
#include "tabuleiro.h"

/* Estado inicial: 32 pinos, posicao central [3][3] vazia */
int tabuleiro[TAMANHO][TAMANHO] = {
    {-1, -1,  1,  1,  1, -1, -1},
    {-1, -1,  1,  1,  1, -1, -1},
    { 1,  1,  1,  1,  1,  1,  1},
    { 1,  1,  1,  0,  1,  1,  1},  /* centro vazio */
    { 1,  1,  1,  1,  1,  1,  1},
    {-1, -1,  1,  1,  1, -1, -1},
    {-1, -1,  1,  1,  1, -1, -1}
};

void inicializarTabuleiro() {
    int estado[TAMANHO][TAMANHO] = {
        {-1, -1,  1,  1,  1, -1, -1},
        {-1, -1,  1,  1,  1, -1, -1},
        { 1,  1,  1,  1,  1,  1,  1},
        { 1,  1,  1,  0,  1,  1,  1},
        { 1,  1,  1,  1,  1,  1,  1},
        {-1, -1,  1,  1,  1, -1, -1},
        {-1, -1,  1,  1,  1, -1, -1}
    };

    int i, j;
    for (i = 0; i < TAMANHO; i++)
        for (j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = estado[i][j];
}

void imprimirTabuleiro() {
    int i, j;
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == INVALIDO)
                printf("  ");
            else if (tabuleiro[i][j] == PINO)
                printf("o ");   /* pino */
            else
                printf(". ");   /* vazio */
        }
        printf("\n");
    }
    printf("\n");
}