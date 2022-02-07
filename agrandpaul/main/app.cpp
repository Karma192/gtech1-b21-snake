#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
using namespace std;

#include "apple.hpp"
#include "snake.hpp"
#include "score.hpp"
#include "MainSDLWindow.hpp"

#define WIDTHGAME 540
#define HEIGHTWINDOW 630
#define SIZE 30

Uint32 frame_rate = 80;

int main(void)
{
    Snake snakeH;
    Apple A;
    Score sc;
    MainSDLWindow sdlwin;
    if (sdlwin.Init("Snake", WIDTHGAME, HEIGHTWINDOW) == EXIT_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    int exit = 0;
    int gameOver = 0;
    int score = 0;
    int apple = 0;
    sdlwin.runTHSetName();
    while (exit == 0 && gameOver == 0)
    {
        Uint32 frame_time_start = SDL_GetTicks();
        sdlwin.map();
        snakeH.drawHead(sdlwin.GetRenderer());
        snakeH.keys();
        A.DrawApple(sdlwin.GetRenderer());
        snakeH.Move(snakeH.keys());
        SDL_RenderPresent(sdlwin.GetRenderer());
        score = score + snakeH.colApple(A.GetPosx(), A.GetPosy());
        sc.drawScore(sdlwin.GetRenderer(), score);
        A.colSnake(snakeH.colApple(A.GetPosx(), A.GetPosy()));
        gameOver = snakeH.colBoard();
        exit = sdlwin.redCross();
        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if (frame_time_interval < frame_rate)
        {
            SDL_Delay(frame_rate - frame_time_interval);
        }
    }

    if (gameOver != 0)
    {
        SDL_Delay(1000);
        cout << "Game Over..." << endl;
        cout << "Your score is " << endl;
        cout << score << endl;
    }
}