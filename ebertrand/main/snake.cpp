#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "snake.hpp"

Snake::Snake()
{
    int posx = 15 * SIZEOFSQUARE;
    int posy = 15 * SIZEOFSQUARE;
    int prev_dir = 0;
}