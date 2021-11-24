#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "fonctions_fichiers.h"
#include "fonctions_SDL.h"

#define MULTIPLICATEUR 9
#define TAILLE_ECRAN_X 140 * MULTIPLICATEUR
#define TAILLE_ECRAN_Y 91 * MULTIPLICATEUR
#define TAILLE_BLOCK 7

int main()
{
    char** tab;
    char* fichier = "map.txt";
    int nbLig, nbCol;

    taille_fichier(fichier, &nbLig, &nbCol);
    tab = lire_fichier(fichier);
    
    afficher_tab_2D(tab, nbLig, nbCol);
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

    //texture du personnage
    Uint8 r = 255, g = 255, b = 255;
    SDL_Texture* perso = charger_image_transparente("Ressource_projet/skin_player.bmp", renderer, r, g, b);

    int nbPersoW = 3, nbPersoH = 2;
    int persoW, persoH;
    SDL_QueryTexture(perso, NULL, NULL, &persoW, &persoH);

    persoW /= nbPersoW;
    persoH /= nbPersoH;

    SDL_Rect SrcPerso, DestPerso;
    SrcPerso.x = 0;
    SrcPerso.y = 0;
    SrcPerso.w = persoW;
    SrcPerso.h = persoH;

    DestPerso.x = TAILLE_BLOCK*MULTIPLICATEUR;
    DestPerso.y = TAILLE_BLOCK*MULTIPLICATEUR;
    DestPerso.w = persoW*MULTIPLICATEUR;
    DestPerso.h = persoH*MULTIPLICATEUR;

    //--------------------------------BOUCLE DE JEU--------------------------------//
    bool terminer = false;

    while(!terminer){
        SDL_RenderClear(renderer);
        
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

        //Affichage du personnage
        SDL_RenderCopy(renderer, perso, &SrcPerso, &DestPerso);
        
        printf("%d\n",persoH);

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
                DestPerso.y -= 2;                    
                break;

            case SDLK_DOWN:
                    DestPerso.y += 1;
                break;

            case SDLK_LEFT:
                    DestPerso.x -= 1;
                break;
            
            case SDLK_RIGHT:
                    DestPerso.x += 1;
                break;

            default:
                break;
            }
        
        default:
            break;
        }

        DestPerso.y += 1;

        for (int x = DestPerso.x; x < DestPerso.x + persoW; x++) {
            for (int y = DestPerso.y; y < DestPerso.y + persoH; y++) {
                if(tab[y/TAILLE_BLOCK/MULTIPLICATEUR][x/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.y += 1;
                }

                if(tab[(y + persoH*MULTIPLICATEUR)/TAILLE_BLOCK/MULTIPLICATEUR][x/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.y -= 1;
                }

                if(tab[y/TAILLE_BLOCK/MULTIPLICATEUR][x/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.x += 1;
                }

                if(tab[y/TAILLE_BLOCK/MULTIPLICATEUR][(x + persoW*MULTIPLICATEUR)/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.x -= 1;
                }
            }
        }

        /*for (int x = DestPerso.x; x <= DestPerso.x + persoW; x++) {
            for (int y = DestPerso.y; y <= DestPerso.y + persoH; y++) {
                if(tab[y/TAILLE_BLOCK/MULTIPLICATEUR][(DestPerso.x)/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.x += 1;
                }

                if(tab[((DestPerso.y)*MULTIPLICATEUR)/TAILLE_BLOCK/MULTIPLICATEUR][x/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.y += 1;
                }

                if(tab[y/TAILLE_BLOCK/MULTIPLICATEUR][(DestPerso.x + persoW)/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.x -= 1;
                }

                if(tab[(DestPerso.y + persoH)/TAILLE_BLOCK/MULTIPLICATEUR][(x*MULTIPLICATEUR)/TAILLE_BLOCK/MULTIPLICATEUR] == '1'){
                    DestPerso.y -= 1;
                }
            }
        }*/

        //Affichage des éléments 
        SDL_RenderPresent(renderer);
    }



    SDL_Quit();
    return 0;
}