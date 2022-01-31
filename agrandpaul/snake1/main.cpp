#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define WIDTHGAME 540
#define SIZE 30
#define SIZEOFSQUARE floor(WIDTHGAME /SIZE)


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
            else {return 0;}
        }
}

int drawGrid(void)
{
    int x =0;
    int y =0;
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    for (int n; n<SIZE; n++) // n takes values from 0 to GRID_SIZE 
    {
        x += SIZEOFSQUARE;
        y += SIZEOFSQUARE;

        SDL_RenderDrawLine(renderer, 0, y, WIDTHGAME, y);
        SDL_RenderDrawLine(renderer, x, 0, x, WIDTHGAME);
    }
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    return 0;
}

int keys()
{
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_UP]) {
      cout << "UP" << endl;
      return 1;
  }
    
  if (keystate[SDL_SCANCODE_DOWN]) {
    cout << "DOWN" << endl;
    return
  }

  if (keystate[SDL_SCANCODE_RIGHT]) { 
    cout << "RIGHT" << endl;
    positx+=10;

  }

  if (keystate[SDL_SCANCODE_LEFT]) { 
    cout << "LEFT" << endl;
    positx-=10;

  }
}

/*int snakeHead()
{
    Head *snkHead = new Head();
    snkHead.posx = sizeOfSquare*15;
    snkHead.posy =sizeOfSquare*15;
    return 0;
}*/

int main(void)
{
    int exit = 0;
    map();
    //drawGrid();

    while (exit == 0)
    {
        move(positx, posity, dirx, diry);
        exit = redCross();
    }
    destroy();
}