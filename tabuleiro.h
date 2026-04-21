/* Integrantes: Marcelo Fernandes de Oliveira Junior */
#ifndef TABULEIRO_H
#define TABULEIRO_H
 
#define TAMANHO  7
#define PINO     1
#define VAZIO    0
#define INVALIDO -1
 
/* Tabuleiro em forma de cruz 7x7
   -1 = posicao invalida (fora da cruz)
    0 = buraco vazio
    1 = pino */
extern int tabuleiro[TAMANHO][TAMANHO];
 
/* Inicializa o tabuleiro com a configuracao padrao do Resta Um
   (32 pinos, centro vazio em [3][3]) */
void inicializarTabuleiro();
 
/* Imprime o tabuleiro atual */
void imprimirTabuleiro();
 
#endif