#include "exercice1.hpp"

int MainSDLWindow::Init(char*name, int*largeur, int*hauteur){
    SDL_Window* window; 
    SDL_Renderer* renderer;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
       printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
       return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Exercice 1", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 800, (Uint32)0);

    if (window == NULL){
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 

    if(renderer == NULL){
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    int SDL_SetRenderDrawColor(SDL_Renderer* renderer, 0,  0 , 0 , 255);
}

int main(void) {
    MainSDLWindow main_window;
    main_window.Init();
    return EXIT_SUCCESS;
}