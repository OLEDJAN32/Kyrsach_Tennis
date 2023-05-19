#include"Pause.h"

void menu_pause(SDL_Renderer*& renderer, bool& p, bool& quit)
{
    SDL_Event event;

    SDL_Rect pause = { 200, 200, 800, 424 };
    SDL_Surface* Menu_pause1 = IMG_Load("Menu_pause.bmp");
    SDL_SetColorKey(Menu_pause1, SDL_TRUE, SDL_MapRGB(Menu_pause1->format, 255, 255, 255));
    SDL_Texture* Menu_pause = SDL_CreateTextureFromSurface(renderer, Menu_pause1);
    SDL_FreeSurface(Menu_pause1);

    SDL_Surface* Menu_pause2 = IMG_Load("Menu_pause_1.bmp");
    SDL_SetColorKey(Menu_pause2, SDL_TRUE, SDL_MapRGB(Menu_pause2->format, 255, 255, 255));
    SDL_Texture* Menu_pause_1 = SDL_CreateTextureFromSurface(renderer, Menu_pause2);
    SDL_FreeSurface(Menu_pause2);

    SDL_Surface* Menu_pause3 = IMG_Load("Menu_pause_2.bmp");
    SDL_SetColorKey(Menu_pause3, SDL_TRUE, SDL_MapRGB(Menu_pause3->format, 255, 255, 255));
    SDL_Texture* Menu_pause_2 = SDL_CreateTextureFromSurface(renderer, Menu_pause3);
    SDL_FreeSurface(Menu_pause3);

    SDL_Surface* fon1 = IMG_Load("Fon.bmp");
    SDL_SetColorKey(fon1, SDL_TRUE, SDL_MapRGB(fon1->format, 254, 255, 255));
    SDL_Texture* Fon = SDL_CreateTextureFromSurface(renderer, fon1);
    SDL_FreeSurface(fon1);
    
    int x = 0, y = 0, n=0;
    bool p1 = false;
    while (!p1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) { quit = true; p1 = true; }
        SDL_SetTextureAlphaMod(Fon, 1);
        SDL_RenderCopy(renderer, Fon, NULL, NULL);
        SDL_RenderCopy(renderer, Menu_pause, NULL, &pause);
        SDL_GetMouseState(&x, &y);

        if (x > 465 && x < 740 && y>345 && y < 425) SDL_RenderCopy(renderer, Menu_pause_1, NULL, &pause);
        if (x > 465 && x < 740 && y>455 && y < 570) SDL_RenderCopy(renderer, Menu_pause_2, NULL, &pause);

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            n += 1;
        }
        if (n == 2)
        {
            n = 0;
            if (x > 465 && x < 740 && y>345 && y < 425) p1 = true;
            if (x > 465 && x < 740 && y>455 && y < 570)
            {
                p1 = true;
                p = true;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p1 == true)
    {
        SDL_DestroyTexture(Fon);
        SDL_DestroyTexture(Menu_pause_2);
        SDL_DestroyTexture(Menu_pause_1);
        SDL_DestroyTexture(Menu_pause);
    }
}