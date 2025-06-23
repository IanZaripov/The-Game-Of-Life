#pragma once

#include "Game.h"
#include "Button.h"

class Renderer {
public:
	Renderer(SDL_Window* window);
	~Renderer();
	SDL_Renderer* GetRenderer();
	void DrawButton(const Button& button);
	void render(const Button& start_button,const Button& pause_button, const Button& speed_button, 
		const Button& slow_button,const Game& game,const int width,const int height);
	void SetDelay(int new_delay);
	int GetDelay() const;
private:
	void DrawGrid(const int width,const int height);
	void DrawCells(const Game& game);
	SDL_Renderer* renderer;
	int delay = 16;
};