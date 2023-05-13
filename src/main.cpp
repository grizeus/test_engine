#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_Surface* surface;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){ 
        std::cout << "Can't init video" << std::endl;
        return 1;
    }

    if (IMG_Init(IMG_INIT_JPG) < 0) {
        std::cout << "Can't init image" << std::endl;
        return 1;
    }
    
    window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if(!window) {
        std::cout <<"Can't create window!\n";
        return 1;
    }

    // create surface
    surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0xFF, 0));
    SDL_Delay(6000);

    return 0;
}