#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
Uint32 frame_rate = 6.9;
 
int main(void)
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
        SDL_WINDOWPOS_CENTERED, 540, 540, SDL_WINDOW_RESIZABLE);  // Création de la fenêtre

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

    SDL_Surface* image = SDL_LoadBMP("img/snk.bmp");
    if(!image)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        return -1;
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
    if(!monImage)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        return -1;
    }
    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    SDL_QueryTexture(monImage, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(renderer, monImage, NULL, &position);
    SDL_RenderPresent(renderer);

    SDL_Delay(10000);  //pause de 10 secondes

    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL
    return 0;
}