#include "Renderer.h"

using namespace std;

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}


void Renderer::DrawGrid(const int width,const int height) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 150);
    for (int x = 0; x < width; x += 20) {
        SDL_RenderDrawLine(renderer, x, 0, x, height);
    }
    for (int y = 0; y < height; y += 20) {
        SDL_RenderDrawLine(renderer, 0, y, width, y);
    }
}


void Renderer::DrawCells(const Game& game) {
    SDL_SetRenderDrawColor(renderer, 152, 251, 152,250);
    for (int x = 0; x < game.GetWidth(); x++) {
        for (int y = 0; y < game.GetHight(); y++) {
            if (game.GetConditionOfCell(x, y) == true) {
                SDL_Rect rect = { x * game.GetCellSize() + 2 ,
                    y * game.GetCellSize() + 2 ,
                    game.GetCellSize() - 5,
                    game.GetCellSize() - 5
                };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

void Renderer::DrawButton(const Button& button) {
    SDL_SetRenderDrawColor(renderer,
        button.IsActive() ? 0 : 255,
        button.IsActive() ? 255 : 0,
        0, 255);
    SDL_RenderFillRect(renderer, &button.getButton());
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &button.getButton());
}

int Renderer::GetDelay() const{
    return delay;
}

void Renderer::SetDelay(int new_delay) {
    if (new_delay <= 0 || new_delay >= 500) {
        return;
    }
    delay = new_delay;
}

void Renderer::render(const Button& start_button, const Button& pause_button, const Button& speed_button,
    const Button& slow_button, const Game& game, const int width, const int height) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    DrawGrid(width,height);
    DrawCells(game);
    DrawButton(start_button);
    DrawButton(pause_button);
    DrawButton(speed_button);
    DrawButton(slow_button);
    start_button.RenderText(renderer);
    pause_button.RenderText(renderer);
    speed_button.RenderText(renderer);
    slow_button.RenderText(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(delay);
}


SDL_Renderer* Renderer::GetRenderer() {
    return renderer;
}