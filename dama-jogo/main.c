// main.c

#include <SDL.h>
#include "peca.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erro ao inicializar a SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *janela = SDL_CreateWindow("Jogo de Damas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);
    if (janela == NULL) {
        fprintf(stderr, "Erro ao criar a janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    if (renderizador == NULL) {
        fprintf(stderr, "Erro ao criar o renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(janela);
        SDL_Quit();
        return 1;
    }

    PecaTabuleiro tabuleiro[8][8];
    inicializarTabuleiro(tabuleiro);

    int rodando = 1;
    while (rodando) {
        SDL_Event evento;
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                rodando = 0;
            }
            handleEvent(&evento, tabuleiro);
        }

        SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 255);
        SDL_RenderClear(renderizador);

        exibirTabuleiro(renderizador, tabuleiro);

        SDL_RenderPresent(renderizador);
    }

    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
