// peca.c

#include <SDL.h>
#include "peca.h"

void inicializarTabuleiro(PecaTabuleiro tabuleiro[][8]) {
    // Lógica de inicialização do tabuleiro aqui
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                tabuleiro[i][j].tipo = PEAO_BRANCO;
            } else if ((i + j) % 2 == 0 && i > 4) {
                tabuleiro[i][j].tipo = PEAO_PRETO;
            } else {
                tabuleiro[i][j].tipo = VAZIO;
            }
            tabuleiro[i][j].linha = i;
            tabuleiro[i][j].coluna = j;
        }
    }
}

void exibirTabuleiro(SDL_Renderer *renderizador, PecaTabuleiro tabuleiro[][8]) {
    // Lógica de renderização do tabuleiro usando SDL aqui
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            SDL_Rect retangulo = {j * TAMANHO_PECA, i * TAMANHO_PECA, TAMANHO_PECA, TAMANHO_PECA};

            if (tabuleiro[i][j].tipo == PEAO_BRANCO) {
                SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 255);
                SDL_RenderFillRect(renderizador, &retangulo);
            } else if (tabuleiro[i][j].tipo == PEAO_PRETO) {
                SDL_SetRenderDrawColor(renderizador, 0, 0, 0, 255);
                SDL_RenderFillRect(renderizador, &retangulo);
            }
            // Para VAZIO, não faz nada
        }
    }
}

void handleEvent(SDL_Event *evento, PecaTabuleiro tabuleiro[][8]) {
    // Lógica de manipulação de eventos aqui
    if (evento->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        int coluna = mouseX / TAMANHO_PECA;
        int linha = mouseY / TAMANHO_PECA;

        printf("Clique na posição: Linha %d, Coluna %d\n", linha, coluna);

        // Aqui você pode adicionar lógica adicional para lidar com o clique na posição (linha, coluna)
    }
}
