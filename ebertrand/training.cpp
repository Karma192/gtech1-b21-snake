#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef ENABLE_TESTS
void keyboard(){
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
    while (keystates[SDL_SCANCODE_DOWN]=false || keystates[SDL_SCANCODE_LEFT]=false || keystates[SDL_SCANCODE_RIGHT]=false);
    {
        /* code */
    }
    
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    while (keystates[SDL_SCANCODE_UP]=false || keystates[SDL_SCANCODE_LEFT]=false || keystates[SDL_SCANCODE_RIGHT]=false);
    {
        /* code */
    }
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    while (keystates[SDL_SCANCODE_DOWN]=false || keystates[SDL_SCANCODE_UP]=false || keystates[SDL_SCANCODE_RIGHT]=false);
    {
        /* code */
    }
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    while (keystates[SDL_SCANCODE_DOWN]=false || keystates[SDL_SCANCODE_LEFT]=false || keystates[SDL_SCANCODE_UP]=false);
    {
        /* code */
    }
  }
}
#endif

int main(int argc, char *argv[])
{
    SDL_Window* fenetre;
    SDL_Renderer* snake;//Déclaration du renderer
    int SDL_Init(SDL_INIT_EVERYTHING);//Init de toute la librairie
    Uint32 frame_rate = 6.9444444444444;//FrameRate
    Uint32 frame_time_start = SDL_GetTicks(); 

    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre :
    fenetre = SDL_CreateWindow("Une fenetre SDL" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 600 , 600 , SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    snake = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

    if(snake == NULL)//gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    int SDL_SetRenderTarget(SDL_Renderer* snake, SDL_Texture*  texture);

    SDL_Texture *texture = SDL_CreateTexture(snake, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,200);
    SDL_SetRenderDrawColor(snake,255,0,255,255);
    SDL_SetRenderTarget(snake, texture); //on modifie la texture
    SDL_RenderDrawRect(snake, NULL);
    SDL_RenderFillRect(snake, NULL);
    SDL_SetRenderTarget(snake, NULL);// Dorénavent, on modifie à nouveau le renderer

    SDL_Rect position;
    position.x = 100;
    position.y = 100;
    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(snake, texture, NULL, &position);
    SDL_RenderPresent(snake);
    SDL_Delay(4000);//pause de 4 secondes

    // Destruction du renderer et de la fenêtre :
    SDL_DestroyRenderer(snake); 
    SDL_DestroyWindow(fenetre);
    SDL_Quit(); // On quitte la SDL
}