#include <stdio.h>
#include <stdlib.h>

#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("ERREUR D'INITIALISATION DE LA SDL : %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_Quit();
}