#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

#define WIDTHGAME 540
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)
#define zero 0

class Apple{
    public:
        int posy;
        int posx;
        Apple(){
            
            SDL_Renderer *renderer;

            srand((unsigned) time(NULL));
            int randomx = zero + (rand() % SIZE+1);
            int randomy = zero + (rand() % SIZE+1);
            this->posy = randomy * SIZEOFSQUARE;
            this->posx = randomx * SIZEOFSQUARE;
        }
};