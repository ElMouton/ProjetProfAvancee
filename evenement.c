#include <SDL2/SDL.h>

#include "data.h"
#include "fonctions_fichiers.h"
#include "evenement.h"

#include <stdio.h>
#include <stdbool.h>

void evenement_jeu(SDL_Event event, world_t *world) {
    //Evenement du clavier
    while(SDL_PollEvent(&event)) {
        switch (event.type){
        case SDL_QUIT:
            world->game_over = 1;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
            case SDLK_ESCAPE:
                world->game_over = 1;
                break;

            case SDLK_UP:
                world->Personnage.y -= 1;                    
                break;

            case SDLK_DOWN:
                world->Personnage.y += 1;
                break;

            case SDLK_LEFT:
                world->Personnage.x -= 1;
                break; 
            
            case SDLK_RIGHT:
                world->Personnage.x += 1;
                break;

            default:
                break;
            }
        
        default:
            break;
        }
    }
}