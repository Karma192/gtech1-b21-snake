#include "snake.hpp"

#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

int Snake::keys(void) {
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

void Snake::Move(int dir) {
    if(dir == UP)
    {
        this->posy = this->posy -SIZEOFSQUARE;
        this->posx = this->posx;
    }

    if (dir == DOWN)
    {
        this->posy = this->posy +SIZEOFSQUARE;
        this->posx = posx;
    }

    if (dir == LEFT)
    {
        this->posx = this->posx -SIZEOFSQUARE;
        this->posy = this->posy;
    }

    if (dir == RIGHT)
    {
        this->posx = this->posx +SIZEOFSQUARE;
        this->posy = this->posy;
    }
}

int Snake::colBoard(void) {
    if (this->posx >= WIDTHGAME || this->posy >= WIDTHGAME || this->posx < 0 || this->posy < 0) {
        return 1;
    }
    else {return 0;}
}

int Snake::colApple(int aPosx, int aPosy) {
    if (this->posx == aPosx && this->posy == aPosy) {
        return 1;
    }
    else {return 0;}
}

Snake::Snake(void) {
    this->posx = 15*SIZEOFSQUARE;
    this->posy = 15*SIZEOFSQUARE;
    this->prev_dir = 0;
}

Snake::~Snake(void) {

}

void Snake::drawHead(SDL_Renderer *renderer) {
    SDL_Rect head;
    head.w = SIZEOFSQUARE;
    head.h = SIZEOFSQUARE;
    head.x = this->posx;
    head.y = this->posy;

    SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
    SDL_RenderDrawRect(renderer, &head);
    SDL_RenderFillRect(renderer, &head); 
}

/*void Snake::drawTails(Snake *tails)
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

/*Snake *Snake::initTails(void)
{
    Snake *tails... = new Snake();

    tails->posx = posx...;
    tails->posy = posy...;
    tails->prev_dir = prev_dir...;

    return tails;
}*/

/*int Snake::colTail(void)
{
    if (posx == ... && posy == ...) {
        return 1;
    }

    else {return 0;}
}*/