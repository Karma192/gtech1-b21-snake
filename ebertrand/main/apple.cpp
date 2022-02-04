#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

#include "apple.hpp"


int DrawApple(){
    SDL_Renderer *apple; //Déclaration renderer
    Apple A = Apple();
    SDL_Rect rect;
    rect.x = A.posx;
    rect.y = A.posy;
    rect.w = SIZEOFSQUARE;
    rect.h = SIZEOFSQUARE;

    SDL_SetRenderDrawColor(apple, 138, 3, 3, 255);
    SDL_RenderDrawRect(apple, &rect);
    SDL_RenderFillRect(apple, &rect); 
    SDL_RenderPresent(apple);
}