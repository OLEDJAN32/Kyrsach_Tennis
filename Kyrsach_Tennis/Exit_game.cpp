#include"Exit.h"

void exit(SDL_Renderer*& renderer, bool& quit, int zvyk)
{
    SDL_Event event;

    SDL_Rect exit_koord = { 200, 200, 800, 424 };
    SDL_Surface* Exit1 = IMG_Load("Exit.bmp");
    SDL_SetColorKey(Exit1, SDL_TRUE, SDL_MapRGB(Exit1->format, 255, 255, 255));
    SDL_Texture* Exit = SDL_CreateTextureFromSurface(renderer, Exit1);
    SDL_FreeSurface(Exit1);

    int x = 0, y = 0, n = 0;
    bool p1 = false;
    while (!p1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) p1 = true;
        SDL_RenderCopy(renderer, Exit, NULL, &exit_koord);
        SDL_GetMouseState(&x, &y);
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            n += 1;
        }

        if (n == 2)
        {
            n = 0;
            if (x > 308 && x < 505 && y>444 & y < 535) 
            {
                p1 = true;
                quit = true;
            }
            if (x > 700 && x < 891 && y>444 & y < 535) p1 = true;
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p1 == true)
    {
        SDL_DestroyTexture(Exit);
    }
}