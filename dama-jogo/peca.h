// peca.h

#ifndef PECA_H
#define PECA_H

#include <SDL.h>

#define TAMANHO_PECA 80

typedef enum {
    VAZIO,
    PEAO_BRANCO,
    PEAO_PRETO,
} TipoPeca;

typedef struct {
    TipoPeca tipo;
    int linha;
    int coluna;
} PecaTabuleiro;

void inicializarTabuleiro(PecaTabuleiro tabuleiro[][8]);
void exibirTabuleiro(SDL_Renderer *renderizador, PecaTabuleiro tabuleiro[][8]);
void handleEvent(SDL_Event *evento, PecaTabuleiro tabuleiro[][8]);

#endif // PECA_H