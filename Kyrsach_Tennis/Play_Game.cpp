#include"Play.h"
#include"Pause.h"
#include"Win_game.h"

Mix_Music* fon_game = NULL;
Mix_Chunk* Sound1 = NULL;
Mix_Chunk* Sound2 = NULL;
Mix_Chunk* Sound3 = NULL;

void loadmusic2()
{
    fon_game = Mix_LoadMUS("fon_game.mp3");
    Mix_PlayMusic(fon_game, -1);
}

void sound1()
{
    Sound1 = Mix_LoadWAV("Table.mp3");
    Mix_PlayChannel(-1, Sound1, 0);
}

void sound2()
{
    Sound2 = Mix_LoadWAV("Rocket.mp3");
    Mix_PlayChannel(-1, Sound2, 0);
}

void sound3()
{
    Sound3 = Mix_LoadWAV("svistok.mp3");
    Mix_PlayChannel(-1, Sound3, 0);
}

int napr()
{
    int x=rand()%(8-(-8)+1)+(-8);
    if (x == 8 || x == (-8)) { return x; }
    else { napr(); }
}

void proverka(int razn)
{
    int a[5], size=0, vrem=0;
    FILE* f = fopen("Records.txt", "rt");
    while (!feof(f))
    {
        fscanf(f, "%d", &a[size]);
        size++;
    }
    fclose(f);

    if (razn > a[0])
    {
        for (int i = 4; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = razn;
    }
    if (razn < a[0] && razn>a[1])
    {
        for (int i = 4; i > 1; i--)
        {
            a[i] = a[i - 1];
        }
        a[1] = razn;
    }
    if (razn < a[1] && razn>a[2])
    {
        for (int i = 4; i > 2; i--)
        {
            a[i] = a[i - 1];
        }
        a[2] = razn;
    }
    if (razn < a[2] && razn>a[3])
    {
        a[4] = a[3];
        a[3] = razn;
    }
    if (razn < a[3] && razn>a[4]) a[4] = razn;

    FILE* f1 = fopen("Records.txt", "wt");
    for (int i = 0; i < size; i++)
        fprintf(f1, "%d ", a[i]);
    fclose(f1);
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

void play(SDL_Renderer*& renderer, int table, int zvyk, bool& quit)
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

    SDL_Rect win_round = { 200, 200, 800, 424 };
    SDL_Surface* Win_round_left1 = IMG_Load("Win_round_left.bmp");
    SDL_SetColorKey(Win_round_left1, SDL_TRUE, SDL_MapRGB(Win_round_left1->format, 255, 255, 255));
    SDL_Texture* Win_round_left_texture = SDL_CreateTextureFromSurface(renderer, Win_round_left1);
    SDL_FreeSurface(Win_round_left1);

    SDL_Surface* Win_round_right1 = IMG_Load("Win_round_right.bmp");
    SDL_SetColorKey(Win_round_right1, SDL_TRUE, SDL_MapRGB(Win_round_right1->format, 255, 255, 255));
    SDL_Texture* Win_round_right_texture = SDL_CreateTextureFromSurface(renderer, Win_round_right1);
    SDL_FreeSurface(Win_round_right1);

    TTF_Init();
    TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
    SDL_Texture* textTexture;
    SDL_Texture* textTexture2;

    int win_round_left = 0, win_round_right = 0, win_left = 0, win_right = 0, left = 0, right = 0, razn;
    int tl = 0;
    int tr = 0;
    char text[10];
    char text2[10];
    textTexture = get_text_texture(renderer, text, my_font);
    textTexture2 = get_text_texture2(renderer, text2, my_font);

    tl = win_round_left;
    _itoa_s(tl, text, 10);
    textTexture = get_text_texture(renderer, text, my_font);

    tr = win_round_right;
    _itoa_s(tr, text2, 10);
    textTexture2 = get_text_texture(renderer, text2, my_font);

    SDL_Rect Rocket_place = { 198,370, 10,80 };
    SDL_Rect Rocket_place2 = { 992,370, 10,80 };
    int x = 0, y = 0;
    int x3, y3, x1 = 600, y1 = 412;
    int x2 = napr();
    int y2 = napr();
    double f;
    bool p = false, change=false, s=false, v=false;
    if (zvyk == 1) loadmusic2();
    while (!p)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {quit = true; p = true;}
        SDL_RenderCopy(renderer, Play_fon, NULL, NULL);
        SDL_RenderCopy(renderer, Tablo, NULL, &tablo);
        SDL_RenderCopy(renderer, Blue_table, NULL, &table_koord);
        if (table == 1) SDL_RenderCopy(renderer, Blue_table, NULL, &table_koord);
        if (table == 2) SDL_RenderCopy(renderer, Green_table, NULL, &table_koord);
        if (table == 3) SDL_RenderCopy(renderer, BGTU_table, NULL, &table_koord);
        SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place);
        SDL_RenderCopy(renderer, Rocket, NULL, &Rocket_place2);
        SDL_GetMouseState(&x, &y);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        x1 += x2;
        y1 += y2;
        if ((x1 - 22 < Rocket_place.x) && ((y1 < Rocket_place.y+Rocket_place.h+9) && (y1>Rocket_place.y-11)) && (x1>Rocket_place.x+17))
        {
            x2 = -x2;
            if(zvyk==1) sound2();
        }
        if ((x1 + 12 > Rocket_place2.x) && ((y1 < Rocket_place2.y + Rocket_place2.h+9) && (y1 > Rocket_place2.y-11)) && (x1 < Rocket_place2.x-7))
        {
            x2 = -x2;
            if(zvyk==1) sound2();
        }
        if (x1<Rocket_place.x-20)
        {
            x2 = 0; y2 = 0;
            SDL_Delay(1000);
            Rocket_place = { 198,370, 10,80 };
            Rocket_place2 = { 992,370, 10,80 };
            win_round_right += 1;
            right += 1;
            change = true;
            x1 = 600;
            y1 = 412;
            x2 = napr();
            y2 = napr();
        }
        if (x1 > Rocket_place2.x+20)
        {
            x2 = 0; y2 = 0;
            SDL_Delay(1000);
            Rocket_place = { 198,370, 10,80 };
            Rocket_place2 = { 992,370, 10,80 };
            win_round_left += 1;
            left += 1;
            change = true;
            x1 = 600;
            y1 = 412;
            x2 = napr();
            y2 = napr();
        }
        if ((y1 + 10 > 624) || (y1 - 10 < 200)) 
        {
            y2 = -y2;
            if(zvyk==1) sound1();
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
            menu_pause(renderer, p, quit);
        }
        
        if (change == true)
        {
            change = false;
            tl = win_round_left;
            _itoa_s(tl, text, 10);
            textTexture = get_text_texture(renderer, text, my_font);

            tr = win_round_right;
            _itoa_s(tr, text2, 10);
            textTexture2 = get_text_texture(renderer, text2, my_font);
        }

        if (win_round_right == 5)
        {            
            tl = win_round_left;
            _itoa_s(tl, text, 10);
            textTexture = get_text_texture(renderer, text, my_font);
            tr = win_round_right;
            _itoa_s(tr, text2, 10);
            textTexture2 = get_text_texture(renderer, text2, my_font);
            draw_text(renderer, textTexture);
            draw_text2(renderer, textTexture2);
            SDL_RenderPresent(renderer);

            win_right += 1;
            if (win_left + win_right == 3)
            {
                razn = abs(right - left);
                proverka(razn);
                winer(renderer, p, win_right, win_left, left, right, v, zvyk, quit);
                left = 0;
                right = 0;
            }
            if(win_right+win_left<3) SDL_RenderCopy(renderer, Win_round_right_texture, NULL, &win_round);
            if (win_right+win_left==3)
            {
                win_right = 0; win_left = 0;
            }
            Rocket_place = { 198,370, 10,80 };
            Rocket_place2 = { 992,370, 10,80 };
            SDL_RenderPresent(renderer);
            if (v == false) SDL_Delay(2000);
            
            win_round_left = 0;
            win_round_right = 0;

            tl = win_round_left;
            _itoa_s(tl, text, 10);
            textTexture = get_text_texture(renderer, text, my_font);
            tr = win_round_right;
            _itoa_s(tr, text2, 10);
            textTexture2 = get_text_texture(renderer, text2, my_font);
            draw_text(renderer, textTexture);
            draw_text2(renderer, textTexture2);
            SDL_RenderPresent(renderer);
            if (v==false) s = false;
        }

        if (win_round_left == 5)
        {
            tl = win_round_left;
            _itoa_s(tl, text, 10);
            textTexture = get_text_texture(renderer, text, my_font);
            tr = win_round_right;
            _itoa_s(tr, text2, 10);
            textTexture2 = get_text_texture(renderer, text2, my_font);
            draw_text(renderer, textTexture);
            draw_text2(renderer, textTexture2);
            SDL_RenderPresent(renderer);

            win_left += 1;
            if (win_left+win_right==3)
            {
                razn = abs(left - right);
                proverka(razn);
                winer(renderer, p, win_right, win_left, left, right, v, zvyk, quit);
                left = 0;
                right = 0;
            }
            if (win_left+win_right<3) SDL_RenderCopy(renderer, Win_round_left_texture, NULL, &win_round);
            if (win_right + win_left == 3)
            {
                win_right = 0; win_left = 0;
            }
            Rocket_place = { 198,370, 10,80 };
            Rocket_place2 = { 992,370, 10,80 };
            SDL_RenderPresent(renderer);
            if(v==false) SDL_Delay(2000);
            
            win_round_left = 0;
            win_round_right = 0;

            tl = win_round_left;
            _itoa_s(tl, text, 10);
            textTexture = get_text_texture(renderer, text, my_font);
            tr = win_round_right;
            _itoa_s(tr, text2, 10);
            textTexture2 = get_text_texture(renderer, text2, my_font);
            draw_text(renderer, textTexture);
            draw_text2(renderer, textTexture2);
            SDL_RenderPresent(renderer);
            if(v==false) s = false;
        }

        draw_text(renderer, textTexture);
        draw_text2(renderer, textTexture2);
        SDL_RenderPresent(renderer);
        if (s == false)
        {
            s = true;
            if(zvyk==1) sound3();
            SDL_Delay(1000);
        }
        SDL_Delay(16);
    }
    if (p == true)
    {
        SDL_Delay(1000);
        SDL_DestroyTexture(Win_round_right_texture);
        SDL_DestroyTexture(Win_round_left_texture);
        SDL_DestroyTexture(textTexture2);
        SDL_DestroyTexture(textTexture);
        SDL_DestroyTexture(Rocket);
        SDL_DestroyTexture(BGTU_table);
        SDL_DestroyTexture(Green_table);
        SDL_DestroyTexture(Blue_table);
        SDL_DestroyTexture(Tablo);
        SDL_DestroyTexture(Play_fon);
    }
    Mix_FreeMusic(fon_game);
    Mix_FreeChunk(Sound3);
    Mix_FreeChunk(Sound2);
    Mix_FreeChunk(Sound1);
}