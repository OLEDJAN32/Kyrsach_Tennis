#include"Play.h"
#include"Pause.h"

void play(SDL_Renderer*& renderer)
{
    SDL_Event event;
    SDL_Surface* Play_fon1 = IMG_Load("Play_fon.jpg");
    SDL_Texture* Play_fon = SDL_CreateTextureFromSurface(renderer, Play_fon1);
    SDL_FreeSurface(Play_fon1);

    SDL_Rect table = { 200, 200, 800, 424 };
    SDL_Surface* Blue_table1 = IMG_Load("Blue_table.jpg");
    SDL_Texture* Blue_table = SDL_CreateTextureFromSurface(renderer, Blue_table1);
    SDL_FreeSurface(Blue_table1);

    int x = 0, y = 0;
    bool p = false;
    while (!p)
    {
        SDL_PollEvent(&event);
        SDL_RenderCopy(renderer, Play_fon, NULL, NULL);
        SDL_RenderCopy(renderer, Blue_table, NULL, &table);
        SDL_GetMouseState(&x, &y);

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
        {
            menu_pause(renderer, p);
        }
        
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p == true)
    {
        SDL_DestroyTexture(Blue_table);
        SDL_DestroyTexture(Play_fon);
    }
}