#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "snake.hpp"
#define widthWindow 540
#define size 30
#define sizeOfSquare = floor(widthWindow /size)

using namespace std;

SDL_Window* fenetre;  // Déclaration de la fenêtre
SDL_Renderer* renderer; //Déclaration du renderer
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
        SDL_WINDOWPOS_CENTERED, widthWindow, widthWindow, Uint32(0));  // Création de la fenêtre

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

int destroyMap()
{
    SDL_FreeSurface(mapSnake); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL

    return 0;
}

int drawGrid(int w)
{
    int x =0;
    int y =0;
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    for (int n; n<size; n++) // n takes values from 0 to GRID_SIZE 
    {
        x += sizeOfSquare;
        y += sizeOfSquare;

        SDL_RenderDrawLine(renderer, 0, y, widthWindow, y);
        SDL_RenderDrawLine(renderer, x, 0, x, widthWindow);
    }
    SDL_RenderPresent(renderer);
    int SDL_RenderClear(renderer);
    return 0;
}

int snakeHead()
{
    Head *snkHead = new Head();
    snkHead.posx = sizeOfSquare*10;
    snkHead.posy =sizeOfSquare*10;
    return 0;
}

int main(void)
{
    int exit = 0;
    map();
    drawGrid(widthWindow);

    while (exit == 0)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                exit =1;
            }
        }
    }
    destroyMap();
}