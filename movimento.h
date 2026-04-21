/* Integrantes: Marcelo Fernandes de Oliveira Junior */
#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#define TOTAL_MOVIMENTOS 31

/* Direcoes possiveis: cima, baixo, esquerda, direita */
extern int direcoes[4][2];

/* Estrutura que representa um movimento realizado */
typedef struct {
    int linhaA, colunaA;   /* posicao de origem (pino que salta) */
    int linhaB, colunaB;   /* posicao do meio  (pino removido)   */
    int linhaC, colunaC;   /* posicao de destino (onde vai parar) */
} Movimento;

/* Historico de movimentos da solucao */
extern Movimento historico[TOTAL_MOVIMENTOS];

/* Retorna 1 se a posicao (linha, coluna) e valida no tabuleiro */
int posicaoValida(int linha, int coluna);

/* Retorna 1 se o movimento a partir de (linha, coluna) na direcao dir e valido
   Condicao: A=PINO, B=PINO, C=VAZIO */
int movimentoValido(int linha, int coluna, int dir);

/* Executa o movimento e salva no historico na posicao 'passo' */
void fazerMovimento(int linhaA, int colunaA, int dir, int passo);

/* Desfaz o movimento do historico na posicao 'passo' (backtrack) */
void desfazerMovimento(int passo);

/* Imprime a sequencia de movimentos da solucao encontrada */
void imprimirSolucao();

/* Funcao principal de backtracking
   Retorna 1 se encontrou solucao, 0 caso contrario */
int resolver(int passo);

#endif 