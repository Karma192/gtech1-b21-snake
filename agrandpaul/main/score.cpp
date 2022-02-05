#include "score.hpp"

Score::Score(void){
    extern DECLSPEC int SDLCALL TTF_Init(void);
    #define TTF_GetError SDL_GetError

    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    this->renderer2 = NULL;
    this->window2 = NULL;
}

Score::~Score(void){
    void SDLCALL TTF_Quit(void);
    // Libération des ressource en mémoire
    SDL_DestroyRenderer(renderer2);
    SDL_DestroyWindow(window2);
    TTF_Quit();
    SDL_Quit();
}

int Score::Init(const char* name, int width, int height) {
  // Init SDL:
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Init the main SDL window:
  Uint32 window_flags = 0;
  this->window2 = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  window_flags);
  if(this->window2 == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Init renderer within the main SDL window:
  Uint32 renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  this->renderer2 = SDL_CreateRenderer(window, -1, renderer_flags);
  if(this->renderer2 == NULL) {
    printf("SDL2 error while creating renderer : %s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Fill renderer background:
  SDL_SetRenderDrawColor(this->renderer2, 0, 0, 0, 255);
  SDL_RenderClear(this->renderer2);
  SDL_RenderPresent(this->renderer2);
  return EXIT_SUCCESS;
}

void Score::showScore(char score) {
    
    
}