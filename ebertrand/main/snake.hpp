#pragma once
#include <SDL2/SDL.h>

#define WIDTHGAME 540
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)
#define zero 0


class Snake{
    public:
        int posy;
        int posx;
        int prev_dir;
        Snake();
        ~Snake();
};