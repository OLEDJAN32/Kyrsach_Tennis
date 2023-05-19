#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<ctime>
#include"SDL.h"
#include"SDL_ttf.h"
#include"SDL_image.h"
#include"SDL_mixer.h"

int napr();
void proverka(int razn);
void draw_text(SDL_Renderer*& renderer, SDL_Texture* texture);
void draw_text2(SDL_Renderer*& renderer, SDL_Texture* texture);
SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font);
SDL_Texture* get_text_texture2(SDL_Renderer*& renderer, char* text2, TTF_Font* font);
void play(SDL_Renderer*& renderer, int table, int zvyk, bool& quit);