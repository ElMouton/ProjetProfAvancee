#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SDL2/SDL.h"

#define MULTIPLICATEUR 1
#define TAILLE_ECRAN_X 700 * MULTIPLICATEUR
#define TAILLE_ECRAN_Y 700 * MULTIPLICATEUR

int main()
{
    bool terminer = false;
    SDL_Event evenement;

    //--------------------------------INITIALISATION SDL--------------------------------//
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("ERREUR D'INITIALISATION DE LA SDL : %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    SDL_Window* fenetre = SDL_CreateWindow("Petit jeu sympa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE_ECRAN_X, TAILLE_ECRAN_Y, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL){
        printf("ERREUR DANS LE CHARGEMENT DE LA FENETRE : %s", SDL_GetError());
        SDL_Quit();
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    //--------------------------------BOUCLE DE JEU--------------------------------//
    while(!terminer){
        SDL_RenderClear(renderer);

        SDL_PollEvent(&evenement);
        switch (evenement.type){
        case SDL_QUIT:
            terminer = true;
            break;

        case SDL_KEYDOWN:
            switch (evenement.key.keysym.sym){
            case SDLK_ESCAPE:
                terminer = true;
                break;
            
            default:
                break;
            }
        
        default:
            break;
        }
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}