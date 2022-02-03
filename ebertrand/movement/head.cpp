#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "apple.cpp"
#include "window.cpp"


#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

int posx = 15*SIZEOFSQUARE;
int posy = 15*SIZEOFSQUARE;
int prev_dir = 0;

int DrawSnake(){
    SDL_Rect head;
    head.w = SIZEOFSQUARE;
    head.h = SIZEOFSQUARE;
    head.x = posx;
    head.y = posy;

    SDL_SetRenderDrawColor(snake, 0, 0, 0, 255);
    SDL_RenderClear(snake);

    SDL_SetRenderDrawColor(snake, 1, 50, 32, 255);
    SDL_RenderDrawRect(snake, &head);
    SDL_RenderFillRect(snake, &head); 
    SDL_RenderPresent(snake);
}

int keys(void)
{
    int tmpdir = prev_dir;
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
    
    if (tmpdir == - prev_dir)
    {
        return prev_dir;
    }
    else{
        prev_dir = tmpdir;
        return prev_dir;
    }

}

void Move(int prev_dir)
{
    
    if(prev_dir == UP)
    {
        posy = posy -SIZEOFSQUARE;
        posx = posx;
    }

    if (prev_dir == DOWN)
    {
        posy = posy +SIZEOFSQUARE;
        posx = posx;
    }

    if (prev_dir == LEFT)
    {
        posx = posx -SIZEOFSQUARE;
        posy = posy;
    }

    if (prev_dir == RIGHT)
    {
        posx = posx +SIZEOFSQUARE;
        posy = posy;
    }
}

int colBoard(void)
{
    if (posx >= WIDTHGAME || posy >= WIDTHGAME) {
        return 1;
    }
    else {return 0;}
}

int destroyMap(){
    SDL_DestroyRenderer(snake); 
    SDL_DestroyRenderer(apple); 
    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL
    return 0;
}

int main(){
  int exit = 0;
  map();
  while (exit == 0){
    DrawSnake();
    keys();
    DrawApple();
    Move(keys());
    SDL_Delay(100);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        exit =1;
      }
    } 
  }
  destroyMap();
}