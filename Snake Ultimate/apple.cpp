#include <SDL2/SDL.h>
#include <iostream>
#include <time.h>
using namespace std;

#include "apple.hpp"

int Apple::GetPosx(void)
{
    return this->aposx;
}

int Apple::GetPosy(void)
{
    return this->aposy;
}

void Apple::DrawApple(SDL_Renderer *renderer)
{
    SDL_Rect rect;
    rect.x = this->aposx;
    rect.y = this->aposy;
    rect.w = SIZEOFSQUARE;
    rect.h = SIZEOFSQUARE;

    SDL_SetRenderDrawColor(renderer, 138, 3, 3, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
}

void Apple::colSnake(int ver)
{
    if (ver == 1)
    {
        srand((unsigned)time(NULL));
        randomx = rand() % SIZE;
        randomy = rand() % SIZE;
        this->aposy = randomy * SIZEOFSQUARE;
        this->aposx = randomx * SIZEOFSQUARE;
    }
}