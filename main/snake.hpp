#pragma once
#include <SDL2/SDL.h>
#include <list>
#include <iostream>
using namespace std;

#define WIDTHGAME 540
#define HEIGHTWINDOW 630
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

extern list<int> listx;
extern list<int> listy;

class Snake {
public :
    int keys(void);
    void Move(int dir);
    int colDeath(void);
    int colApple(int aPosx, int aPosy);
    void drawHead(SDL_Renderer *renderer);
    Snake(void);
    ~Snake(void);
    void initTails(int score);
    void drawTails(SDL_Renderer *renderer);
    void setList(void);
    void error(void);

private :
    int posx = 0;
    int posy = 0;
    int prev_dir = 0;
    int prev_score = 0;
};