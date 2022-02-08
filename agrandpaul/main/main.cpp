#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
using namespace std;

//#include "app.cpp"

int main()
{
    MainSDLWindow *sdlwin = new MainSDLWindow;
    if (sdlwin->Init("Snake", WIDTHGAME, HEIGHTWINDOW) == EXIT_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    std::thread t1 (&MainSDLWindow::setName, sdlwin);
    std::thread t2 (game, sdlwin);
    t1.join();
    t2.join();
}