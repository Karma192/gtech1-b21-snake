#include "snake.hpp"
using namespace std;

list<int> listx = {0};
list<int> listy = {0};

int Snake::keys(void) {
    int tmpdir = this->prev_dir;
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    SDL_Event event;
    SDL_PollEvent(&event);

    if (keystate[SDL_SCANCODE_UP]) {
        tmpdir = UP;
    }
    
    if (keystate[SDL_SCANCODE_DOWN]) {
        tmpdir = DOWN;
    }

    if (keystate[SDL_SCANCODE_RIGHT]) { 
        tmpdir = RIGHT;
    }

    if (keystate[SDL_SCANCODE_LEFT]) { 
        tmpdir = LEFT;
    }
    
    if (tmpdir == - this->prev_dir)
    {
        return this->prev_dir;
    }
    else{
        this->prev_dir = tmpdir;
        return this->prev_dir;
    }
}

void Snake::Move(int dir) {
    if(dir == UP)
    {
        this->posy = this->posy -SIZEOFSQUARE;
        this->posx = this->posx;
    }

    if (dir == DOWN)
    {
        this->posy = this->posy +SIZEOFSQUARE;
        this->posx = posx;
    }

    if (dir == LEFT)
    {
        this->posx = this->posx -SIZEOFSQUARE;
        this->posy = this->posy;
    }

    if (dir == RIGHT)
    {
        this->posx = this->posx +SIZEOFSQUARE;
        this->posy = this->posy;
    }
}

int Snake::colDeath(void) {
    if (this->posx >= WIDTHGAME || this->posy >= WIDTHGAME || this->posx < 0 || this->posy < 0) {
        return 1;
    }
    else {return 0;}

    int nbTails = sizeof(listx);
    for ( int i = nbTails; i != 0; i--) {
        auto l_Actx = listx.begin();
        auto l_Acty = listy.begin();
        advance(l_Actx, i);
        advance(l_Acty, i);
        if (*l_Actx == *listx.begin() && *l_Acty == *listy.begin()) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int Snake::colApple(int aPosx, int aPosy) {
    if (this->posx == aPosx && this->posy == aPosy) {
        return 1;
    }
    else {return 0;}
}

Snake::Snake(void) {
    this->posx = 15*SIZEOFSQUARE;
    this->posy = 15*SIZEOFSQUARE;
    this->prev_dir = 0;
}

Snake::~Snake(void) {

}

void Snake::drawHead(SDL_Renderer *renderer) {
    SDL_Rect head;
    head.w = SIZEOFSQUARE;
    head.h = SIZEOFSQUARE;
    head.x = this->posx;
    head.y = this->posy;

    SDL_SetRenderDrawColor(renderer, 11, 60, 42, 255);
    SDL_RenderDrawRect(renderer, &head);
    SDL_RenderFillRect(renderer, &head); 
}

void Snake::initTails(int ver)
{
    if (ver != 0) {
        listx.push_back(this->posx);
        listy.push_back(this->posy);
    }
}

void Snake::drawTails(SDL_Renderer *renderer)
{
    int nbTails = listx.size();
    for (int i = nbTails; i < 0; i--) {
        auto l_Actx = listx.begin();
        auto l_Acty = listy.begin();
        advance(l_Actx, i);
        advance(l_Acty, i);
        SDL_Rect tail;
        tail.w = SIZEOFSQUARE;
        tail.h = SIZEOFSQUARE;
        tail.x = *l_Actx;
        tail.y = *l_Acty;

        SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
        SDL_RenderDrawRect(renderer, &tail);
        SDL_RenderFillRect(renderer, &tail); 
        SDL_RenderPresent(renderer);
    }
}

void Snake::setList(void)
{
    *listx.begin() = this->posx;
    *listy.begin() = this->posy;
    int nbTails = listx.size();
    for (int i = nbTails ; i != 0; i--)
    {
        auto l_Actx = listx.begin();
        auto l_Prevx = listx.begin();
        auto l_Acty = listy.begin();
        auto l_Prevy = listy.begin();
        advance(l_Actx, i);
        advance(l_Prevx, i-1);
        advance(l_Acty, i);
        advance(l_Prevy, i-1);
        *l_Actx = *l_Prevx;
        *l_Acty = *l_Prevy;
    }
}

void Snake::error(void)
{
    int nbTails = listx.size();
    cout << nbTails << endl;
    for (int i = nbTails ; i >= 0; i--)
    {
        auto l_Actx = listx.begin();
        auto l_Acty = listy.begin();
        advance(l_Actx, i);
        advance(l_Acty, i);
        cout << "x : " << *listx.begin() << " y : " << *listy.begin() << endl;
        cout << "x : " << *l_Actx << " y : " << *l_Acty << endl;
    }
    cout << "." << endl;
}