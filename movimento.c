/* Integrantes: Marcelo Fernandes de Oliveira Junior */
#include <stdio.h>
#include "tabuleiro.h"
#include "movimento.h"

/* Direcoes: cima, baixo, esquerda, direita */
int direcoes[4][2] = {
    {-1,  0},   /* cima      */
    { 1,  0},   /* baixo     */
    { 0, -1},   /* esquerda  */
    { 0,  1}    /* direita   */
};

/* Historico dos 31 movimentos da solucao */
Movimento historico[TOTAL_MOVIMENTOS];

/* posicaoValida: checa se (linha, coluna) esta dentro
   dos limites do tabuleiro e nao e posicao invalida*/
int posicaoValida(int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO) return 0;
    if (coluna < 0 || coluna >= TAMANHO) return 0;
    if (tabuleiro[linha][coluna] == INVALIDO) return 0;
    return 1;
}

/*movimentoValido: verifica se o pino em (linha, coluna)
   pode saltar na direcao 'dir'
   A=origem(PINO), B=meio(PINO), C=destino(VAZIO)*/
int movimentoValido(int linha, int coluna, int dir) {
    int linhaB  = linha  + direcoes[dir][0];
    int colunaB = coluna + direcoes[dir][1];
    int linhaC  = linha  + 2 * direcoes[dir][0];
    int colunaC = coluna + 2 * direcoes[dir][1];

    if (!posicaoValida(linhaB, colunaB)) return 0;
    if (!posicaoValida(linhaC, colunaC)) return 0;

    return (tabuleiro[linha] [coluna]  == PINO  &&
            tabuleiro[linhaB][colunaB] == PINO  &&
            tabuleiro[linhaC][colunaC] == VAZIO);
}

/* fazerMovimento: executa o salto e registra no historico
   A vira VAZIO, B e removido (VAZIO), C recebe o PINO*/
void fazerMovimento(int linhaA, int colunaA, int dir, int passo) {
    int linhaB  = linhaA + direcoes[dir][0];
    int colunaB = colunaA + direcoes[dir][1];
    int linhaC  = linhaA + 2 * direcoes[dir][0];
    int colunaC = colunaA + 2 * direcoes[dir][1];

    tabuleiro[linhaA][colunaA] = VAZIO;
    tabuleiro[linhaB][colunaB] = VAZIO;
    tabuleiro[linhaC][colunaC] = PINO;

    historico[passo].linhaA  = linhaA;
    historico[passo].colunaA = colunaA;
    historico[passo].linhaB  = linhaB;
    historico[passo].colunaB = colunaB;
    historico[passo].linhaC  = linhaC;
    historico[passo].colunaC = colunaC;
}

/* desfazerMovimento: reverte o movimento do historico
   (backtrack) restaurando o estado anterior*/
void desfazerMovimento(int passo) {
    Movimento m = historico[passo];

    tabuleiro[m.linhaA][m.colunaA] = PINO;
    tabuleiro[m.linhaB][m.colunaB] = PINO;
    tabuleiro[m.linhaC][m.colunaC] = VAZIO;
}

// imprimirSolucao: exibe os 31 movimentos encontrados
void imprimirSolucao() {
    int i;
    printf("\n\n=== SOLUCAO ENCONTRADA ===\n\n");
    printf("%-6s  %-12s  %-12s  %-12s\n",
           "Passo", "Origem (A)", "Removido (B)", "Destino (C)");
    printf("--------------------------------------------------\n");

    for (i = 0; i < TOTAL_MOVIMENTOS; i++) {
        Movimento m = historico[i];
        printf("  %-4d  (%d,%d)         (%d,%d)         (%d,%d)\n",
               i + 1,
               m.linhaA, m.colunaA,
               m.linhaB, m.colunaB,
               m.linhaC, m.colunaC);
    }

    printf("\n=== TABULEIRO FINAL ===\n\n");
}

/* resolver: backtracking recursivo
   Tenta todos os movimentos possiveis a partir do
   estado atual. Retorna 1 se encontrou solucao.*/
int resolver(int passo) {
    int i, j, dir;

    /* Feedback para o usuario a cada 100.000 chamadas */
    static long long tentativas = 0;
    tentativas++;
    if (tentativas % 500000 == 0) {
        printf("  tentativas: %lld | passo atual: %d\n", tentativas, passo);
        fflush(stdout);
    }


    /* Condicao de vitoria: 31 movimentos e pino no centro */
    if (passo == TOTAL_MOVIMENTOS) {
        if (tabuleiro[3][3] == PINO) {
            imprimirSolucao();
            return 1;
        }
        return 0;
    }

    /* Percorre todas as posicoes do tabuleiro */
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {

            /* So tenta se houver pino nessa posicao */
            if (tabuleiro[i][j] != PINO) continue;

            /* Tenta cada uma das 4 direcoes */
            for (dir = 0; dir < 4; dir++) {
                if (movimentoValido(i, j, dir)) {

                    fazerMovimento(i, j, dir, passo);   /* faz o movimento  */

                    if (resolver(passo + 1))             /* recursao         */
                        return 1;                        /* solucao achada!  */

                    desfazerMovimento(passo);            /* backtrack        */
                }
            }
        }
    }

    return 0; /* nenhum movimento levou a solucao neste ramo */
}