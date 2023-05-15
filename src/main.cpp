#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Renderer* renderer;

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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer) {
        std::cout <<"Can't create renderer!\n";
        return 1;
    }
    // Set background color to turquoise
    SDL_SetRenderDrawColor(renderer, 64, 224, 208, 255);
    // Clear screen
    SDL_RenderClear(renderer);
    // update screen
    SDL_RenderPresent(renderer);
    
    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();

    return 0;
}