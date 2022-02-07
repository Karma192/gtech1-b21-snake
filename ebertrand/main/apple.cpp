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
    randomx = zero + (rand() % SIZE + 1);
    randomy = zero + (rand() % SIZE + 1);
    this->aposy = randomy * SIZEOFSQUARE;
    this->aposx = randomx * SIZEOFSQUARE;
}
