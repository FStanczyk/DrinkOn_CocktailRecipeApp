#pragma once
#include<iostream>
#include<string>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <sstream>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* logo;
extern SDL_Texture* drinksOptions;
extern SDL_Texture* alcohols_txt;
extern SDL_Texture* displayTexture;
class State;
extern State* the_game;
extern State* options;
extern State* menu;
extern State* current;
extern State* alcohol_list;
extern State* smojito;
extern State* scuba_libre;
extern State* ssex_on_the_beach;
extern State* sblue_lagoon;
extern State* saura_in_me;
extern State* sblack_russian;
extern State* sbazooka_joe;
extern State* sbed_of_roses;
extern State* scosmopolitan;
extern State* sdaiquiri;
extern State* scurrent;
