#include <SDL2/SDL.h>
#include <iostream>

#include "snake.hpp"

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
    Window *window = window->Window();
    Snake *snakeHead = snakeHead->initSnake();

    while (exit == 0 || gameOver == 0)
    {
        window->map();
        gameOver = snakeHead->colBoard();
        //gameOver = snakeH->colTail();
        snakeHead->drawHead(snakeHead);
        snakeHead->Move(snakeHead->keys());
        SDL_RenderClear(Window->renderer);
        exit = window->redCross();
    }

    if (gameOver != 0) {
        cout << "Game Over..." << endl;
        cout << "Your score is " << endl;
        cout << score << endl;
    }
    ~Window();
    return 0;
}