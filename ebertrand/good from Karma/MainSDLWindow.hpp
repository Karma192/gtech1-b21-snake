#pragma once
#include <SDL2/SDL.h>

class MainSDLWindow {
public:
  MainSDLWindow();
  ~MainSDLWindow();
  SDL_Renderer *GetRenderer();
  int Init(const char* winname, int score, int width_, int height_);
  int redCross(void);
  int map(void);

private:
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Surface* mapSnake;
};