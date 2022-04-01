#include "State.h"
#pragma warning(disable : 4996).

State::State() {
	static Mouse* m = new Mouse;
	mouse = m;
}
State::~State() {}

Menu::Menu() {
	logo = IMG_LoadTexture(renderer, "drinkon_logo_full.png");
	recipes = new Button(0,506);
	alcohols = new Button(0, 552);
	game = new Button(0, 598);
	game->setXY(SCREEN_WIDTH / 2 - (96 / 2), 260);
	alcohols->setXY(SCREEN_WIDTH / 2 - (96 / 2), 210);
	recipes->setXY(SCREEN_WIDTH / 2 - (96 / 2), 160);

}
Menu::~Menu() {
	SDL_DestroyTexture(logo);
	delete recipes;
	delete alcohols;
}
void Menu::enter() { cout << "Entering menu" << endl; }
void Menu::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (recipes->selected) {
						current = options;
						running = false;
					}
					if (alcohols->selected) {
						current = alcohol_list;
						running = false;
					}
					if (game->selected) {
						current = the_game;
						running = false;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, logo, NULL, NULL);
		recipes->checkSelected(mouse);
		recipes->draw();
		alcohols->checkSelected(mouse);
		alcohols->draw();
		game->checkSelected(mouse);
		game->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}
	
}

Options::Options() {
	drinksOptions = IMG_LoadTexture(renderer, "options_drink_choose.png");
	menuButton = new Button(0, 460);
	menuButton->setXY(SCREEN_WIDTH / 2 - (96 / 2), 400);
	button[MOJITO] = new Button(0, 0);
	button[CUBA_LIBRE] = new Button(0, 46);
	button[SEX_ON_THE_BEACH] = new Button(0, 92);
	button[BLUE_LAGOON] = new Button(0, 138);
	button[AURA_IN_ME] = new Button(0, 184);
	button[BLACK_RUSSIAN] = new Button(0, 230);
	button[BAZOOKA_JOE] = new Button(0, 276);
	button[BED_OF_ROSES] = new Button(0, 322);
	button[COSMOPOLITAN] = new Button(0, 368);
	button[DAIQUIRI] = new Button(0, 414);
	button[MOJITO]->setXY(SCREEN_WIDTH / 4 - 48, 170);
	button[CUBA_LIBRE]->setXY(SCREEN_WIDTH / 4 - 48, 220);
	button[SEX_ON_THE_BEACH]->setXY(SCREEN_WIDTH / 4 - 48, 270);
	button[BLUE_LAGOON]->setXY(SCREEN_WIDTH / 4 - 48, 320);
	button[AURA_IN_ME]->setXY((SCREEN_WIDTH / 4) * 2 - 48, 170);
	button[BLACK_RUSSIAN]->setXY((SCREEN_WIDTH / 4) * 2 - 48, 220);
	button[BAZOOKA_JOE]->setXY((SCREEN_WIDTH / 4) * 2 - 48, 270);
	button[BED_OF_ROSES]->setXY((SCREEN_WIDTH / 4) * 2 - 48, 320);
	button[COSMOPOLITAN]->setXY((SCREEN_WIDTH / 4) * 3 - 48, 170);
	button[DAIQUIRI]->setXY((SCREEN_WIDTH / 4) * 3 - 48, 220);

}
Options::~Options() {
	SDL_DestroyTexture(drinksOptions);
	delete menuButton;
	delete button[MOJITO];
	delete button[CUBA_LIBRE];
	delete button[SEX_ON_THE_BEACH];
	delete button[BLUE_LAGOON];
	delete button[AURA_IN_ME];
	delete button[BLACK_RUSSIAN];
	delete button[BAZOOKA_JOE];
	delete button[BED_OF_ROSES];
	delete button[COSMOPOLITAN];
	delete button[DAIQUIRI];
}
void Options::enter() { cout << "Entering Options" << endl; }
void Options::update() {
	bool running = true;
	SDL_Event e;

	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if(menuButton->selected)
					current = menu;
                    running = false;
				}			
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[MOJITO]->selected)
						current = smojito;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[CUBA_LIBRE]->selected)
						current = scuba_libre;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[SEX_ON_THE_BEACH]->selected)
						current = ssex_on_the_beach;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[BLUE_LAGOON]->selected)
						current = sblue_lagoon;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[AURA_IN_ME]->selected)
						current = saura_in_me;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[BLACK_RUSSIAN]->selected)
						current = sblack_russian;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[BAZOOKA_JOE]->selected)
						current = sbazooka_joe;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[BED_OF_ROSES]->selected)
						current = sbed_of_roses;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[COSMOPOLITAN]->selected)
						current = scosmopolitan;
					running = false;
				}
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (button[DAIQUIRI]->selected)
						current = sdaiquiri;
					running = false;
					break;
				}

			}
		}

		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, drinksOptions, NULL, NULL);
		for (auto n : button) {
			n->checkSelected(mouse);
			n->draw();
		}
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}
	
}


Alcohol_List::Alcohol_List()
{
	button[VODKA] = new Button(0, 0);
	button[WHITE_RUM] = new Button(0, 46);
	button[COINTREAU] = new Button(0, 92);
	button[BLUE_CURACAO] = new Button(0, 138);
	button[KAHLUA] = new Button(0, 184);
	button[JAGERMEISTER] = new Button(0, 230);
	button[GRENADINE] = new Button(0, 276);
	button[JACK_DANIELS] = new Button(0, 322);
	button[ABSINTH] = new Button(0, 368);
	button[TEQUILA] = new Button(0, 414);
	button[METAXA] = new Button(0, 460);
	button[APEROL] = new Button(0, 506);
	button[GINEBRA] = new Button(0, 552);
	button[BOMBAY] = new Button(0, 598);
	button[MALIBU] = new Button(0, 644);
	button[VODKA]->setXY(SCREEN_WIDTH / 3 , 120);
	button[WHITE_RUM]->setXY(SCREEN_WIDTH / 3, 170);
	button[COINTREAU]->setXY(SCREEN_WIDTH / 3, 220);
	button[BLUE_CURACAO]->setXY(SCREEN_WIDTH / 3, 270);
	button[KAHLUA]->setXY(SCREEN_WIDTH / 3, 320);
	button[JAGERMEISTER]->setXY(SCREEN_WIDTH / 3 + 100, 120);
	button[GRENADINE]->setXY(SCREEN_WIDTH / 3 + 100, 170);
	button[JACK_DANIELS]->setXY(SCREEN_WIDTH / 3 + 100, 220);
	button[ABSINTH]->setXY(SCREEN_WIDTH / 3 + 100, 270);
	button[TEQUILA]->setXY(SCREEN_WIDTH / 3 + 100, 320);
	button[METAXA]->setXY(SCREEN_WIDTH / 3 + 200, 120);
	button[APEROL]->setXY(SCREEN_WIDTH / 3 + 200, 170);
	button[GINEBRA]->setXY(SCREEN_WIDTH / 3 + 200, 220);
	button[BOMBAY]->setXY(SCREEN_WIDTH / 3 + 200, 270);
	button[MALIBU]->setXY(SCREEN_WIDTH / 3 + 200, 320);
	menuButton = new Button(0, 460);
	menuButton->setXY(SCREEN_WIDTH / 2 - (96 / 2), 400);
	alcohols_txt = IMG_LoadTexture(renderer, "alcohol_list.png");
	vodka = IMG_LoadTexture(renderer, "alcohols/vodka.png");
	vodka_text = IMG_LoadTexture(renderer, "info/vodka_text.png");
	white_rum = IMG_LoadTexture(renderer, "alcohols/bacardi.png");
	white_rum_text = IMG_LoadTexture(renderer, "info/bacardi_text.png");
	cointreau = IMG_LoadTexture(renderer, "alcohols/cointreau.png.png");
	cointreau_text = IMG_LoadTexture(renderer, "info/cointreau_text.png");
	blue_curacao = IMG_LoadTexture(renderer, "alcohols/curacao.png");
	blue_curacao_text = IMG_LoadTexture(renderer, "info/blue_curacao_text.png");
	jagermeister = IMG_LoadTexture(renderer, "alcohols/jager.png");
	jagermeister_text = IMG_LoadTexture(renderer, "info/jager_text.png");
	grenadine = IMG_LoadTexture(renderer, "alcohols/grenadine.png");
	grenadine_text = IMG_LoadTexture(renderer, "info/grenadine_text.png");
	jack_daniels = IMG_LoadTexture(renderer, "alcohols/daniels.png");
	jack_daniels_text = IMG_LoadTexture(renderer, "info/jack_text.png");
	kahlua = IMG_LoadTexture(renderer, "alcohols/kahlua.png");
	kahlua_text = IMG_LoadTexture(renderer, "info/kahlua_text.png");
	absinth = IMG_LoadTexture(renderer, "alcohols/absinth.png");
	absinth_text = IMG_LoadTexture(renderer, "info/absinth_text.png");
	tequila = IMG_LoadTexture(renderer, "alcohols/tequila.png");
	tequila_text = IMG_LoadTexture(renderer, "info/tequila_text.png");
	metaxa = IMG_LoadTexture(renderer, "alcohols/metaxa.png");
	metaxa_text = IMG_LoadTexture(renderer, "info/metaxa_text.png");
	aperol = IMG_LoadTexture(renderer, "alcohols/aperol.png");
	aperol_text = IMG_LoadTexture(renderer, "info/aperol_text.png");
	ginebra = IMG_LoadTexture(renderer, "alcohols/ginebra.png");
	ginebra_text = IMG_LoadTexture(renderer, "info/ginebra_text.png");
	bombay = IMG_LoadTexture(renderer, "alcohols/bombay.png");
	bombay_text = IMG_LoadTexture(renderer, "info/bombay_text.png");
	malibu = IMG_LoadTexture(renderer, "alcohols/malibu.png");
	malibu_text = IMG_LoadTexture(renderer, "info/malibu_text.png");
}
Alcohol_List::~Alcohol_List()
{
	SDL_DestroyTexture(alcohols_txt);
	delete button[VODKA];
	delete button[WHITE_RUM];
	delete button[COINTREAU];
	delete button[BLUE_CURACAO];
	delete button[KAHLUA];
	delete button[JAGERMEISTER];
	delete button[GRENADINE];
	delete button[JACK_DANIELS];
	delete button[ABSINTH];
	delete button[TEQUILA];
	delete button[METAXA];
	delete button[APEROL];
	delete button[GINEBRA];
	delete button[BOMBAY];
	delete button[MALIBU];
	delete menuButton;
}
void Alcohol_List::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = menu;
						running = false;
						break;
					}
				}
			case SDL_MOUSEMOTION:
				if (button[VODKA]->selected) {
					displayTexture = vodka;
					textTexture = vodka_text;
					break;
				}
				if (button[WHITE_RUM]->selected) {
					displayTexture = white_rum;
					textTexture = white_rum_text;
					break;
				}
				if (button[COINTREAU]->selected) {
					displayTexture = cointreau;
					textTexture = cointreau_text;
					break;
				}
				if (button[BLUE_CURACAO]->selected) {
					displayTexture = blue_curacao;
					textTexture = blue_curacao_text;
					break;
				}
				if (button[JAGERMEISTER]->selected) {
					displayTexture = jagermeister;
					textTexture = jagermeister_text;
					break;
				}
				if (button[GRENADINE]->selected) {
					displayTexture = grenadine;
					textTexture = grenadine_text;
					break;
				}
				if (button[JACK_DANIELS]->selected) {
					displayTexture = jack_daniels;
					textTexture = jack_daniels_text;
					break;
				}
				if (button[ABSINTH]->selected) {
					displayTexture = absinth;
					textTexture = absinth_text;
					break;
				}
				if (button[TEQUILA]->selected) {
					displayTexture = tequila;
					textTexture = tequila_text;
					break;
				}
				if (button[METAXA]->selected) {
					displayTexture = metaxa;
					textTexture = metaxa_text;
					break;
				}
				if (button[APEROL]->selected) {
					displayTexture = aperol;
					textTexture = aperol_text;
					break;
				}
				if (button[GINEBRA]->selected) {
					displayTexture = ginebra;
					textTexture = ginebra_text;
					break;
				}
				if (button[BOMBAY]->selected) {
					displayTexture = bombay;
					textTexture = bombay_text;
					break;
				}
				if (button[KAHLUA]->selected) {
					displayTexture = kahlua;
					textTexture = kahlua_text;
					break;
				}
				if (button[MALIBU]->selected) {
					displayTexture = malibu;
					textTexture = malibu_text;
				}
				else displayTexture = NULL, textTexture = NULL;
			}
			
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, alcohols_txt, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		for (auto n : button) {
			n->checkSelected(mouse);
			n->draw2();
		}
        SDL_RenderCopy(renderer, displayTexture, NULL, &displayRect);
		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}

The_Game::The_Game()
{

	ray = IMG_LoadTexture(renderer, "game/ray.png");
	ray2 = IMG_LoadTexture(renderer, "game/ray.png");
	ray3 = IMG_LoadTexture(renderer, "game/ray.png");

	logo = IMG_LoadTexture(renderer, "drinkon_logo_full.png");

	switcher = IMG_LoadTexture(renderer, "game/switcher.png");
	switcher2 = IMG_LoadTexture(renderer, "game/switcher.png");
	switcher3 = IMG_LoadTexture(renderer, "game/switcher.png");

	game_panel = IMG_LoadTexture(renderer, "game/game_panel.png");
	logo = IMG_LoadTexture(renderer, "drinkon_logo_full.png");
	scoreboard = IMG_LoadTexture(renderer, "game/scoreboard.png");
	menuButton = new Button(0, 460);
	menuButton->setXY(SCREEN_WIDTH / 2 - (96 / 2), 400);

	empty = new Button(0, 966);
	empty2 = new Button(0, 966);
	empty3 = new Button(0, 966);

	amount = new Button(0, 1058);
	amount->setXY(SCREEN_WIDTH/2 - 46, 200);

	empty->setXY(80, 145);
	empty2->setXY(80, 215);
	empty3->setXY(80, 285);

	clear = new Button(0, 1012);
	clear->setXY(80, 60);

	serve = new Button(0, 1104);
	serve->setXY(SCREEN_WIDTH / 2 - (96 / 2), 350);

	drinks[VODKA] = new Button(0, 0);
	drinks[WHITE_RUM] = new Button(0, 46);
	drinks[COINTREAU] = new Button(0, 92);
	drinks[BLUE_CURACAO] = new Button(0, 138);
	drinks[KAHLUA] = new Button(0, 184);
	drinks[JAGERMEISTER] = new Button(0, 230);
	drinks[GRENADINE] = new Button(0, 276);
	drinks[JACK_DANIELS] = new Button(0, 322);
	drinks[ABSINTH] = new Button(0, 368);
	drinks[TEQUILA] = new Button(0, 414);
	drinks[METAXA] = new Button(0, 460);
	drinks[APEROL] = new Button(0, 506);
	drinks[GINEBRA] = new Button(0, 552);
	drinks[BOMBAY] = new Button(0, 598);
	drinks[MALIBU] = new Button(0, 644);
	drinks[ORANGE] = new Button(0, 690);
	drinks[GRAPE] = new Button(0, 736);
	drinks[PINAPPLE] = new Button(0, 782);
	drinks[COCONUT] = new Button(0, 828);
	drinks[COLA] = new Button(0, 874);
	drinks[SPRITE] = new Button(0, 920);
	//alcohols
	drinks[VODKA]->setXY(((SCREEN_WIDTH / 5) * 4)-110, 85);
	drinks[WHITE_RUM]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 85);
	drinks[COINTREAU]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 135);
	drinks[JAGERMEISTER]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 135);
	drinks[JACK_DANIELS]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 185);
	drinks[ABSINTH]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 185);
	drinks[TEQUILA]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 235);
	drinks[METAXA]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 235);
	drinks[APEROL]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 285);
	drinks[GINEBRA]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 285);
	drinks[BOMBAY]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 335);
	//Liqueurs
	drinks[BLUE_CURACAO]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 85);
	drinks[KAHLUA]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 85);
	drinks[GRENADINE]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 135);
	drinks[MALIBU]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 135);
	drinks[COCONUT]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 185);
	//Juices
	drinks[ORANGE]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 85);
	drinks[GRAPE]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 85);
	drinks[PINAPPLE]->setXY(((SCREEN_WIDTH / 5) * 4) - 110, 135);
	drinks[COLA]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 135);
	drinks[SPRITE]->setXY(((SCREEN_WIDTH / 5) * 4) - 10, 185);

}
The_Game::~The_Game()
{
	TTF_Quit();
	delete drinks[VODKA];
	delete drinks[WHITE_RUM];
	delete drinks[COINTREAU];
	delete drinks[BLUE_CURACAO];
	delete drinks[JAGERMEISTER];
	delete drinks[GRENADINE];
	delete drinks[JACK_DANIELS];
	delete drinks[ABSINTH];
	delete drinks[METAXA];
	delete drinks[TEQUILA];
	delete drinks[APEROL];
	delete drinks[GINEBRA];
	delete drinks[BOMBAY];
	delete drinks[MALIBU];
	delete drinks[ORANGE];
	delete drinks[GRAPE];
	delete drinks[PINAPPLE];
	delete drinks[COCONUT];
	delete drinks[COLA];
	delete drinks[SPRITE];
	delete clear;
	delete menuButton;
	SDL_FreeSurface(Score);
	SDL_DestroyTexture(Score_Texture);

}	
void The_Game::update()
{
	bool display = true;
	bool inrect = false;
	bool inrect2 = false;
	bool inrect3 = false;
	bool serveSelected = false;
	bool amountSelected = false;
	bool alcoholSelected = false;
	bool liqueurSelected = false;
	bool juiceSelected = false;

	bool running = true;

	int wynik_koncowy;
	float wynik_alkoholu = 0;
	float wynik_likieru = 0;
	float wynik_soku = 0;
	float mnoznik_alkoholu = 0;
	float mnoznik_likieru = 0;
	float mnoznik_soku = 0;

	bool vodka_selected = false;
	bool cola_selected = false;
	bool grenadine_selected = false;
	bool orange_selected = false;
	bool rum_selected = false;
	bool cointreau_selected = false;
	bool malibu_selected = false;
	bool bombay_selected = false;
	bool jager_selected = false;
	bool metaxa_selected = false;
	bool aperol_selected = false;
	bool sprite_selected = false;
	bool pinapple_selected = false;
	bool grape_selected = false;
	bool coconut_selected = false;
	bool absinth_selected = false;
	bool jack_selected = false;
	bool tequila_selected = false;
	bool kahlua_selected = false;
	bool curacao_selected = true;
	bool ginebra_selected = false;

	SDL_Event e;
	while (running) {
		space = 175 - (alcohol_amount + liqueur_amount + juice_amount);
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = menu;
						running = false;
						break;
					}
					if (SDL_HasIntersection(&(mouse->tip), rswitcher)) {
						inrect = true;
						inrect2 = false;
						inrect3 = false;
					}
					if (SDL_HasIntersection(&(mouse->tip), rswitcher2)) {
						inrect = false;
						inrect2 = true;
						inrect3 = false;
					}
					if (SDL_HasIntersection(&(mouse->tip), rswitcher3)) {
						inrect = false;
						inrect2 = false;
						inrect3 = true;
					}
					if (inrect == true && mouse->tip.x > 442 && mouse->tip.x < 442 + (space + alcohol_amount) ) {
						rswitcher->x = mouse->tip.x;
						alcohol_amount = rswitcher->x - 442;

					}
					if (inrect2 == true && mouse->tip.x > 442 && mouse->tip.x < 442 + (space + liqueur_amount)) {
						rswitcher2->x = mouse->tip.x;
						liqueur_amount = rswitcher2->x - 442;
					}
					if (inrect3 == true && mouse->tip.x > 442 && mouse->tip.x < 442 + (space + juice_amount)) {
						juice_amount = rswitcher3->x - 442;
						rswitcher3->x = mouse->tip.x;
					}
					if (empty->selected) {
						alcoholSelected = true;
						liqueurSelected = false;
						juiceSelected = false;
					    amountSelected = false;
					}
					if (empty2->selected) {
						alcoholSelected = false;
					    liqueurSelected = true;
						juiceSelected = false;
						amountSelected = false;
					}
					if (empty3->selected) {
						alcoholSelected = false;
						liqueurSelected = false;
					    juiceSelected = true;
						amountSelected = false;
					}
					if (serve->selected) {
						display = false;
						serveSelected = true;
						alcoholSelected = false;
						liqueurSelected = false;
						juiceSelected = false;
						amountSelected = false;
						rum_selected = false;
						cointreau_selected = false;
						malibu_selected = false;

					}
					if (clear->selected) {
						cout << "JUICE" << juice_amount << endl;
						cout << "Liqueur" <<liqueur_amount << endl;
						cout << "ALCOHOL" << alcohol_amount << endl;
						cout << space << endl;

						alcohol_amount = 0;
						liqueur_amount = 0;
						juice_amount = 0;
						
						amountSelected = false;
						empty->sRect.y = 966;
						empty2->sRect.y = 966;
						empty3->sRect.y = 966;
						rswitcher->x = 442;
						rswitcher2->x = 442;
						rswitcher3->x = 442;

						alcoholSelected = false;
						liqueurSelected = false;
						juiceSelected = false;
					}
					if (amount->selected) {
						amountSelected = true;
						alcoholSelected = false;
						liqueurSelected = false;
						juiceSelected = false;
					}
					//alcohols
					if (drinks[VODKA]->selected) {
						empty->sRect.y = 0;
						mnoznik_alkoholu = 0.5;
						vodka_selected = true;
					}
					if (drinks[WHITE_RUM]->selected) {
						empty->sRect.y = 46;
						mnoznik_alkoholu = 0.5;
						rum_selected = true;
					}
					if (drinks[COINTREAU]->selected) {
						empty->sRect.y = 92;
						mnoznik_alkoholu = 0.5;
						cointreau_selected = true;
					}
					if (drinks[JAGERMEISTER]->selected) {
						empty->sRect.y = 230;
						mnoznik_alkoholu = 0.5;
						jager_selected = true;
					}
					if (drinks[JACK_DANIELS]->selected) {
						empty->sRect.y = 322;
						mnoznik_alkoholu = 0.5;
						jack_selected = true;
					}
					if (drinks[ABSINTH]->selected) {
						empty->sRect.y = 368;
						mnoznik_alkoholu = 0.5;
						absinth_selected = true;
					}
					if (drinks[TEQUILA]->selected) {
						empty->sRect.y = 414;
						mnoznik_alkoholu = 0.5;
						tequila_selected = true;
					}
					if (drinks[METAXA]->selected) {
						empty->sRect.y = 460;
						mnoznik_alkoholu = 0.5;
						metaxa_selected = true;
					}
					if (drinks[APEROL]->selected) {
						empty->sRect.y = 506;
						mnoznik_alkoholu = 0.5;
						aperol_selected = true;
					}
					if (drinks[GINEBRA]->selected) {
						empty->sRect.y = 552;
						mnoznik_alkoholu = 0.5;
						ginebra_selected = true;
					}
					if (drinks[BOMBAY]->selected) {
						empty->sRect.y = 598;
						mnoznik_alkoholu = 0.5;
						bombay_selected = true;
					}
					//liqueurs
					if (drinks[BLUE_CURACAO]->selected) {
						empty2->sRect.y = 138;
						mnoznik_likieru = 0.3;
						curacao_selected = true;
					}
					if (drinks[KAHLUA]->selected) {
						empty2->sRect.y = 184;
						mnoznik_likieru = 0.3;
						kahlua_selected = true;
					}
					if (drinks[GRENADINE]->selected) {
						empty2->sRect.y = 276;
						mnoznik_likieru = 0.3;
						grenadine_selected = true;
					}
					if (drinks[MALIBU]->selected) {
						empty2->sRect.y = 644;
						mnoznik_likieru = 0.3;
						malibu_selected = true;
					}
					if (drinks[COCONUT]->selected) {
						empty2->sRect.y = 828;
						mnoznik_likieru = 0.3;
						coconut_selected = true;
					}
					//juices
					if (drinks[ORANGE]->selected) {
						empty3->sRect.y = 690;
						mnoznik_soku = 0.2;
						orange_selected = true;
					}
					if (drinks[GRAPE]->selected) {
						empty3->sRect.y = 736;
						mnoznik_soku = 0.2;
						grape_selected = true;
					}
					if (drinks[PINAPPLE]->selected) {
						empty3->sRect.y = 782;
						mnoznik_soku = 0.2;
						pinapple_selected = true;
					}
					if (drinks[COLA]->selected) {
						empty3->sRect.y = 874;
						mnoznik_soku = 0.2;
						cola_selected = true;
					}
					if (drinks[SPRITE]->selected) {
						empty3->sRect.y = 920;
						mnoznik_soku = 0.2;
						sprite_selected = true;
					}

				}

			}
		}
		float x1 = (33 - alcohol_amount);
		if (x1 < 0) { x1 = -x1; }
		float x2 = (34 - liqueur_amount);
		if (x2 < 0) { x2 = -x2; }
		float x3 = (107 - juice_amount);
		if (x3 < 0) { x3 = -x3; }

		float xx1 = 5.303;
		float xx2 =5.147;
		float xx3 = 1.635;

		wynik_alkoholu = (175 - (xx1 * x1)) *mnoznik_alkoholu;
		wynik_likieru = (175 - (xx2*x2))* mnoznik_likieru;
		wynik_soku = (175 - (xx3*x3))* mnoznik_soku;
		
		wynik_koncowy = wynik_alkoholu + wynik_likieru + wynik_soku;

		//kombinacje specjalne
		if (vodka_selected == true && cola_selected == true) {
			wynik_koncowy = wynik_koncowy + 5;
		}
		if (orange_selected == true && grenadine_selected == true) {
			wynik_koncowy = wynik_koncowy + 5;
		}
		if (vodka_selected == true && curacao_selected == true && orange_selected == true) {
			wynik_koncowy = wynik_koncowy * 1.2;
		}
		if (rum_selected == true && grape_selected == true) {
			wynik_koncowy = wynik_koncowy + 4;
		}
		if (metaxa_selected == true && coconut_selected == true) {
			wynik_koncowy = wynik_koncowy/3;
		}
		if (jager_selected == true && malibu_selected == true) {
			wynik_koncowy = wynik_koncowy / 3;
		}
		if (bombay_selected == true && curacao_selected == true && sprite_selected) {
			wynik_koncowy = wynik_koncowy +12;
		}
		if (vodka_selected == true && curacao_selected == true && sprite_selected) {
			wynik_koncowy = wynik_koncowy + 6;
		}
		if (aperol_selected == true && orange_selected == true) {
			wynik_koncowy = wynik_koncowy + 9;
		}
		if (aperol_selected == true && pinapple_selected == true) {
			wynik_koncowy = wynik_koncowy / 2;
		}
		if (aperol_selected == true && coconut_selected == true) {
			wynik_koncowy = wynik_koncowy / 2;
		}
		if (tequila_selected == true && orange_selected == true) {
			wynik_koncowy = wynik_koncowy + 8;
		}
		if (tequila_selected == true && orange_selected == true && sprite_selected) {
			wynik_koncowy = wynik_koncowy + 17;
		}
		if (tequila_selected == true && coconut_selected == true && cola_selected) {
			wynik_koncowy = wynik_koncowy /4;
		}
		if (tequila_selected == true && coconut_selected == true && grape_selected) {
			wynik_koncowy = wynik_koncowy / 4;
		}
		if (vodka_selected == true && kahlua_selected == true && orange_selected) {
			wynik_koncowy = wynik_koncowy + 21;
		}
		if (cointreau_selected == true && grenadine_selected == true && sprite_selected) {
			wynik_koncowy = wynik_koncowy + 24;
		}
		if (cointreau_selected == true && orange_selected == true) {
			wynik_koncowy = wynik_koncowy + 8;
		}
		if (cointreau_selected == true && coconut_selected == true) {
			wynik_koncowy = wynik_koncowy /2;
		}
		if (cointreau_selected == true && kahlua_selected == true) {
			wynik_koncowy = wynik_koncowy / 2;
		}
		if (cointreau_selected == true && pinapple_selected == true) {
			wynik_koncowy = wynik_koncowy / 2;
		}
		if (coconut_selected == true && orange_selected == true) {
			wynik_koncowy = wynik_koncowy + 10;
		}
		if (rum_selected == true && sprite_selected == true) {
			wynik_koncowy = wynik_koncowy + 10;
		}
		if (wynik_koncowy < 0) {
			wynik_koncowy = 0;
		}
		if (wynik_koncowy < 10) {
			rscore->w = 20;
		}
		else if (wynik_koncowy < 100) {
			rscore->w = 30;
			rscore->x = SCREEN_WIDTH / 2 - 20;
		}
		else {
			rscore->w = 60;
			rscore->x = SCREEN_WIDTH / 2 - 30;
		}

		char Buffer[256];
		sprintf(Buffer, "%i", wynik_koncowy);
		SDL_Surface* Score = TTF_RenderText_Solid(vcr, Buffer, Black);
		SDL_Texture* Score_Texture = SDL_CreateTextureFromSurface(renderer, Score);

		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, game_panel, NULL, NULL);
		if (display == true) {
			empty->checkSelected(mouse);
			empty->draw3();
			empty2->checkSelected(mouse);
			empty2->draw3();
			empty3->checkSelected(mouse);
			empty3->draw3();
			clear->checkSelected(mouse);
			clear->draw3();
			amount->checkSelected(mouse);
			amount->draw3();
		}
		if (amountSelected == true) {
			SDL_RenderCopy(renderer, ray, NULL, rray);
			SDL_RenderCopy(renderer, ray2, NULL, rray2);
			SDL_RenderCopy(renderer, ray3, NULL, rray3);
			SDL_RenderCopy(renderer, switcher, NULL, rswitcher);
			SDL_RenderCopy(renderer, switcher2, NULL, rswitcher2);
			SDL_RenderCopy(renderer, switcher3, NULL, rswitcher3);
			SDL_RenderCopy(renderer, switcher3, NULL, rswitcher3);
		}

		if (alcoholSelected == true) {
			drinks[VODKA]->checkSelected(mouse);
			drinks[VODKA]->draw3();
			drinks[WHITE_RUM]->checkSelected(mouse);
			drinks[WHITE_RUM]->draw3();
			drinks[COINTREAU]->checkSelected(mouse);
			drinks[COINTREAU]->draw3();
			drinks[JAGERMEISTER]->checkSelected(mouse);
			drinks[JAGERMEISTER]->draw3();
			drinks[ABSINTH]->checkSelected(mouse);
			drinks[ABSINTH]->draw3();
			drinks[JACK_DANIELS]->checkSelected(mouse);
			drinks[JACK_DANIELS]->draw3();
			drinks[TEQUILA]->checkSelected(mouse);
			drinks[TEQUILA]->draw3();
			drinks[METAXA]->checkSelected(mouse);
			drinks[METAXA]->draw3();
			drinks[APEROL]->checkSelected(mouse);
			drinks[APEROL]->draw3();
			drinks[GINEBRA]->checkSelected(mouse);
			drinks[GINEBRA]->draw3();
			drinks[BOMBAY]->checkSelected(mouse);
			drinks[BOMBAY]->draw3();
		}
		if (liqueurSelected == true) {
			drinks[BLUE_CURACAO]->checkSelected(mouse);
			drinks[BLUE_CURACAO]->draw3();
			drinks[KAHLUA]->checkSelected(mouse);
			drinks[KAHLUA]->draw3();
			drinks[GRENADINE]->checkSelected(mouse);
			drinks[GRENADINE]->draw3();
			drinks[COCONUT]->checkSelected(mouse);
			drinks[COCONUT]->draw3();
			drinks[MALIBU]->checkSelected(mouse);
			drinks[MALIBU]->draw3();
		}
		if (juiceSelected == true) {

			drinks[ORANGE]->checkSelected(mouse);
			drinks[ORANGE]->draw3();
			drinks[GRAPE]->checkSelected(mouse);
			drinks[GRAPE]->draw3();
			drinks[PINAPPLE]->checkSelected(mouse);
			drinks[PINAPPLE]->draw3();
			drinks[COLA]->checkSelected(mouse);
			drinks[COLA]->draw3();
			drinks[SPRITE]->checkSelected(mouse);
			drinks[SPRITE]->draw3();
		}
		serve->checkSelected(mouse);
		serve->draw3();
		if (serveSelected == true) {

			SDL_RenderCopy(renderer, logo, NULL, NULL);
			SDL_RenderCopy(renderer, scoreboard, NULL, rscoreboard);
			SDL_RenderCopy(renderer, Score_Texture, NULL, rscore);
			empty->sRect.y = 966;
			empty2->sRect.y = 966;
			empty3->sRect.y = 966;
			rswitcher->x = 442;
			rswitcher2->x = 442;
			rswitcher3->x = 442;
		}
		
		mouse->draw();
		menuButton->checkSelected(mouse);
		menuButton->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}



Mojito::Mojito()
{
	mojito = IMG_LoadTexture(renderer, "mojito.png");
}
Mojito::~Mojito()
{
	SDL_DestroyTexture(mojito);
	delete menuButton;
}
void Mojito::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, mojito, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}

Cuba_Libre::Cuba_Libre()
{
	cuba_libre = IMG_LoadTexture(renderer, "cuba_libre.png");
}
Cuba_Libre::~Cuba_Libre()
{
	SDL_DestroyTexture(cuba_libre);
	delete menuButton;
}
void Cuba_Libre::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, cuba_libre, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}

Sex_On_The_Beach::Sex_On_The_Beach()
{
	sex_on_the_beach = IMG_LoadTexture(renderer, "sex_on_the_beach.png");
}
Sex_On_The_Beach::~Sex_On_The_Beach()
{
	SDL_DestroyTexture(sex_on_the_beach);
	delete menuButton;
}
void Sex_On_The_Beach::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, sex_on_the_beach, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}

Blue_Lagoon::Blue_Lagoon()
{
	blue_lagoon = IMG_LoadTexture(renderer, "blue_lagoon.png");
}
Blue_Lagoon::~Blue_Lagoon()
{
	SDL_DestroyTexture(blue_lagoon);
	delete menuButton;
}
void Blue_Lagoon::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, blue_lagoon, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}

Aura_In_Me::Aura_In_Me()
{
	aura_in_me = IMG_LoadTexture(renderer, "aura_in_me.png");
}
Aura_In_Me::~Aura_In_Me()
{
	SDL_DestroyTexture(aura_in_me);
	delete menuButton;
}
void Aura_In_Me::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, aura_in_me, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}

Black_Russian::Black_Russian()
{
	black_russian = IMG_LoadTexture(renderer, "black_russian.png");
}
Black_Russian::~Black_Russian()
{
	SDL_DestroyTexture(black_russian);
	delete menuButton;
}
void Black_Russian::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, black_russian, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}
Bazooka_Joe::Bazooka_Joe()
{
	bazooka_joe = IMG_LoadTexture(renderer, "bazooka_joe.png");
}
Bazooka_Joe::~Bazooka_Joe()
{
	SDL_DestroyTexture(bazooka_joe);
	delete menuButton;
}
void Bazooka_Joe::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, bazooka_joe, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}
Bed_Of_Roses::Bed_Of_Roses()
{
	bed_of_roses = IMG_LoadTexture(renderer, "bed_of_roses.png");
}
Bed_Of_Roses::~Bed_Of_Roses()
{
	SDL_DestroyTexture(bed_of_roses);
	delete menuButton;
}
void Bed_Of_Roses::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, bed_of_roses, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}
Cosmopolitan::Cosmopolitan()
{
	cosmopolitan = IMG_LoadTexture(renderer, "cosmopolitan.png");
}
Cosmopolitan::~Cosmopolitan()
{
	SDL_DestroyTexture(cosmopolitan);
	delete menuButton;
}
void Cosmopolitan::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, cosmopolitan, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}
Daiquiri::Daiquiri()
{
	daiquiri = IMG_LoadTexture(renderer, "daiquiri.png");
}
Daiquiri::~Daiquiri()
{
	SDL_DestroyTexture(daiquiri);
	delete menuButton;
}
void Daiquiri::update() {
	bool running = true;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (menuButton->selected) {
						current = options;
						running = false;
						break;
					}
				}

			}
		}
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
		SDL_RenderCopy(renderer, daiquiri, NULL, NULL);
		menuButton->checkSelected(mouse);
		menuButton->draw();
		mouse->draw();
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

}






static int n = SDL_Init(SDL_INIT_EVERYTHING);
static int m = TTF_Init();
SDL_Window* window = SDL_CreateWindow("DrinkOn", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
State* menu = new Menu;
State* options = new Options;
State* alcohol_list = new Alcohol_List;
State* the_game = new The_Game;
State* smojito = new Mojito;
State* current = menu;
State* scuba_libre = new Cuba_Libre;
State* ssex_on_the_beach = new Sex_On_The_Beach;
State* sblue_lagoon = new Blue_Lagoon;
State* saura_in_me = new Aura_In_Me;
State* sblack_russian = new Black_Russian;
State* sbazooka_joe = new Bazooka_Joe;
State* sbed_of_roses = new Bed_Of_Roses;
State* scosmopolitan = new Cosmopolitan;
State* sdaiquiri = new Daiquiri;

