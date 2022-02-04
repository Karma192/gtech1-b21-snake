#pragma once
#include <SDL2/SDL.h>
#include <iostream>

#define WIDTHGAME 540
#define HEIGHTWINDOW 600
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)

class Window {
    private :
        SDL_Window* fenetre1;
        SDL_Renderer* renderer;
        SDL_Surface* mapSnake;

    public :
        int map(void)
        {
            mapSnake = SDL_LoadBMP("../img/snk.bmp");
            
            SDL_Rect position;
            position.x = 0;
            position.y = 0;

            if(!mapSnake)
            {
                printf("Erreur de chargement de l'image : %s",SDL_GetError());
                return -1;
            }
            
            SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer,mapSnake); 
            
            if(!monImage)
            {
                printf("Erreur de chargement de l'image : %s",SDL_GetError());
                return -1;
            }
            
            SDL_QueryTexture(monImage, NULL, NULL, &position.w, &position.h);
            SDL_RenderCopy(renderer, monImage, NULL, &position);
            SDL_RenderPresent(renderer);

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

        Window(void)
        {
            if(SDL_Init(SDL_INIT_VIDEO) < 0)
            {
            printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
            return EXIT_FAILURE;
            }

            fenetre1 = SDL_CreateWindow("SNAKE",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, WIDTHGAME, HEIGHTWINDOW, Uint32(0));

            if (fenetre1 == NULL)
            {
                printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
                return EXIT_FAILURE;
            }

            renderer = SDL_CreateRenderer(fenetre1, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if(renderer == NULL)
            {
                printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
                return EXIT_FAILURE;
            }

            SDL_RenderPresent(renderer);

            return EXIT_SUCCESS;
        }

        ~Window(void)
        {
            SDL_FreeSurface(mapSnake); 
            SDL_DestroyRenderer(renderer); 
            SDL_DestroyWindow(fenetre1);
            SDL_Quit(); 

            return EXIT_SUCCESS;
        }
};