#pragma once
#include <SDL2/SDL.h>

#define WIDTHGAME 540
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

class Snake {

public :
    int posx = 0;
    int posy = 0;
    int dir = 0;

    int keys()
    {
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        SDL_PollEvent(&event);

        if (keystate[SDL_SCANCODE_UP]) {
            dir = 1;
        }
        
        if (keystate[SDL_SCANCODE_DOWN]) {
            dir = 2;
        }

        if (keystate[SDL_SCANCODE_RIGHT]) { 
            dir = 3;
        }

        if (keystate[SDL_SCANCODE_LEFT]) { 
            dir = 4;
        }

        return dir;
    }

    void Move(int dir)
    {
        
        if(dir == 1)
        {
            posy = posy +SIZEOFSQUARE;
            posx = posx;
        }

        if (dir == 2)
        {
            posy = posy -SIZEOFSQUARE;
            posx = posx;
        }

        if (dir == 3)
        {
            posx = posx -SIZEOFSQUARE;
            posy = posy;
        }

        if (dir == 4)
        {
            posx = posx -SIZEOFSQUARE;
            posy = posy;
        }
    }
};