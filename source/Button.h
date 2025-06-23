#pragma once
#include <SDL.h>
#include <string>
#include<SDL_ttf.h>



class Button {
public:
	Button(const std::string& t, const int x, const int y, const int w, const int h);
	~Button();
	void SetButton(bool state);
	bool IsClicked(const int x, const int y);
	bool IsActive() const;
	SDL_Rect getButton() const;
	void RenderText(SDL_Renderer* renderer) const;
private:
	SDL_Color color = { 0, 0, 0,0 };
	TTF_Font* font = nullptr;
	SDL_Rect rect;
	std::string text;
	bool active = false;
};