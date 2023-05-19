#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"SDL.h"
#include"SDL_ttf.h"
#include"SDL_image.h"
#include"SDL_mixer.h"

void draw_left(SDL_Renderer*& renderer, SDL_Texture* texture);
void draw_right(SDL_Renderer*& renderer, SDL_Texture* texture);
SDL_Texture* get_left_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font);
SDL_Texture* get_right_texture(SDL_Renderer*& renderer, char* text2, TTF_Font* font);
void winer(SDL_Renderer*& renderer, bool& p, int win_right, int win_left, int left, int right, bool& v, int zvyk);