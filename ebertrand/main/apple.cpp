#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

#include "apple.hpp"

Apple::Apple()
{
    srand((unsigned)time(NULL));
    int randomx = zero + (rand() % SIZE + 1);
    int randomy = zero + (rand() % SIZE + 1);
    this->posy = randomy * SIZEOFSQUARE;
    this->posx = randomx * SIZEOFSQUARE;
}

