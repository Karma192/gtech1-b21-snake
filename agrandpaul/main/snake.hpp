#pragma once
#include <SDL2/SDL.h>

#define WIDTHGAME 540
#define HEIGHTWINDOW 630
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

class Snake {
public :
    int keys(void);
    void Move(int dir);
    int colBoard(void);
    int colApple(int aPosx, int aPosy);
    void drawHead(SDL_Renderer *renderer);
    Snake(void);
    ~Snake(void);
    void drawTails(SDL_Renderer *renderer);
    int colTail(void);
    void setList(void);

private :
    int posx = 0;
    int posy = 0;
    int prev_dir = 0;
    listx();
    listy();
};