#pragma once
#include <SDL2/SDL.h>

class Score {
    public :
        Score();
        ~Score();
        int Init(const char* name, int width, int height);
        void SWindow(void);
        void showScore(void);
    private :
        SDL_Renderer *renderer2;
        SDL_Window *window2;
};