#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
Uint32 frame_rate = 6.9;
 
int main(int argc, char *argv[])
{
    SDL_Window* fenetre;  // Déclaration de la fenêtre
    SDL_Renderer* renderer; //Déclaration du renderer

    if(SDL_Init(SDL_INIT_VIDEO) < 0)  // initialisation de la SDL
    {
       printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
       return EXIT_FAILURE;
    }

    fenetre = SDL_CreateWindow("SNAKE",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 800, 800, (Uint32)0);  // Création de la fenêtre

    if (fenetre == NULL)  //gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

    if(renderer == NULL)//gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    int SDL_SetRenderTarget(SDL_Renderer* renderer, SDL_Texture*  texture);

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,200);
    SDL_SetRenderDrawColor(renderer,250,150,250,255);
    SDL_SetRenderTarget(renderer, texture); //on modifie la texture
    SDL_RenderDrawRect(renderer,NULL);
    SDL_RenderFillRect(renderer, NULL);
    SDL_SetRenderTarget(renderer, NULL);// Dorénavent, on modifie à nouveau le renderer

    SDL_Rect position;
    position.x = 100;
    position.y = 200;
    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(renderer, texture, NULL, &position);
    SDL_RenderPresent(renderer);

    SDL_Delay(5000);  //pause de 5 secondes

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL
    return 0;
}