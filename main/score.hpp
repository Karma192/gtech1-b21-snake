#pragma once
#include <SDL2/SDL.h>

#define WIDTHGAME 540
#define SIZE 30
#define SIZESHOWSCORE 90
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

class Score {
    public:
        void drawScore(SDL_Renderer *renderer, int score);
        int i = 0;

    private:
        int Red;
        int Green;
        int Blue;
        int verY = 0;
        int verShow = 0;
        int sposx = 0;
        int sposy = 31 * SIZEOFSQUARE;
        int x;
        int y;
};