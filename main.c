#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "fonctions_fichiers.h"
#include "fonctions_SDL.h"

#define MULTIPLICATEUR 1
#define TAILLE_ECRAN_X 700 * MULTIPLICATEUR
#define TAILLE_ECRAN_Y 700 * MULTIPLICATEUR

int main()
{
    char** tab;
    char* fichier = "map.txt";
    int nbLig, nbCol;

    taille_fichier(fichier, &nbLig, &nbCol);
    tab = lire_fichier(fichier);
    
    //--------------------------------INITIALISATION SDL--------------------------------//
    SDL_Event evenement;

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

    //--------------------------------TEXTURES--------------------------------//
    SDL_Texture* block = charger_image("Ressource_projet/block.bmp", renderer);
    int blockW, blockH;
    SDL_QueryTexture(block, NULL, NULL, &blockW, &blockH);

    blockW /= 2;

    SDL_Rect SrcBlocks[2], DestBlock;
    for(int i = 0; i < 2; i++){
        SrcBlocks[i].x = i * 7;
        SrcBlocks[i].y = 0;
        SrcBlocks[i].w = blockW;
        SrcBlocks[i].h = blockH;
    }

    //--------------------------------BOUCLE DE JEU--------------------------------//
    bool terminer = false;

    while(!terminer){
        SDL_RenderClear(renderer);

        for(int i = 0; i < nbLig; i ++){
            for(int j = 0; j < nbCol; j++){
                DestBlock.x = j*7*MULTIPLICATEUR;
                DestBlock.y = i*7*MULTIPLICATEUR;
                DestBlock.w = blockW*MULTIPLICATEUR;
                DestBlock.h = blockH*MULTIPLICATEUR;
            }
        }

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