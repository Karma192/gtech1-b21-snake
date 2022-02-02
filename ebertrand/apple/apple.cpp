#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "apple.hpp"
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

int main(){
    map();
    Apple(posx);
    printf("%d\n%d\n", posy, posx);
    SDL_Delay(3000);
}