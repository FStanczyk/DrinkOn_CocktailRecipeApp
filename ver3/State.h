#pragma once
#include "Globals.h"
#include "Button.h"
#include "Mouse.h"
#include <sstream>

using namespace std;
class State
{
public:
	SDL_Texture* logo;
	SDL_Texture* drinksOptions;
	Mouse* mouse;
	State();
	virtual ~State();
	virtual void enter() = 0;
	virtual void update() = 0;
};
class Menu : public State {

public:
	Button* recipes;
	Button* alcohols;
	Button* game;
	Menu();
	virtual ~Menu();
	void enter();
	void update();
};
class Alcohol_List : public Menu {
public:
	SDL_Rect displayRect{ 15, 15, 175, 215 };
	SDL_Rect textRect{ 220, 10, 400, 100 };
	SDL_Texture* textTexture;
	SDL_Texture* displayTexture;
	SDL_Texture* alcohols_txt;
	SDL_Texture* vodka;
	SDL_Texture* vodka_text;
	SDL_Texture* white_rum;
	SDL_Texture* cointreau;
	SDL_Texture* blue_curacao;
	SDL_Texture* kahlua;
	SDL_Texture* jagermeister;
	SDL_Texture* grenadine;
	SDL_Texture* jack_daniels;
	SDL_Texture* absinth;
	SDL_Texture* tequila;
	SDL_Texture* metaxa;
	SDL_Texture* aperol;
	SDL_Texture* ginebra;
	SDL_Texture* bombay;
	SDL_Texture* malibu;
	SDL_Texture* white_rum_text;
	SDL_Texture* cointreau_text;
	SDL_Texture* blue_curacao_text;
	SDL_Texture* kahlua_text;
	SDL_Texture* jagermeister_text;
	SDL_Texture* grenadine_text;
	SDL_Texture* jack_daniels_text;
	SDL_Texture* absinth_text;
	SDL_Texture* tequila_text;
	SDL_Texture* metaxa_text;
	SDL_Texture* aperol_text;
	SDL_Texture* ginebra_text;
	SDL_Texture* bombay_text;
	SDL_Texture* malibu_text;
	enum ButtonNames{VODKA, WHITE_RUM, COINTREAU, BLUE_CURACAO, KAHLUA, JAGERMEISTER, GRENADINE, JACK_DANIELS,
	ABSINTH, TEQUILA, METAXA, APEROL, GINEBRA, BOMBAY, MALIBU};

	Button* button[15];
	Button* menuButton;
	Alcohol_List();
	virtual ~Alcohol_List();
	void update();
	

};

class The_Game : public Menu {
public:
	int space = 100;
	int alcohol_amount = 0;
	int liqueur_amount = 0;
	int juice_amount = 0;



	TTF_Font* vcr = TTF_OpenFont("VCR_OSD_MONO.ttf", 24);
	SDL_Color Black = { 1, 1, 1, 255 };


	SDL_Surface* Score;
	SDL_Texture* Score_Texture;
	SDL_Rect* rscore = new SDL_Rect{ SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2 - 20, 45, 30 };


	SDL_Rect* rscoreboard = new SDL_Rect{ SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 50, 200, 100 };
	SDL_Rect* rray = new SDL_Rect { SCREEN_WIDTH - 200, 160, 180, 20 };
	SDL_Rect* rray2 = new SDL_Rect { SCREEN_WIDTH - 200, 230, 180, 20 };
	SDL_Rect* rray3 = new SDL_Rect { SCREEN_WIDTH - 200, 300, 180, 20 };
	SDL_Rect* rswitcher = new SDL_Rect{ SCREEN_WIDTH - 198, 162, 5, 15 };
	SDL_Rect* rswitcher2 = new SDL_Rect{ SCREEN_WIDTH - 198, 232, 5, 15 };
	SDL_Rect* rswitcher3 = new SDL_Rect{ SCREEN_WIDTH - 198, 302, 5, 15 };
	SDL_Texture* scoreboard;
	SDL_Texture* game_panel;
	SDL_Texture* ray;
	SDL_Texture* ray2;
	SDL_Texture* ray3;
	SDL_Texture* switcher;
	SDL_Texture* switcher2;
	SDL_Texture* switcher3;
	Button* serve;
	Button* empty;
	Button* empty2;
	Button* empty3;
	Button* clear;
	Button* amount;
	enum drinksNames{
		VODKA, WHITE_RUM, COINTREAU, BLUE_CURACAO, KAHLUA, JAGERMEISTER, GRENADINE, JACK_DANIELS,
		ABSINTH, TEQUILA, METAXA, APEROL, GINEBRA, BOMBAY, MALIBU, ORANGE, GRAPE, PINAPPLE, COCONUT,
		COLA, SPRITE
	};
	Button* drinks[21];
	Button* menuButton;
	The_Game();
	virtual ~The_Game();
	void update();
};


class Options : public State {
public:
	SDL_Texture* mojito;
	SDL_Texture* cuba_libre;
	SDL_Texture* sex_on_the_beach;
	SDL_Texture* blue_lagoon;
	SDL_Texture* aura_in_me;
	SDL_Texture* black_russian;
	SDL_Texture* bazooka_joe;
	SDL_Texture* bed_of_roses;
	SDL_Texture* cosmopolitan;
	SDL_Texture* daiquiri;
    enum ButtonNames { MOJITO, CUBA_LIBRE, SEX_ON_THE_BEACH, BLUE_LAGOON, AURA_IN_ME, BLACK_RUSSIAN, BAZOOKA_JOE, BED_OF_ROSES, COSMOPOLITAN, DAIQUIRI};

    Button* button[10];
	Button *menuButton;
	Options();
	virtual ~Options();
	void enter();
	void update();
};

class Mojito : public Options {
public:
	Mojito();
	virtual ~Mojito();
	void update();

};
class Cuba_Libre : public Options {
public:
	Cuba_Libre();
	virtual ~Cuba_Libre();
	void update();

};

class Sex_On_The_Beach : public Options {
public:
	Sex_On_The_Beach();
	virtual ~Sex_On_The_Beach();
	void update();

};

class Blue_Lagoon : public Options {
public:
	Blue_Lagoon();
	virtual ~Blue_Lagoon();
	void update();

};
class Aura_In_Me : public Options {
public:
	Aura_In_Me();
	virtual ~Aura_In_Me();
	void update();

};
class Black_Russian : public Options {
public:
	Black_Russian();
	virtual ~Black_Russian();
	void update();

};
class Bazooka_Joe : public Options {
public:
	Bazooka_Joe();
	virtual ~Bazooka_Joe();
	void update();

};
class Bed_Of_Roses : public Options {
public:
	Bed_Of_Roses();
	virtual ~Bed_Of_Roses();
	void update();

};
class Cosmopolitan : public Options {
public:
	Cosmopolitan();
	virtual ~Cosmopolitan();
	void update();

};
class Daiquiri : public Options {
public:
	Daiquiri();
	virtual ~Daiquiri();
	void update();

};

