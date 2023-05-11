#include"Options.h"

void options(SDL_Renderer*& renderer, int& table, int& zvyk)
{
    SDL_Event event;

    SDL_Rect option = { 315, 120, 600, 600 };
    SDL_Surface* option1 = IMG_Load("Options.bmp");
    SDL_Texture* Menu_options = SDL_CreateTextureFromSurface(renderer, option1);
    SDL_FreeSurface(option1);

    SDL_Surface* OK1 = IMG_Load("OK.bmp");
    SDL_Texture* OK = SDL_CreateTextureFromSurface(renderer, OK1);
    SDL_FreeSurface(OK1);

    SDL_Rect ok_koord1 = { 415,658,34,34 };
    SDL_Rect ok_koord2 = { 595,658,34,34 };
    SDL_Rect ok_koord3 = { 774,657,34,34 };
    int x = 0, y = 0;
    bool p1 = false, ok1=false, ok2=false, ok3=false;
    while (!p1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) p1 = true;
        SDL_RenderCopy(renderer, Menu_options, NULL, &option);
        if (ok1 == true || table == 1) SDL_RenderCopy(renderer, OK, NULL, &ok_koord1);
        if (ok2 == true || table == 2) SDL_RenderCopy(renderer, OK, NULL, &ok_koord2);
        if (ok3 == true || table == 3) SDL_RenderCopy(renderer, OK, NULL, &ok_koord3);
        SDL_GetMouseState(&x, &y);

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (x > 860 && x < 910 && y>120 && y < 170) p1 = true;
            if ((x > 410 && x < 450 && y>655 && y < 690) || table == 1)
            {
                ok1 = true;
                ok2 = false;
                ok3 = false;
                table = 1;
            }
            if ((x > 590 && x < 630 && y>655 && y < 690) || table == 2)
            {
                ok2 = true;
                ok1 = false;
                ok3 = false;
                table = 2;
            }
            if ((x > 770 && x < 810 && y>655 && y < 690) || table == 3)
            {
                ok3 = true;
                ok1 = false;
                ok2 = false;
                table = 3;
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p1 == true)
    {
        SDL_DestroyTexture(OK);
        SDL_DestroyTexture(Menu_options);
    }
}