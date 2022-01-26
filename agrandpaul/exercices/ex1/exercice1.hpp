#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
 
class MainSDLWindow {
    public :
    int window = NULL;
    int renderer = NULL;
    private :
    window = SDL_Window*window;
    renderer = SDL_Renderer*renderer;
    }
}

~MainSDLWindow() {

}