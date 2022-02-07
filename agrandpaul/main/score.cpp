#include "score.hpp"

Score::Score()
{

}

Score::~Score()
{

}

void Score::drawScore(SDL_Renderer *renderer, int score)
{
  int x = this->sposx;
  int y = this->sposy;
  for (int i = score+1; i<0; i--) 
  {
    x = x + (i *SIZEOFSQUARE);
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = SIZEOFSQUARE;
    rect.h = SIZEOFSQUARE;

    SDL_SetRenderDrawColor(renderer, this->Red, this->Green, this->Blue, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);

    if (score%SIZESHOWSCORE == 0) {
      x = this->sposx;
      y = this->sposy;
    }

    if (i%SIZE == 0) {
      x = this->sposx;
      y = y +SIZEOFSQUARE;
    }
  }
}