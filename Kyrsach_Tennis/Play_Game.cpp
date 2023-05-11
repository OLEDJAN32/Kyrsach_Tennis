#include"Play.h"
#include"Pause.h"

int napr()
{
    int x=rand()%(6-(-6)+1)+(-6);
    if (x == 6 || x == (-6)) { return x; }
    else { napr(); }
}

void draw_text(SDL_Renderer*& renderer, SDL_Texture* texture)
{
    SDL_Rect rect = { 546,53, 40, 80 };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void draw_text2(SDL_Renderer*& renderer, SDL_Texture* texture)
{
    SDL_Rect rect = { 614,53, 40, 80 };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font)
{
    SDL_Surface* textSurface = NULL;
    SDL_Color fore_color = { 255,0,0 };
    SDL_Color back_color = { 0,0,0};
    textSurface = TTF_RenderText_Shaded(font, text, fore_color, back_color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
}

SDL_Texture* get_text_texture2(SDL_Renderer*& renderer, char* text2, TTF_Font* font)
{
    SDL_Surface* textSurface = NULL;
    SDL_Color fore_color = { 255,0,0 };
    SDL_Color back_color = { 0,0,0 };
    textSurface = TTF_RenderText_Shaded(font, text2, fore_color, back_color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
}

void play(SDL_Renderer*& renderer, int table)
{
    srand(time(NULL));
    SDL_Event event;
    SDL_Surface* Play_fon1 = IMG_Load("Play_fon.jpg");
    SDL_Texture* Play_fon = SDL_CreateTextureFromSurface(renderer, Play_fon1);
    SDL_FreeSurface(Play_fon1);

    SDL_Rect tablo = { 525,20,150,150 };
    SDL_Surface* Tablo1 = IMG_Load("Tablo.bmp");
    SDL_SetColorKey(Tablo1, SDL_TRUE, SDL_MapRGB(Tablo1->format, 255, 0, 0));
    SDL_Texture* Tablo = SDL_CreateTextureFromSurface(renderer, Tablo1);
    SDL_FreeSurface(Tablo1);

    SDL_Rect table_koord = { 200, 200, 800, 424 };
    SDL_Surface* Blue_table1 = IMG_Load("Blue_table.jpg");
    SDL_Texture* Blue_table = SDL_CreateTextureFromSurface(renderer, Blue_table1);
    SDL_FreeSurface(Blue_table1);

    SDL_Surface* Green_table1 = IMG_Load("Green_table.bmp");
    SDL_Texture* Green_table = SDL_CreateTextureFromSurface(renderer, Green_table1);
    SDL_FreeSurface(Green_table1);

    SDL_Surface* BGTU_table1 = IMG_Load("BGTU_table.jpg");
    SDL_Texture* BGTU_table = SDL_CreateTextureFromSurface(renderer, BGTU_table1);
    SDL_FreeSurface(BGTU_table1);

    SDL_Surface* Rocket1 = IMG_Load("Rocket.bmp");
    SDL_Texture* Rocket = SDL_CreateTextureFromSurface(renderer, Rocket1);
    SDL_FreeSurface(Rocket1);

    TTF_Init();
    TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
    SDL_Texture* textTexture;
    SDL_Texture* textTexture2;

    int tl = 0;
    int tr = 0;
    char text[10];
    char text2[10];
    textTexture = get_text_texture(renderer, text, my_font);
    textTexture2 = get_text_texture2(renderer, text2, my_font);

    SDL_Rect Rocket_place = { 198,370, 10,80 };
    SDL_Rect Rocket_place2 = { 992,370, 10,80 };
    int x = 0, y = 0;
    int x3, y3, x1 = 600, y1 = 412, win_round_left=0, win_round_right=0;
    int x2 = napr();
    int y2 = napr();
    double f;
    bool p = false;
    while (!p)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) p = true;
        SDL_RenderCopy(renderer, Play_fon, NULL, NULL);
        SDL_RenderCopy(renderer, Tablo, NULL, &tablo);
        SDL_RenderCopy(renderer, Blue_table, NULL, &table_koord);
        /*if (table == 1) SDL_RenderCopy(renderer, Blue_table, NULL, &table_koord);
        if (table == 2) SDL_RenderCopy(renderer, Green_table, NULL, &table_koord);
        if (table == 3) SDL_RenderCopy(renderer, BGTU_table, NULL, &table_koord);*/
        SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place);
        SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place2);
        SDL_GetMouseState(&x, &y);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        x1 += x2;
        y1 += y2;
        if ((x1 - 20 < Rocket_place.x) && ((y1 < Rocket_place.y+Rocket_place.h+9) && (y1>Rocket_place.y-9)) && (x1>Rocket_place.x+15))
        {
            x2 = -x2;
        }
        if ((x1 + 10 > Rocket_place2.x) && ((y1 < Rocket_place2.y + Rocket_place2.h+9) && (y1 > Rocket_place2.y-9)) && (x1 < Rocket_place2.x-5))
        {
            x2 = -x2;
        }
        if (x1<Rocket_place.x-20)
        {
            x2 = 0; y2 = 0;
            SDL_Delay(1000);
            win_round_right += 1;
            x1 = 600;
            y1 = 412;
            x2 = napr();
            y2 = napr();
        }
        if (x1 > Rocket_place2.x+20)
        {
            x2 = 0; y2 = 0;
            SDL_Delay(1000);
            win_round_left += 1;
            x1 = 600;
            y1 = 412;
            x2 = napr();
            y2 = napr();
        }
        if ((y1 + 10 > 624) || (y1 - 10 < 200)) 
        {
            y2 = -y2;
        }
        for (int R = 10; R >= 0; R--) 
        {
            for (int i = 0; i <= 1350; i++) 
            {
                f = i * (3.14 / 180);
                x3 = int(x1 + cos(f) * R);
                y3 = int(-(-y1 + sin(f) * R));
                SDL_RenderDrawPoint(renderer, x3, y3);
            }
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_w) && (Rocket_place.y>=205) && (x1>Rocket_place.x+10))
        {
            Rocket_place.y -= 43;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_s) && (Rocket_place.y <= 535) && (x1 > Rocket_place.x + 10))
        {
            Rocket_place.y += 43;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP) && (Rocket_place2.y >= 205) && (x1 < Rocket_place2.x))
        {
            Rocket_place2.y -= 43;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place2);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN) && (Rocket_place2.y <= 535) && (x1 < Rocket_place2.x))
        {
            Rocket_place2.y += 43;
            SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place2);
        }

        if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
        {
            menu_pause(renderer, p);
        }
        
        tl = win_round_left;
        _itoa_s(tl, text, 10);
        textTexture = get_text_texture(renderer, text, my_font);
        draw_text(renderer, textTexture);

        tr = win_round_right;
        _itoa_s(tr, text2, 10);
        textTexture2 = get_text_texture(renderer, text2, my_font);
        draw_text2(renderer, textTexture2);

        if (win_round_right == 5)
        {
            p = true;
            printf("Winer right\n");
        }

        if (win_round_left == 5)
        {
            p = true;
            printf("Winer left\n");
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (p == true)
    {
        SDL_Delay(1000);
        SDL_DestroyTexture(Rocket);
        SDL_DestroyTexture(BGTU_table);
        SDL_DestroyTexture(Green_table);
        SDL_DestroyTexture(Blue_table);
        SDL_DestroyTexture(Tablo);
        SDL_DestroyTexture(Play_fon);
    }
}