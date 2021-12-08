#include "textures.h"
#include "fonctions_SDL.h"
#include "Constante.h"

void init_textures(textures_t* textures, SDL_Renderer* renderer){
    textures->Personnage = charger_image("Ressource_projet/block.bmp", renderer);
}

void clean_textures(textures_t* textures){
    SDL_DestroyTexture(textures->Personnage);
}

void apply_texture(SDL_Texture* textures, SDL_Renderer* renderer, SDL_Rect Src, int x, int y, int w, int h){
    SDL_Rect Dest = {0, 0, 0, 0};
    
    Dest.x = x; 
    Dest.y = y;
    Dest.w = w;
    Dest.h = h;
    SDL_QueryTexture(textures, NULL, NULL, &Dest.w, &Dest.h);

    SDL_RenderCopy(renderer, textures, &Src, &Dest);
}

SDL_Rect* texture_separate(SDL_Texture* texture , int nbTextureW, int nbTextureH){
    int TextW, TextH;

    SDL_QueryTexture(texture, NULL, NULL, &TextW, &TextH);

    if(nbTextureW != 0){
        TextW /= nbTextureW;
    }

    SDL_Rect Src[nbTextureH][nbTextureW];
    for (int i = 0; i < nbTextureW; i++)
    {
        Src[i].x = i * TextW;
        Src[i].y = j * TextH;
        Src[i].w = TextW;
        Src[i].h = TextH;
    }
    return Src;
}

void apply_wall(SDL_Renderer* renderer, SDL_Texture* textures, char** tab int nbLig, int nbCol){
    SDL_Rect Dest;

    for(int i = 0; i < nbLig; i ++){
        for(int j = 0; j < nbCol; j++){


            Dest.x = j * TAILLE_BLOCK;
            Dest.y = i * TAILLE_BLOCK;
            Dest.w = Src->w;
            Dest.h = Src->h;


            switch (tab[i][j]){
            case '1':
                SDL_RenderCopy(renderer, textures, &Src[0], &Dest);
                break;
            
            default:
                SDL_RenderCopy(renderer, textures, &Src[1], &Dest);
                break;
            }
        }
    }
}

void apply_sprite(SDL_Renderer* renderer, SDL_Texture* textures, sprite_t* sprite){
    apply_texture(textures, renderer, NULL ,sprite->x, sprite->y, 0, 0);
}

void apply_perso(SDL_Renderer* renderer, textures_t* textures, sprite_t* sprite){
    apply_sprite(renderer, textures->Personnage, sprite);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures, char** tab){
    clear_renderer(renderer);

    apply_perso(renderer, textures->Personnage, &(world->Personnage));
    apply_wall(renderer, textures, tab, )

    mise_a_jour_renderer(renderer);

    stop_game(world);
}

void stop_game(world_t* world){
    if(world->etat_jeu != 0){
        SDL_Delay(2000);
    }
}

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){

    clean_textures(textures);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

int init_sdl(SDL_Window* fenetre, SDL_Renderer* renderer){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("ERREUR D'INITIALISATION DE LA SDL : %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    fenetre = SDL_CreateWindow("Petite fenêtre sympa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE_ECRAN_X, TAILLE_ECRAN_Y, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL){
        printf("ERREUR DANS LE CHARGEMENT DE LA FENETRE : %s", SDL_GetError());
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
}

void init(SDL_Window* fenetre, SDL_Renderer* renderer, world_t* world, textures_t* textures){
    init_sdl(fenetre, renderer);
    //init_data(world);
    init_textures(renderer, textures);
}



//--------------RENDERER--------------//

void clear_renderer(SDL_Renderer* renderer){
    SDL_RenderClear(renderer);
}

void mise_a_jour_renderer(SDL_Renderer* renderer){
    SDL_RenderPresent(renderer);
}