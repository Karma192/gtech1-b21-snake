#include <iostream>
#include <SDL2/SDL.h>

#include "window.cpp"

#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

class Snake {
private :
    int posx = 0;
    int posy = 0;
    int prev_dir = 0;

public :
    int keys(void)
    {
        int tmpdir = this->prev_dir;
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        SDL_PollEvent(&event);

        if (keystate[SDL_SCANCODE_UP]) {
            tmpdir = UP;
        }
        
        if (keystate[SDL_SCANCODE_DOWN]) {
            tmpdir = DOWN;
        }

        if (keystate[SDL_SCANCODE_RIGHT]) { 
            tmpdir = RIGHT;
        }

        if (keystate[SDL_SCANCODE_LEFT]) { 
            tmpdir = LEFT;
        }
        
        if (tmpdir == - this->prev_dir)
        {
            return this->prev_dir;
        }
        else{
            this->prev_dir = tmpdir;
            return this->prev_dir;
        }

    }

    void Move(int dir)
    {
        
        if(dir == UP)
        {
            posy = posy +SIZEOFSQUARE;
            posx = posx;
        }

        if (dir == DOWN)
        {
            posy = posy -SIZEOFSQUARE;
            posx = posx;
        }

        if (dir == LEFT)
        {
            posx = posx -SIZEOFSQUARE;
            posy = posy;
        }

        if (dir == RIGHT)
        {
            posx = posx +SIZEOFSQUARE;
            posy = posy;
        }
    }

    int colBoard(void)
    {
        if (this->posx >= WIDTHGAME || this->posy >= WIDTHGAME) {
            return 1;
        }
        else {return 0;}
    }

    /*int colTail(void)
    {
        if (posx == ... && posy == ...) {
            return 1;
        }

        else {return 0;}
    }*/
    
    Snake *initSnake(void)
    {
        Snake *snakeH = new Snake();

        snakeH->posx = 15*SIZEOFSQUARE;
        snakeH->posy = 15*SIZEOFSQUARE;
        snakeH->prev_dir = 0;

        return snakeH;
    }

    /*Snake *initTails(void)
    {
        Snake *tails... = new Snake();

        tails->posx = posx...;
        tails->posy = posy...;
        tails->prev_dir = prev_dir...;

        return tails;
    }*/

    void drawHead(Snake *snakeHead)
    {
        SDL_Rect head;
        head.w = SIZEOFSQUARE;
        head.h = SIZEOFSQUARE;
        head.x = snakeHead->posx;
        head.y = snakeHead->posy;

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
};