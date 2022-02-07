#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "apple.hpp"
#include "snake.hpp"
//#include "score.hpp"
#include "MainSDLWindow.hpp"

#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

int frame_delay;
int frame_rate_ms = 20;
Uint32 frame_start;

int main(void)
{
    Snake snakeH;
    Apple A;
    MainSDLWindow sdlwin;
    if (sdlwin.Init("Snake", WIDTHGAME, HEIGHTWINDOW) == EXIT_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    /*Score scwin;
    if (scwin.Init("Score Snake", 100, 50) == EXIT_FAILURE)
    {
        exit(EXIT_FAILURE);
    }*/
    int exit = 0;
    int gameOver = 0;
    int score = 0;
    int apple = 0;
    while (exit == 0 && gameOver == 0)
    {
        frame_start = SDL_GetTicks();
        sdlwin.map();
        snakeH.drawHead(sdlwin.GetRenderer());
        snakeH.keys();
        A.DrawApple(sdlwin.GetRenderer());
        snakeH.Move(snakeH.keys());
        SDL_RenderPresent(sdlwin.GetRenderer());
        score = score + snakeH.colApple(A.GetPosx(), A.GetPosy());
        A.colSnake(snakeH.colApple(A.GetPosx(), A.GetPosy()));
        gameOver = snakeH.colBoard();
        exit = sdlwin.redCross();
        frame_delay = frame_rate_ms - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0){
            SDL_Delay(frame_delay);
        }
    }

    if (gameOver != 0) {
        cout << "Game Over..." << endl;
        cout << "Your score is " << endl;
        cout << score << endl;
    }
}