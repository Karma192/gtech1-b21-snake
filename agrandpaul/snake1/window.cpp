#pragma once
#include <SDL2/SDL.h>

SDL_Window* fenetre;
SDL_Renderer* renderer;
SDL_Surface* mapSnake = SDL_LoadBMP("../img/snk.bmp");

int map(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)  // initialisation de la SDL
    {
       printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
       return EXIT_FAILURE;
    }

    fenetre = SDL_CreateWindow("SNAKE",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WIDTHGAME, WIDTHGAME, Uint32(0));  // Création de la fenêtre

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

    if(!mapSnake)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        return -1;
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer,mapSnake);  //La texture monImage contient maintenant l'image importée
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

    return 0;
}

int destroy(void)
{
    SDL_FreeSurface(mapSnake); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL

    return 0;
}

int redCross(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 1;
        }
    }
    return 0;
}