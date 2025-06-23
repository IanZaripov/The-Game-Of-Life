#pragma once
#include <SDl.h>
#include "Game.h"
#include "Renderer.h"
#include "Button.h"
#include <memory>

class App {
public:
	App();
	~App();
	void HandleEvents();
private:
	SDL_Window* window;
	std::unique_ptr<Renderer> renderer;
	std::unique_ptr<Button> start_button;
	std::unique_ptr<Button> pause_button;
	std::unique_ptr<Button> slow_button;
	std::unique_ptr<Button> speed_button;
	std::unique_ptr<Game> game;
	unsigned int width = 1000;
	unsigned int height = 700;
};