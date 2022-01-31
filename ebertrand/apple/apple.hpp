#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

#define WIDTHGAME 540
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

class Apple{
    public:
        int posy;
        int posx;
        Apple(){
            
            SDL_Renderer *renderer;

            srand((unsigned) time(NULL));
            int randomx = 0 + (rand() % 31);
            int randomy = 0 + (rand() % 31);
            posy = randomy * SIZEOFSQUARE;
            posx = randomx * SIZEOFSQUARE;
            
            SDL_Rect rect;
            rect.x = this->posx;
            rect.y = this->posy;
            rect.w = SIZEOFSQUARE;
            rect.h = SIZEOFSQUARE;

            SDL_SetRenderDrawColor(renderer, 138, 3, 3, 255);
            SDL_RenderDrawRect(renderer, &rect);
            SDL_RenderFillRect(renderer, &rect); 
            SDL_RenderPresent(renderer);

        }
};