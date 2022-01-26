#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
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

int keys(void){
  SDL_Rect rect;
  rect.w = 30;
  rect.h = 30;
  rect.x = 285;
  rect.y = 285;

  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderDrawRect(renderer, &rect);
  SDL_RenderFillRect(renderer, &rect); 
  SDL_RenderPresent(renderer);

  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_UP]) {
    printf("%d", rect.x);
    cout << "UP" << endl;
    rect.x+=100;
    printf("%d", rect.x);
    SDL_Delay(1000);
  }
    
  if (keystate[SDL_SCANCODE_DOWN]) {
    cout << "DOWN" << endl;
    rect.y+=100;
    SDL_Delay(1000);
  }

  if (keystate[SDL_SCANCODE_RETURN]) { 
    printf("La touche entree est appuyee."); 
  }

  return 0;
  SDL_Delay(1000);
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