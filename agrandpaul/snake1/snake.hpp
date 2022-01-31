#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Head {
    public :
    int posx = NULL;
    int posy = NULL;
    int dir = NULL;

    private :

};

int Move(int dir)
{
    if(dir == 1)
    {
        posy += SIZEOFSQUARE;
        posx = posx;
    }

    if (dir == 2)
    {
        posx += SIZEOFSQUARE;
        posy = posy;
    }

    if (dir == 3)
    {
        posx -= SIZEOFSQUARE;
        posy = posy;
    }

    if (dir == 4)
    {
        posx -= SIZEOFSQUARE;
        posy = posy
    }
}