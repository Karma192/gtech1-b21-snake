#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void keyboard(){
const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_UP]) {
    {
       printf("yes ça marche");
    }
  }
  else{
      printf("oups");
  }
}

int main(int argc, char *argv[])
{
    SDL_Window* fenetre;  // Déclaration de la fenêtre

    if(SDL_Init(SDL_INIT_VIDEO) < 0)  // initialisation de la SDL
    {
       printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
       return EXIT_FAILURE;
    }

    fenetre = SDL_CreateWindow("Une fenetre SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);  // Création de la fenêtre

    if (fenetre == NULL)  //gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    keyboard();

    SDL_Delay(10000);  //pause de 10 secondes

    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL
    return 0;
}