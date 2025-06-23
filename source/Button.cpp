#include "Button.h"
using namespace std;

Button::Button(const string& t,const int x,const int y, const int w,const int h) : text(t) {
	rect = { x,y,w,h };
	font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 12);
}

Button::~Button() {
	TTF_CloseFont(font);
}

bool Button::IsActive() const {
	return active;
}


bool Button::IsClicked(const int mouse_click_x, const int mouse_click_y) {
	if (mouse_click_x >= rect.x && mouse_click_x <= rect.x + rect.w &&
		mouse_click_y >= rect.y && mouse_click_y <= rect.y + rect.h) {
		return true;
	}
	return false;
}

SDL_Rect Button::getButton() const {
	return rect;
}

void Button::SetButton(bool state) {
	active = state;
}

void Button::RenderText(SDL_Renderer* renderer) const{
	if (font) {
		SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect textRect = {
				rect.x + (rect.w - surface->w) / 2,
				rect.y + (rect.h - surface->h) / 2,
				surface->w,
				surface->h
		};
		SDL_RenderCopy(renderer, texture, NULL, &textRect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}	
}