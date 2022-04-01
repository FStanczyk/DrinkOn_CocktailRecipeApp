#pragma once
#include "Globals.h"
#include "Mouse.h"
class Button
{
public:

	SDL_Texture* texture;
	SDL_Texture* texture2;
	SDL_Texture* texture3;
	SDL_Rect sRect, dRect;  //Source rect (sprite sheet), direction rect (where on the screen)
	bool selected;
	Button() {}
	Button(int x, int y);
	void setXY(int x, int y);

	void checkSelected(Mouse* mouse);

	void draw();   //drinks cocktails
	void draw2();  //acohol list
	void draw3();  //game
	~Button(){}
};

