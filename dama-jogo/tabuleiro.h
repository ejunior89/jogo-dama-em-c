#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "peca.h"

void inicializarTabuleiro(PecaTabuleiro tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibirTabuleiro(PecaTabuleiro tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
int movimentoValido(PecaTabuleiro tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int jogador,
                    int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
void executarMovimento(PecaTabuleiro tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int *jogador,
                        int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

#endif // TABULEIRO_H