#include<stdlib.h>
#include<stdio.h>
#include"SDL.h"
#include"SDL_ttf.h"
#include"SDL_image.h"
#include"SDL_mixer.h"
#include"Play.h"
#include"Options.h"
#include<Windows.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
SDL_Window* window = NULL;
Mix_Chunk* Sound = NULL;
Mix_Music* fon = NULL;
bool init();

void loadmusic()
{
    fon = Mix_LoadMUS("Menu.mp3");
    Mix_PlayMusic(fon, -1);
}

void sound()
{
    Sound = Mix_LoadWAV("sonic_jump.mp3");
    Mix_PlayChannel(-1, Sound, 0);
}

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO < 0))
    {
        printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        window = SDL_CreateWindow(u8"Теннис", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
    }
    return success;
}

int main(int argc, char* args[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Mix_Init(0);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

    if (!(init()))
    {
        printf("Ошибка инициализации окна\n");
    }
    else
    {
        loadmusic();
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);

        SDL_Surface* Menu_fon1 = IMG_Load("Menu_fon.jpg");
        SDL_Texture* Menu_fon = SDL_CreateTextureFromSurface(renderer, Menu_fon1);
        SDL_FreeSurface(Menu_fon1);

        SDL_Surface* Start1 = IMG_Load("Start.bmp");
        SDL_Texture* Start = SDL_CreateTextureFromSurface(renderer, Start1);
        SDL_FreeSurface(Start1);

        SDL_Surface* Start_1 = IMG_Load("Start2.bmp");
        SDL_Texture* Start2 = SDL_CreateTextureFromSurface(renderer, Start_1);
        SDL_FreeSurface(Start_1);

        SDL_Surface* Settings1 = IMG_Load("Settings.bmp");
        SDL_Texture* Settings = SDL_CreateTextureFromSurface(renderer, Settings1);
        SDL_FreeSurface(Settings1);

        SDL_Surface* Settings_1 = IMG_Load("Settings2.bmp");
        SDL_Texture* Settings2 = SDL_CreateTextureFromSurface(renderer, Settings_1);
        SDL_FreeSurface(Settings_1);

        SDL_Surface* Records1 = IMG_Load("Records.bmp");
        SDL_Texture* Records = SDL_CreateTextureFromSurface(renderer, Records1);
        SDL_FreeSurface(Records1);

        SDL_Surface* Records_1 = IMG_Load("Records2.bmp");
        SDL_Texture* Records2 = SDL_CreateTextureFromSurface(renderer, Records_1);
        SDL_FreeSurface(Records_1);

        SDL_Surface* Back1 = IMG_Load("Back.bmp");
        SDL_Texture* Back = SDL_CreateTextureFromSurface(renderer, Back1);
        SDL_FreeSurface(Back1);

        SDL_Surface* Back_1 = IMG_Load("Back2.bmp");
        SDL_Texture* Back2 = SDL_CreateTextureFromSurface(renderer, Back_1);
        SDL_FreeSurface(Back_1);

        SDL_Rect Ball_k = { 533, 25, 95, 95 };
        SDL_Surface* Ball1 = IMG_Load("Ball.png");
        SDL_Texture* Ball = SDL_CreateTextureFromSurface(renderer, Ball1);
        SDL_FreeSurface(Ball1);

        SDL_Rect knopka[4];
        knopka[0] = { 470,250, 300, 115 };
        knopka[1] = { 470,380, 300, 115 };
        knopka[2] = { 470,510, 300, 115 };
        knopka[3] = { 470,640, 300, 115 };
        
        SDL_Event event;
        bool quit = false;
        int x = 0, y = 0, table=1, zvyk=1, j=0;
        while (!quit)
        {
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT) quit = true;

            SDL_RenderCopy(renderer, Menu_fon, NULL, NULL);
            SDL_RenderCopy(renderer, Start, NULL, &knopka[0]);
            SDL_RenderCopy(renderer, Settings, NULL, &knopka[1]);
            SDL_RenderCopy(renderer, Records, NULL, &knopka[2]);
            SDL_RenderCopy(renderer, Back, NULL, &knopka[3]);
            j += 100;
            SDL_RenderCopyEx(renderer, Ball, NULL, &Ball_k, j * (3.14 / 180), 0, SDL_FLIP_NONE);
            SDL_GetMouseState(&x, &y);
            for (int i = 0; i < 4; i++)
            {
                if ((x > knopka[i].x && x < knopka[i].x + knopka[i].w) && (y > knopka[i].y && y < knopka[i].y + knopka[i].h))
                {
                    if (i == 0) SDL_RenderCopy(renderer, Start2, NULL, &knopka[0]);
                    if (i == 1) SDL_RenderCopy(renderer, Settings2, NULL, &knopka[1]);
                    if (i == 2) SDL_RenderCopy(renderer, Records2, NULL, &knopka[2]);
                    if (i == 3) SDL_RenderCopy(renderer, Back2, NULL, &knopka[3]);
                }
            }

            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if ((event.button.x > knopka[0].x) && (event.button.x < knopka[0].x + knopka[0].w) && (event.button.y > knopka[0].y) && (event.button.y < knopka[0].y + knopka[0].h))
                {
                    play(renderer, table);
                }

                if ((event.button.x > knopka[1].x) && (event.button.x < knopka[1].x + knopka[1].w) && (event.button.y > knopka[1].y) && (event.button.y < knopka[1].y + knopka[1].h))
                {
                    options(renderer, table, zvyk);
                }

                if ((event.button.x > knopka[2].x) && (event.button.x < knopka[2].x + knopka[1].w) && (event.button.y > knopka[2].y) && (event.button.y < knopka[2].y + knopka[2].h))
                {
                    records(renderer, table, zvyk);
                }

                if ((event.button.x > knopka[3].x) && (event.button.x < knopka[3].x + knopka[3].w) && (event.button.y > knopka[3].y) && (event.button.y < knopka[3].y + knopka[3].h))
                {
                    quit = true;
                }

            }
            SDL_RenderPresent(renderer);
            SDL_Delay(16);
        }
        SDL_DestroyTexture(Ball);
        SDL_DestroyTexture(Back2);
        SDL_DestroyTexture(Back);
        SDL_DestroyTexture(Records2);
        SDL_DestroyTexture(Records);
        SDL_DestroyTexture(Settings2);
        SDL_DestroyTexture(Settings);
        SDL_DestroyTexture(Start2);
        SDL_DestroyTexture(Start);
        SDL_DestroyTexture(Menu_fon);
        SDL_DestroyRenderer(renderer);
    }
    Mix_FreeMusic(fon);
    Mix_FreeChunk(Sound);
    Mix_CloseAudio();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}