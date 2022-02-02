#include <iostream>
#include <SDL2/SDL.h>

class Snake {
public :
    int keys(void);
    void Move(int dir);
    int colBoard(void);
    Snake *initSnake(void);

private :
    int posx = 0;
    int posy = 0;
    int prev_dir = 0;
};