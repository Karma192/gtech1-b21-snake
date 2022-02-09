#include "MainSDLWindow.hpp"

MainSDLWindow::MainSDLWindow() {
  this->renderer = NULL;
  this->window = NULL;
}

MainSDLWindow::~MainSDLWindow() {
  if(this->renderer != NULL) SDL_DestroyRenderer(this->renderer);
  if(this->window != NULL) SDL_DestroyWindow(this->window);
  SDL_Quit();
}

SDL_Renderer *MainSDLWindow::GetRenderer() {
  return this->renderer;
}

int MainSDLWindow::Init(const char* name, int score, int width, int height) {
  // Init SDL:
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Init the main SDL window:
  Uint32 window_flags = 0;
  this->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  window_flags);
  if(this->window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Init renderer within the main SDL window:
  Uint32 renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  this->renderer = SDL_CreateRenderer(window, -1, renderer_flags);
  if(this->renderer == NULL) {
    printf("SDL2 error while creating renderer : %s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Fill renderer background:
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
  SDL_RenderClear(this->renderer);
  SDL_RenderPresent(this->renderer);
  return EXIT_SUCCESS;
}

int MainSDLWindow::redCross(void)
{
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return 1;
    }
  }
  return 0;
}

int MainSDLWindow::map(void)
{
  this->mapSnake = SDL_LoadBMP("../img/snk.bmp");
  
  SDL_Rect position;
  position.x = 0;
  position.y = 0;

  if(!this->mapSnake)
  {
    printf("Erreur de chargement de l'image : %s",SDL_GetError());
    return -1;
  }
  
  SDL_Texture* monImage = SDL_CreateTextureFromSurface(this->renderer, this->mapSnake); 
  
  if(!monImage)
  {
    printf("Erreur de chargement de l'image : %s",SDL_GetError());
    return -1;
  }
  
  SDL_QueryTexture(monImage, NULL, NULL, &position.w, &position.h);
  SDL_RenderCopy(this->renderer, monImage, NULL, &position);

  return 0;
}