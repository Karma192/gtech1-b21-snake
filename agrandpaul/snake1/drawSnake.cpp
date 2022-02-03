#include <SDL2/SDL.h>
#include <iostream>

//#include "snake.hpp"
//#include "window.cpp"
#include "head.cpp"

#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

Snake *initSnake()
{
    Snake *snakeH = new Snake();

    snakeH->posx = 15*SIZEOFSQUARE;
    snakeH->posy = 15*SIZEOFSQUARE;
    snakeH->prev_dir = 0;

    return snakeH;
}

/*Snake *initTails()
{
    Snake *tails... = new Snake();

    tails->posx = posx...;
    tails->posy = posy...;
    tails->prev_dir = prev_dir...;

    return tails;
}*/

void drawHead(Snake *snakeH)
{
    SDL_Rect head;
    head.w = SIZEOFSQUARE;
    head.h = SIZEOFSQUARE;
    head.x = snakeH->posx;
    head.y = snakeH->posy;

    SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
    SDL_RenderDrawRect(renderer, &head);
    SDL_RenderFillRect(renderer, &head); 
    SDL_RenderPresent(renderer);
}

/*void drawTails(Snake *tails)
{
    SDL_Rect tail;
    tail.w = SIZEOFSQUARE;
    tail.h = SIZEOFSQUARE;
    tail.x = tails->posx;
    tail.y = tails->posy;

    SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
    SDL_RenderDrawRect(renderer, &tail);
    SDL_RenderFillRect(renderer, &tail); 
    SDL_RenderPresent(renderer);
}*/