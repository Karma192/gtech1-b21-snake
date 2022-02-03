#include <SDL2/SDL.h>
#include <iostream>

// #include "snake.hpp"
#include "window.cpp"
#include "head.cpp"
#include "drawSnake.cpp"

#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)
Uint32 frame_rate = 7;

using namespace std;

int main(void)
{
    int exit = 0;
    int gameOver = 0;
    int score = 0;
    windows();
    Snake *snakeH = initSnake();

    while (exit == 0 || gameOver == 0)
    {
        map();
        gameOver = snakeH->colBoard();
        //gameOver = snakeH->colTail();
        drawHead(snakeH);
        snakeH->Move(snakeH->keys());
        SDL_RenderClear(renderer);
        exit = redCross();
    }

    if (gameOver != 0) {
        cout << "Game Over..." << endl;
        cout << "Your score is " << endl;
    }
    destroy();
    return 0;
}