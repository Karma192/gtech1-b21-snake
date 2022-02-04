#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
 
class MainSDLWindow {
public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(char*name, int*largeur, int*hauteur);
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
}
