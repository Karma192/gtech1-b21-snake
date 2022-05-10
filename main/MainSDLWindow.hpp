#pragma once
#include <SDL2/SDL.h>
#include <thread>

class MainSDLWindow {
public:
  MainSDLWindow();
  ~MainSDLWindow();
  SDL_Renderer *GetRenderer();
  int Init(const char* winname, int width_, int height_);
  void setName(void);
  void runTHSetName(void);
  int redCross(void);
  int map(void);

private:
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Surface* mapSnake;
};