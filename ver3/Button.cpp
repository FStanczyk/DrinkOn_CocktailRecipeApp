#include "Button.h"
//#include "globals.h"


Button::Button(int x, int y):sRect{ x,y, 96, 46 }, dRect {x,y, 96, 46}
{
	static SDL_Texture* t = IMG_LoadTexture(renderer, "drinks_options_prt.png");
	static SDL_Texture* t2 = IMG_LoadTexture(renderer, "alcohols_buttons.png");
	static SDL_Texture* t3 = IMG_LoadTexture(renderer, "game/game_drinks.png");
	texture = t;
	texture2 = t2;
	texture3 = t3;
	selected = false;
}

void Button::setXY(int x, int y)
{
	dRect.x = x;
	dRect.y = y;
}

void Button::checkSelected(Mouse* mouse)
{
	if(SDL_HasIntersection(&(mouse->tip), &dRect)) {
		selected = true;
		sRect.x = 96;
	}
	else {
		selected = false;
		sRect.x = 0;
	}
}

void Button::draw()
{
	SDL_RenderCopy(renderer, texture, &sRect, &dRect);
}
void Button::draw2()
{
	SDL_RenderCopy(renderer, texture2, &sRect, &dRect);
}
void Button::draw3()
{
	SDL_RenderCopy(renderer, texture3, &sRect, &dRect);
}