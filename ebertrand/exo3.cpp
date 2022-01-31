#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int positx = 285;
int posity = 285;

using namespace std;
SDL_Renderer *renderer; //Déclaration renderer
SDL_Window* fenetre;  // Déclaration de la fenêtre
Uint32 frame_rate = 17;//FrameRate
Uint32 frame_time_start = SDL_GetTicks(); 

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

int keys(void){
  int i;

  SDL_Rect rect;
  rect.w = 30;
  rect.h = 30;
  rect.x = positx;
  rect.y = posity;

  SDL_Event event;
  SDL_PollEvent(&event);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderDrawRect(renderer, &rect);
  SDL_RenderFillRect(renderer, &rect); 
  SDL_RenderPresent(renderer);

  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_UP] && i!=-1) {
    while (keystate[SDL_SCANCODE_LEFT]==0 || keystate[SDL_SCANCODE_RIGHT]==0){
      SDL_Delay(50);
      cout << "UP" << endl;
      posity-=10;
      keys();
      i=1;
    }
  }

  if (keystate[SDL_SCANCODE_DOWN] && i!=1) {
    while (keystate[SDL_SCANCODE_LEFT]==0 || keystate[SDL_SCANCODE_RIGHT]==0){
      SDL_Delay(50);
      cout << "DOWN" << endl;
      posity+=10;
      keys();
      printf("%d\n", i);
      i=-1;
    }
  }

  if (keystate[SDL_SCANCODE_RIGHT] && i!=-2) {
    while (keystate[SDL_SCANCODE_DOWN]==0 || keystate[SDL_SCANCODE_UP]==0){
      SDL_Delay(50);     
      cout << "RIGHT" << endl;
      positx+=10;
      keys();
      i=2;
    }
  }

  if (keystate[SDL_SCANCODE_LEFT] && i!=2) { 
    while (keystate[SDL_SCANCODE_DOWN]==0 || keystate[SDL_SCANCODE_UP]==0 || keystate[SDL_SCANCODE_RIGHT]==1){
      SDL_Delay(50);
      cout << "LEFT" << endl;
      positx-=10;
      keys();
      i=-2;
    }
  }

  printf("%d\n", *i);
  return 0;

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
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        exit =1;
      }
    } 
  }
  destroyMap();
}