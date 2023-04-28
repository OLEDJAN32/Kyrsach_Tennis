#include<stdlib.h>
#include<stdio.h>
#include"SDL.h"
#include"SDL_ttf.h"
#include"SDL_image.h"
#include"SDL_mixer.h"
#include<Windows.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
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
        SDL_Event event;
        bool quit = false;
        while (!quit)
        {
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT) quit = true;

            SDL_RenderCopy(renderer, Menu_fon, NULL, NULL);

            SDL_RenderPresent(renderer);
        }
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