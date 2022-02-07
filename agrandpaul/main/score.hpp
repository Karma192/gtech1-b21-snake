#pragma once
#include <SDL2/SDL.h>

#define WIDTHGAME 540
#define SIZE 30
#define SIZESHOWSCORE 90
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

class Score {
    public :
        Score();
        ~Score();
        void drawScore(SDL_Renderer *renderer, int score);

    private :
        int Red = 11;
        int Green = 143;
        int Blue = 46;
        int verY = 0;
        int verShow = 0;
        int sposx = 0;
        int sposy = 32 *SIZEOFSQUARE;
};