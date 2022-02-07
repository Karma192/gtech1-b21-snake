#pragma once
#include <SDL2/SDL.h>

class Snake {
public :
    int keys(void);
    void Move(int dir);
    int colBoard(void);
    int colApple(int aPosx, int aPosy);
    void drawHead(SDL_Renderer *renderer);
    Snake(void);
    ~Snake(void);
    //void drawTails(Snake *tails);
    //Snake *initTails(void);
    //int colTail(void);

private :
    int posx = 0;
    int posy = 0;
    int prev_dir = 0;
    Snake *next;
};


int list[][][][] = {}


list[5] 

 sizeof(list)
for (int i =listnbv ; i < 0; i--)
{
    listx [i] = list [i-1];
}


segment = 5; 
listx [segment]