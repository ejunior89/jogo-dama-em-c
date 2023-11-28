#include <SDL.h>
#include "tabuleiro.h"

void inicializarTabuleiro(PecaTabuleiro tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Lógica de inicialização do tabuleiro aqui
}

void exibirTabuleiro(SDL_Renderer *renderizador, PecaTabuleiro tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Lógica de renderização do tabuleiro usando SDL aqui
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Desenha um retângulo simples para representar cada posição no tabuleiro
            SDL_Rect retangulo = {j * 100, i * 100, 100, 100};

            // Escolha a cor com base na posição para simular um tabuleiro xadrez
            if ((i + j) % 2 == 0) {
                SDL_SetRenderDrawColor(renderizador, 200, 200, 200, 255);
            } else {
                SDL_SetRenderDrawColor(renderizador, 100, 100, 100, 255);
            }

            SDL_RenderFillRect(renderizador, &retangulo);
        }
    }
}
