/* Integrantes: Marcelo Fernandes de Oliveira Junior */
#include <stdio.h>
#include "tabuleiro.h"
#include "movimento.h"
 
// gcc -Wall -o restaum main.c tabuleiro.c movimento.c <---- compilacao

int main() {
    printf("=== RESTA UM - Solucao por Backtracking ===\n\n");
 
    printf("Tabuleiro inicial:\n\n");
    imprimirTabuleiro();
 
    printf("Buscando solucao, aguarde...\n\n");
 
    if (resolver(0)) {
        imprimirTabuleiro(); /* tabuleiro final (so o centro preenchido) */
    } else {
        printf("\nNenhuma solucao encontrada.\n");
    }
 
    return 0;
}
