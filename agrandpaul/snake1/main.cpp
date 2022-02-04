#include <SDL2/SDL.h>
#include <iostream>

#include "snake.hpp"
#include "MainSDLWindow.hpp"

#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)
Uint32 frame_rate = 7;

using namespace std;

int main(void)
{
    int Exit = 0;
    int gameOver = 0;
    int score = 0;
    MainSDLWindow sdlwin;
    if (sdlwin.Init("Snake", 800, 600) == EXIT_FAILURE) {
      exit(EXIT_FAILURE);
    }
    Snake *snakeHead = snakeHead->initSnake();

    while (Exit == 0 || gameOver == 0)
    {
        gameOver = snakeHead->colBoard();
        //gameOver = snakeH->colTail();
        snakeHead->drawHead(snakeHead, sdlwin.GetRenderer());
        snakeHead->Move(snakeHead->keys());
        SDL_RenderClear(sdlwin.GetRenderer());
        Exit = sdlwin.redCross();
    }

    if (gameOver != 0) {
        cout << "Game Over..." << endl;
        cout << "Your score is " << endl;
        cout << score << endl;
    }
    return 0;
}