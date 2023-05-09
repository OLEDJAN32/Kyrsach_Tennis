#include"Pause.h"

void menu_pause(SDL_Renderer*& renderer, bool& p)
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

    int x = 0, y = 0;
    bool p1 = false;
    while (!p1)
    {
        SDL_PollEvent(&event);
        SDL_RenderCopy(renderer, Menu_pause, NULL, &pause);
        SDL_GetMouseState(&x, &y);

        if (x > 465 && x < 740 && y>345 && y < 425) SDL_RenderCopy(renderer, Menu_pause_1, NULL, &pause);
        if (x > 465 && x < 740 && y>455 && y < 570) SDL_RenderCopy(renderer, Menu_pause_2, NULL, &pause);

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (x > 465 && x < 740 && y>345 && y < 425) p1=true;
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
        SDL_DestroyTexture(Menu_pause_2);
        SDL_DestroyTexture(Menu_pause_1);
        SDL_DestroyTexture(Menu_pause);
    }
}