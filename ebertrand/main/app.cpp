#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "apple.hpp"
#include "MainSDLWindow.hpp"
#include "snake.hpp"

#define HEIGHTWINDOW 600

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

Uint32 frame_rate = 16;
Uint32 frame_time_start = SDL_GetTicks();
Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;

int DrawSnake(SDL_Renderer *renderer)
{
    Snake *S = new Snake();
    SDL_Rect head;
    head.w = SIZEOFSQUARE;
    head.h = SIZEOFSQUARE;
    head.x = S->posx;
    head.y = S->posy;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
    SDL_RenderDrawRect(renderer, &head);
    SDL_RenderFillRect(renderer, &head);
    SDL_RenderPresent(renderer);
}

int DrawApple(SDL_Renderer *renderer)
{
    Apple *A = new Apple();
    SDL_Rect apple;
    apple.w = SIZEOFSQUARE;
    apple.h = SIZEOFSQUARE;
    apple.x = A->posx;
    apple.y = A->posy;

    SDL_SetRenderDrawColor(renderer, 138, 3, 3, 255);
    SDL_RenderDrawRect(renderer, &apple);
    SDL_RenderFillRect(renderer, &apple);
    SDL_RenderPresent(renderer);
}

int keys(void)
{
    int tmpdir = prev_dir;
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    SDL_Event event;
    SDL_PollEvent(&event);

    if (keystate[SDL_SCANCODE_UP])
    {
        tmpdir = UP;
    }

    if (keystate[SDL_SCANCODE_DOWN])
    {
        tmpdir = DOWN;
    }

    if (keystate[SDL_SCANCODE_RIGHT])
    {
        tmpdir = RIGHT;
    }

    if (keystate[SDL_SCANCODE_LEFT])
    {
        tmpdir = LEFT;
    }

    if (tmpdir == -prev_dir)
    {
        return prev_dir;
    }
    else
    {
        prev_dir = tmpdir;
        return prev_dir;
    }
}

void Move(int prev_dir)
{

    if (prev_dir == UP)
    {
        posy = posy - SIZEOFSQUARE;
        posx = posx;
    }

    if (prev_dir == DOWN)
    {
        posy = posy + SIZEOFSQUARE;
        posx = posx;
    }

    if (prev_dir == LEFT)
    {
        posx = posx - SIZEOFSQUARE;
        posy = posy;
    }

    if (prev_dir == RIGHT)
    {
        posx = posx + SIZEOFSQUARE;
        posy = posy;
    }
}

int colBoard(void)
{
    if (posx >= WIDTHGAME || posy >= WIDTHGAME)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int colApple(Apple *A)
{
    if (posx == A->posx && posy == A->posy)
    {
        cout << "yeeeeees" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    MainSDLWindow sdlwin;
    if (sdlwin.Init("Snake", 540, 600) == EXIT_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    int exit = 0;
    while (exit == 0)
    {
        DrawSnake(sdlwin.GetRenderer());
        keys();
        DrawApple(sdlwin.GetRenderer());
        Move(keys());
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit = 1;
            }
        }
    }
}