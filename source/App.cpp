#include "App.h"
#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

App::App() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw runtime_error("Error initializing SDL");
        system("pause");
    }
    if (TTF_Init() == -1) {
        throw std::runtime_error("TTF init failed");
    }
    window = SDL_CreateWindow("The Game Of Life", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        throw runtime_error("Error initializing SDL");
        system("pause");
    }
    renderer = make_unique<Renderer>(window);
    if (!window || !renderer) {
        throw runtime_error("Error initializing SDL");
        system("pause");
    }
    game = make_unique<Game>((width-100) / 20, height / 20);
    start_button = make_unique<Button>("start button",910,100,80,40);
    pause_button = make_unique<Button>("pause button",910,250,80,40);
    start_button->SetButton(false);
    pause_button->SetButton(true);
    slow_button = make_unique<Button>("slow button",910,400,80,40);
    speed_button = make_unique<Button>("speed button",910,550,80,40);
}


App::~App() {
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::HandleEvents() {
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (start_button->IsClicked(event.button.x, event.button.y)) {
                        game->Start();
                        start_button->SetButton(true);
                        pause_button->SetButton(false);
                    }
                    else if (pause_button->IsClicked(event.button.x, event.button.y)) {
                        game->Pause();
                        start_button->SetButton(false);
                        pause_button->SetButton(true);
                    }
                    else if (slow_button->IsClicked(event.button.x, event.button.y)) {
                        renderer->SetDelay(renderer->GetDelay() + 10);
                    }
                    else if (speed_button->IsClicked(event.button.x, event.button.y)) {
                        renderer->SetDelay(renderer->GetDelay() - 10);
                    }
                    else {
                        if (!game->IsSimulationRanning()) {
                            game->ToggleCell(event.button.x, event.button.y);
                        }
                    }
                }
                break;
            case SDL_QUIT:
                running = 0;
                break;
            }
        }
        game->DoSimulation();
        renderer->render(*start_button,*pause_button,*speed_button,*slow_button, *game, width - 100, height);
    }
}

