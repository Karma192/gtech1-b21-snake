#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "snake.hpp"

Snake::Snake()
{
    posx = 15 * SIZEOFSQUARE;
    posy = 15 * SIZEOFSQUARE;
    this->prev_dir = 0;
}