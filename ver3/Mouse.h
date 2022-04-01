#pragma once
#include "Globals.h"
class Mouse
{
public:
	SDL_Texture* texture;
	SDL_Rect cursor, tip;

	Mouse();
	~Mouse();
	void draw();
};

