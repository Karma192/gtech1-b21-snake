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
        int aposy;
        int aposx;
        int randomx;
        int randomy;
        Apple();
        ~Apple();
};