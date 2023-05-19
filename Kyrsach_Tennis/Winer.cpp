#include"Win_game.h"

void draw_left(SDL_Renderer*& renderer, SDL_Texture* texture)
{
    SDL_Rect rect = { 605,460, 50, 70 };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void draw_right(SDL_Renderer*& renderer, SDL_Texture* texture)
{
    SDL_Rect rect = { 700,460, 50, 70 };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Texture* get_left_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font)
{
    SDL_Surface* textSurface = NULL;
    SDL_Color fore_color = { 0,0,0 };
    SDL_Color back_color = { 245,245,220 };
    textSurface = TTF_RenderText_Shaded(font, text, fore_color, back_color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
}

SDL_Texture* get_right_texture(SDL_Renderer*& renderer, char* text2, TTF_Font* font)
{
    SDL_Surface* textSurface = NULL;
    SDL_Color fore_color = { 0,0,0 };
    SDL_Color back_color = { 245,245,220 };
    textSurface = TTF_RenderText_Shaded(font, text2, fore_color, back_color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
}

void winer(SDL_Renderer*& renderer, bool& p, int win_right, int win_left, int left, int right)
{
    SDL_Event event;

    SDL_Rect win_play = { 315, 120, 600, 600 };
    SDL_Surface* Win_play_left1 = IMG_Load("Win_play_left.bmp");
    SDL_SetColorKey(Win_play_left1, SDL_TRUE, SDL_MapRGB(Win_play_left1->format, 255, 255, 255));
    SDL_Texture* Win_play_left_texture = SDL_CreateTextureFromSurface(renderer, Win_play_left1);
    SDL_FreeSurface(Win_play_left1);

    SDL_Surface* Win_play_right1 = IMG_Load("Win_play_right.bmp");
    SDL_SetColorKey(Win_play_right1, SDL_TRUE, SDL_MapRGB(Win_play_right1->format, 255, 255, 255));
    SDL_Texture* Win_play_right_texture = SDL_CreateTextureFromSurface(renderer, Win_play_right1);
    SDL_FreeSurface(Win_play_right1);

    TTF_Init();
    TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
    SDL_Texture* textTexture;
    SDL_Texture* textTexture2;
    char text[10];
    char text2[10];
    textTexture = get_left_texture(renderer, text, my_font);
    textTexture2 = get_right_texture(renderer, text2, my_font);

    _itoa_s(left, text, 10);
    textTexture = get_left_texture(renderer, text, my_font);

    _itoa_s(right, text2, 10);
    textTexture2 = get_right_texture(renderer, text2, my_font);

    int x = 0, y = 0;
    bool p1 = false;
    while (!p1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) p1 = true;
        if (win_right>win_left) SDL_RenderCopy(renderer, Win_play_right_texture, NULL, &win_play);
        if (win_left>win_right) SDL_RenderCopy(renderer, Win_play_left_texture, NULL, &win_play);
        SDL_GetMouseState(&x, &y);

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (x > 415 && x < 515 && y>560 && y < 660) p1 = true;
            if (x > 595 && x < 830 && y>560 && y < 660)
            {
                p1 = true;
                p = true;
            }
        }
        
        draw_left(renderer, textTexture);
        draw_right(renderer, textTexture2);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p1 == true)
    {
        SDL_DestroyTexture(textTexture2);
        SDL_DestroyTexture(textTexture);
        SDL_DestroyTexture(Win_play_right_texture);
        SDL_DestroyTexture(Win_play_left_texture);
    }
}