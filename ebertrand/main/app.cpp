#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "apple.hpp"
#include "snake.hpp"
#include "MainSDLWindow.hpp"

#define HEIGHTWINDOW 600

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

Uint32 frame_rate = 50;

int posx = 15 * SIZEOFSQUARE;
int posy = 15 * SIZEOFSQUARE;

int prev_dir = 0;

Apple *A = new Apple();

int DrawSnake(SDL_Renderer *renderer)
{
    SDL_Rect head;
    head.w = SIZEOFSQUARE;
    head.h = SIZEOFSQUARE;
    head.x = posx;
    head.y = posy;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
    SDL_RenderDrawRect(renderer, &head);
    SDL_RenderFillRect(renderer, &head);
}

int DrawApple(SDL_Renderer *renderer)
{
    SDL_Rect rect;
    rect.x = A->aposx;
    rect.y = A->aposy;
    rect.w = SIZEOFSQUARE;
    rect.h = SIZEOFSQUARE;

    SDL_SetRenderDrawColor(renderer, 138, 3, 3, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
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

int colBoard()
{
    if (posx >= WIDTHGAME || posy >= WIDTHGAME || posx < 0 || posy < 0)
    {
        SDL_Renderer *renderer;
        SDL_Window *fenetre;
        cout << "GAME OVER" << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 1;
    }
}

int colApple(SDL_Renderer *renderer)
{
    int i = 0;
    if (posx == A->aposx && posy == A->aposy)
    {
        cout << "yes" << endl;
        A.~Apple();
        Apple *A = new Apple();
        return 1;
    }
    else
    {
        cout << A->aposx << endl;
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
        if (colBoard() == 1)
        {
            break;
        }
        else
        {
            Uint32 frame_time_start = SDL_GetTicks();
            DrawSnake(sdlwin.GetRenderer());
            keys();
            DrawApple(sdlwin.GetRenderer());
            colApple(sdlwin.GetRenderer());
            Move(keys());
            SDL_RenderPresent(sdlwin.GetRenderer());
            Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
            if (frame_time_interval < frame_rate)
            {
                SDL_Delay(frame_rate - frame_time_interval);
            }
        }
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