#pragma once
#include <SDL2/SDL.h>

class Snake {
public :
    int posx = 0;
    int posy = 0;
    int prev_dir = 0;

<<<<<<< HEAD
    private :

};

int keys()
{
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    SDL_Event event;
    SDL_PollEvent(&event);

    if (keystate[SDL_SCANCODE_UP] && dir!=2) {
        cout << "UP" << endl;
        dir = 1;
    }
    
    if (keystate[SDL_SCANCODE_DOWN] && dir!=1) {
        cout << "DOWN" << endl;
        dir = 2;
    }

    if (keystate[SDL_SCANCODE_RIGHT] && dir!=4) { 
        cout << "RIGHT" << endl;
        dir = 3;
    }

    if (keystate[SDL_SCANCODE_LEFT] && dir!=3) { 
        cout << "LEFT" << endl;
        dir = 4;
    }

    return dir;
}

int Move(int dir)
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
        posy = posy
    }
}
=======
};
>>>>>>> ecfb4cbfefa04e3f24271a2ab029f02d0c475ca1
