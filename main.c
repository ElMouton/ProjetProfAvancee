#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "fonctions_fichiers.h"
#include "fonctions_SDL.h"
#include "Constante.h"
#include "textures.h"

int main()
{
    char** tab;
    char* fichier = "map.txt";
    int nbLig, nbCol;

    taille_fichier(fichier, &nbLig, &nbCol);
    tab = lire_fichier(fichier);

    //--------------------------------INITIALISATION SDL--------------------------------//
    SDL_Event evenement;
    world_t world;
    textures_t textures;
    SDL_Window* fenetre;
    SDL_Renderer* renderer;

    init(fenetre, renderer, &world, &textures);

    //--------------------------------TEXTURES--------------------------------//

    //texture des blocks de la map
    SDL_Texture* block = charger_image("Ressource_projet/block.bmp", renderer);

    int nbBlockW = 2;
    int blockW, blockH;
    SDL_QueryTexture(block, NULL, NULL, &blockW, &blockH);

    blockW /= nbBlockW;    //Division par le nombre de texture

    SDL_Rect SrcBlocks[nbBlockW], DestBlock;   //Séparation dans le fichier source des différents block
    for(int i = 0; i < nbBlockW; i++){
        SrcBlocks[i].x = i * TAILLE_BLOCK;
        SrcBlocks[i].y = 0;
        SrcBlocks[i].w = blockW;
        SrcBlocks[i].h = blockH;
    }


    //--------------------------------BOUCLE DE JEU--------------------------------//
    bool terminer = false;

    while(!terminer){
        clear_renderer(renderer);
        
        //Création et affichage de la map
        for(int i = 0; i < nbLig; i ++){
            for(int j = 0; j < nbCol; j++){
                DestBlock.x = j*TAILLE_BLOCK*MULTIPLICATEUR;
                DestBlock.y = i*TAILLE_BLOCK*MULTIPLICATEUR;
                DestBlock.w = blockW*MULTIPLICATEUR;
                DestBlock.h = blockH*MULTIPLICATEUR;

                switch (tab[i][j]){
                case '1':
                    SDL_RenderCopy(renderer, block, &SrcBlocks[0], &DestBlock);
                    break;
                
                default:
                    SDL_RenderCopy(renderer, block, &SrcBlocks[1], &DestBlock);
                    break;
                }
            }
        }

        //Evenement du clavier
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

            case SDLK_UP:
                //DestPerso.y -= 2;                    
                break;

            case SDLK_DOWN:
                //DestPerso.y += 1;
                break;

            case SDLK_LEFT:
                //DestPerso.x -= 1;
                break; 
            
            case SDLK_RIGHT:
                //DestPerso.x += 1;
                break;

            default:
                break;
            }
        
        default:
            break;
        }

        refresh_graphics(renderer, &world, &textures);

        //Affichage des éléments 
        mise_a_jour_renderer(renderer);
    }

    SDL_Quit();
    return 0;
}