#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


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

SDL_Renderer *renderer; //Déclaration renderer
SDL_Window* fenetre;  // Déclaration de la fenêtre

int map(void){
  if(SDL_Init(SDL_INIT_VIDEO) < 0)  // initialisation de la SDL
  {
      printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
      return EXIT_FAILURE;
  }

  fenetre = SDL_CreateWindow("Une fenetre SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 600, 600, 0);  // Création de la fenêtre

  if (fenetre == NULL)  //gestion des erreurs
  {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
  }

  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(renderer == NULL)//gestion des erreurs
  {
    printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
    return EXIT_FAILURE;
  }
}

int keys(void)
{
    SDL_Rect head;
    head.w = SIZEOFSQUARE;
    head.h = SIZEOFSQUARE;
    head.x = posx;
    head.y = posy;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
    SDL_RenderDrawRect(renderer, &head);
    SDL_RenderFillRect(renderer, &head); 
    SDL_RenderPresent(renderer);

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
  SDL_DestroyRenderer(renderer); 
  SDL_DestroyWindow(fenetre);
  SDL_Quit();  //on quitte la SDL
  return 0;
}

int main(void){
  int exit = 0;
  map();
  while (exit == 0){
    keys();
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