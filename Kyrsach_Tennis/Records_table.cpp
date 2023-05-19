#include"Records.h"

void draw_left(SDL_Renderer*& renderer, SDL_Texture* texture, SDL_Texture* texture2, SDL_Texture* texture3, SDL_Texture* texture4, SDL_Texture* texture5)
{
    SDL_Rect rect1 = { 625,308, 40, 60 };
    SDL_RenderCopy(renderer, texture, NULL, &rect1);
    SDL_Rect rect2 = { 625,383, 40, 60 };
    SDL_RenderCopy(renderer, texture2, NULL, &rect2);
    SDL_Rect rect3 = { 625,457, 40, 60 };
    SDL_RenderCopy(renderer, texture3, NULL, &rect3);
    SDL_Rect rect4 = { 625,533, 40, 60 };
    SDL_RenderCopy(renderer, texture4, NULL, &rect4);
    SDL_Rect rect5 = { 625,608, 40, 60 };
    SDL_RenderCopy(renderer, texture5, NULL, &rect5);
}

SDL_Texture* get_record_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font)
{
    SDL_Surface* textSurface = NULL;
    SDL_Color fore_color = { 0,0,0 };
    SDL_Color back_color = { 245,245,220 };
    textSurface = TTF_RenderText_Shaded(font, text, fore_color, back_color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
}

void records(SDL_Renderer*& renderer, bool& quit)
{
    SDL_Event event;

    SDL_Rect record = { 315, 120, 600, 600 };
    SDL_Surface* Records_table1 = IMG_Load("Records_table.bmp");
    SDL_SetColorKey(Records_table1, SDL_TRUE, SDL_MapRGB(Records_table1->format, 255, 255, 255));
    SDL_Texture* Records_table = SDL_CreateTextureFromSurface(renderer, Records_table1);
    SDL_FreeSurface(Records_table1);

    int a[5], size = 0;
    FILE* f = fopen("Records.txt", "rt");
    while (!feof(f))
    {
        fscanf(f, "%d", &a[size]);
        size++;
    }
    fclose(f);

    TTF_Init();
    TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
    SDL_Texture* textTexture;
    SDL_Texture* textTexture2;
    SDL_Texture* textTexture3;
    SDL_Texture* textTexture4;
    SDL_Texture* textTexture5;

    char text[10];
    char text2[10];
    char text3[10];
    char text4[10];
    char text5[10];
    textTexture = get_record_texture(renderer, text, my_font);
    textTexture2 = get_record_texture(renderer, text2, my_font);
    textTexture3 = get_record_texture(renderer, text3, my_font);
    textTexture4 = get_record_texture(renderer, text4, my_font);
    textTexture5 = get_record_texture(renderer, text5, my_font);

    _itoa_s(a[0], text, 10);
    textTexture = get_record_texture(renderer, text, my_font);

    _itoa_s(a[1], text2, 10);
    textTexture2 = get_record_texture(renderer, text2, my_font);

    _itoa_s(a[2], text3, 10);
    textTexture3 = get_record_texture(renderer, text3, my_font);

    _itoa_s(a[3], text4, 10);
    textTexture4 = get_record_texture(renderer, text4, my_font);

    _itoa_s(a[4], text5, 10);
    textTexture5 = get_record_texture(renderer, text5, my_font);

    int x = 0, y = 0;
    bool p1 = false;
    while (!p1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) { quit = true; p1 = true; }
        SDL_RenderCopy(renderer, Records_table, NULL, &record);
        SDL_GetMouseState(&x, &y);

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (x > 860 && x < 910 && y>120 && y < 170) p1 = true;
        }

        draw_left(renderer, textTexture, textTexture2, textTexture3, textTexture4, textTexture5);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p1 == true)
    {
        SDL_DestroyTexture(textTexture5);
        SDL_DestroyTexture(textTexture4);
        SDL_DestroyTexture(textTexture3);
        SDL_DestroyTexture(textTexture2);
        SDL_DestroyTexture(textTexture);
        SDL_DestroyTexture(Records_table);
    }
}