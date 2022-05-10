#include "score.hpp"
using namespace std;
#include <SDL2/SDL.h>
#include <iostream>

void Score::drawScore(SDL_Renderer *renderer, int score)
{
  int x = this->sposx;
  int y = this->sposy;
  x = x + (i * SIZEOFSQUARE);
  for (int i = score; i != 0; i--)
  {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = SIZEOFSQUARE;
    rect.h = SIZEOFSQUARE;

    SDL_SetRenderDrawColor(renderer, this->Red, this->Green, this->Blue, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);

    if (score < 30)
    {
      x = x + SIZEOFSQUARE;
      this->Red = 9;
      this->Green = 40;
      this->Blue = 116;
    }

    else
    {
      this->Red += 10;
      this->Green += 10;
      this->Blue += 10;
      x = x + SIZEOFSQUARE;
    }
  }
}