#include "snake.hpp"
using namespace std;

int listx[] = {};
int listy[] = {};

int Snake::keys(void)
{
    int tmpdir = this->prev_dir;
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    SDL_Event event;
    SDL_PollEvent(&event);

    if (keystate[SDL_SCANCODE_UP])
    {
        tmpdir = UP;
    }

    if (keystate[SDL_SCANCODE_DOWN])
    {
        tmpdir = DOWN;
    }

    if (keystate[SDL_SCANCODE_RIGHT])
    {
        tmpdir = RIGHT;
    }

    if (keystate[SDL_SCANCODE_LEFT])
    {
        tmpdir = LEFT;
    }

    if (tmpdir == -this->prev_dir)
    {
        return this->prev_dir;
    }
    else
    {
        this->prev_dir = tmpdir;
        return this->prev_dir;
    }
}

void Snake::Move(int dir)
{
    if (dir == UP)
    {
        this->posy = this->posy - SIZEOFSQUARE;
        this->posx = this->posx;
    }

    if (dir == DOWN)
    {
        this->posy = this->posy + SIZEOFSQUARE;
        this->posx = posx;
    }

    if (dir == LEFT)
    {
        this->posx = this->posx - SIZEOFSQUARE;
        this->posy = this->posy;
    }

    if (dir == RIGHT)
    {
        this->posx = this->posx + SIZEOFSQUARE;
        this->posy = this->posy;
    }
}

int Snake::colDeath(void)
{
    if (this->posx >= WIDTHGAME || this->posy >= WIDTHGAME || this->posx < 0 || this->posy < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    int nbTails = sizeof(listx);
    for (int i = nbTails; i != 0; i--)
    {
        if (listx[i] == listx[0] && listy[i] == listy[0])
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

int Snake::colApple(int aPosx, int aPosy)
{
    if (this->posx == aPosx && this->posy == aPosy)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Snake::Snake(void)
{
    this->posx = 15 * SIZEOFSQUARE;
    this->posy = 15 * SIZEOFSQUARE;
    this->prev_dir = 0;
}

Snake::~Snake(void)
{
}

void Snake::drawHead(SDL_Renderer *renderer)
{
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
    if (ver != 0)
    {
        listx.push_back(5);
        cout << listx.size() << endl;

        cout << sizeof(listx) << endl;
    }   
}

void Snake::drawTails(SDL_Renderer *renderer)
{
    int nbTails = sizeof(listx);
    for (int i = nbTails; i < 0; i--)
    {
        cout << "yeah" << endl;
        SDL_Rect tail;
        tail.w = SIZEOFSQUARE;
        tail.h = SIZEOFSQUARE;
        tail.x = listx[i];
        tail.y = listy[i];

        SDL_SetRenderDrawColor(renderer, 1, 50, 32, 255);
        SDL_RenderDrawRect(renderer, &tail);
        SDL_RenderFillRect(renderer, &tail);
        SDL_RenderPresent(renderer);
    }
}

void Snake::setList(void)
{
    listx[0] = this->posx;
    listy[0] = this->posy;
    int nbTails = sizeof(listx);
    for (int i = nbTails; i != 0; i--)
    {
        listx[i] = listx[i - 1];
        listy[i] = listy[i - 1];
    }
}

void Snake::error(void)
{
    int nbTails = sizeof(listx);
    for (int i = nbTails; i >= 0; i--)
    {
        cout << "x : " << listx[i] << " y : " << listy[i] << endl;
    }
    cout << "." << endl;
}