#include"State.h"
#include <SDL_ttf.h>

using namespace std;

int main(int argc, char* args[]) {

    while (1) {
		current->enter();
		current->update();
	}


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}