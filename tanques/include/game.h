#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "allegro.h"
#include "allegro_image.h"
#include "allegro_font.h"
#include "allegro_ttf.h"
#include "allegro_audio.h"
#include "allegro_acodec.h"
#include <cstdio>
#include <vector>

class game
{
    public:
        static game *Get_instance_game();
        int getWidth_Screen();
        int getHeight_Screen();
        int getWidth_world();
        int getHeight_world();
        //void load_coin(vector<float>);
        //void load_coin(std::vector<float>);
        ALLEGRO_FONT *getfont();
        ALLEGRO_DISPLAY *getdisplay();
        ALLEGRO_SAMPLE * getmusic();
    private:
        game();
        ALLEGRO_DISPLAY *display;
        ALLEGRO_FONT *font;
        ALLEGRO_SAMPLE *MUSIC;
        ALLEGRO_BITMAP *coin;
        static game *instan_game;
        int screenWidth;
        int screenHeight;
        int worldWidth;
        int worldHeight;
};

#endif // GAME_H
