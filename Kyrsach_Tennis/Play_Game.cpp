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

    SDL_Surface* Rocket1 = IMG_Load("Rocket.bmp");
    SDL_Texture* Rocket = SDL_CreateTextureFromSurface(renderer, Rocket1);
    SDL_FreeSurface(Rocket1);

    SDL_Rect Rocket_place = { 198,370, 10,80 };
    SDL_Rect Rocket_place2 = { 992,370, 10,80 };
    int x = 0, y = 0;
    int x3, y3, x1 = 600, y1 = 412, x2 = 8, y2 = 8;
    double f;
    bool p = false;
    while (!p)
    {
        SDL_PollEvent(&event);
        SDL_RenderCopy(renderer, Play_fon, NULL, NULL);
        SDL_RenderCopy(renderer, Blue_table, NULL, &table);
        SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place);
        SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place2);
        SDL_GetMouseState(&x, &y);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        x1 += x2;
        y1 += y2;
        if ((x1 + 10 > Rocket_place2.x) || (x1 - 10 < Rocket_place.x)) {
            x2 = -x2;
        }
        if ((y1 + 10 > 624) || (y1 - 10 < 200)) {
            y2 = -y2;
        }
        for (int R = 10; R >= 0; R--) {
            for (int i = 0; i <= 1350; i++) {
                f = i * (3.14 / 180);
                x3 = int(x1 + cos(f) * R);
                y3 = int(-(-y1 + sin(f) * R));
                SDL_RenderDrawPoint(renderer, x3, y3);
            }
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_w) && Rocket_place.y>=205)
        {
            Rocket_place.y -= 12;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_s) && Rocket_place.y <= 535)
        {
            Rocket_place.y += 12;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP) && Rocket_place2.y >= 205)
        {
            Rocket_place2.y -= 12;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place2);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN) && Rocket_place2.y <= 535)
        {
            Rocket_place2.y += 12;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place2);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
        {
            menu_pause(renderer, p);
        }
        
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p == true)
    {
        SDL_DestroyTexture(Rocket);
        SDL_DestroyTexture(Blue_table);
        SDL_DestroyTexture(Play_fon);
    }
}