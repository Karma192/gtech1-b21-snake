#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
const Uint8 *keystate = SDL_GetKeyboardState(NULL);

int main(int argc, char *argv[]){

  SDL_Window* fenetre;  // Déclaration de la fenêtre

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

  SDL_Renderer *renderer;
  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(renderer == NULL)//gestion des erreurs
  {
    printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Rect rect;
  rect.w = 200;
  rect.h = 200;
  rect.x = 350;
  rect.y = 350;

  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderDrawRect(renderer, &rect);
  SDL_RenderFillRect(renderer, &rect); 
  SDL_RenderPresent(renderer);


  if (keystate[SDL_SCANCODE_UP]){
      cout << "UP" << endl;
    }
    
  if (keystate[SDL_SCANCODE_DOWN]){
      cout << "DOWN" << endl;
  }

  SDL_Delay(4000);

  return 0;
}