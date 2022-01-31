#pragma once
#include <SDL2/SDL.h>

#define WIDTHGAME 540
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

class Snake { // -> class Application

public :
    int posx = 0;
    int posy = 0;
    int prev_dir = 0;

    int keys()
    {
        int tmpdir = this->prev_dir;
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        SDL_PollEvent(&event);

        if (keystate[SDL_SCANCODE_UP]) {
            tmpdir = UP;
        }
        
        if (keystate[SDL_SCANCODE_DOWN]) {
            tmpdir = DOWN;
        }

        if (keystate[SDL_SCANCODE_RIGHT]) { 
            tmpdir = RIGHT;
        }

        if (keystate[SDL_SCANCODE_LEFT]) { 
            tmpdir = LEFT;
        }
        
        if (tmpdir == - this->prev_dir)
        {
            return this->prev_dir;
        }
        else{
            this->prev_dir = tmpdir;
            return this->prev_dir;
        }

    }

    void Move(int dir)
    {
        
        if(dir == UP)
        {
            posy = posy +SIZEOFSQUARE;
            posx = posx;
        }

        if (dir == DOWN)
        {
            posy = posy -SIZEOFSQUARE;
            posx = posx;
        }

        if (dir == LEFT)
        {
            posx = posx -SIZEOFSQUARE;
            posy = posy;
        }

        if (dir == RIGHT)
        {
            posx = posx +SIZEOFSQUARE;
            posy = posy;
        }
    }
};