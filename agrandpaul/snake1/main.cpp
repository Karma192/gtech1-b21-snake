#include <SDL2/SDL.h>
#include <iostream>

#include "snake.hpp"
#include "window.cpp"
#include "head.cpp"

#define WIDTHGAME 540
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)
Uint32 frame_rate = 7;

using namespace std;

Snake *initSnake()
{
    Snake *snakeH = new Snake();

    snakeH->posx = 15*SIZEOFSQUARE;
    snakeH->posy = 15*SIZEOFSQUARE;
    snakeH->prev_dir = 0;
    return snakeH;
}

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

int main(void)
{
    int exit = 0;
    Snake *snakeH = initSnake();

    while (exit == 0)
    {
        map();
        drawHead(snakeH);
        snakeH->Move(snakeH->keys());
        SDL_RenderClear(renderer);
        exit = redCross();
    }
    destroy();
    return 0;
}