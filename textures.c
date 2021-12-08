#include "textures.h"
#include "fonctions_SDL.h"

void init_textures(textures_t* texture, SDL_Renderer* renderer){
    texture->Personnage = charger_image("Ressource_projet/block.bmp", renderer);
}

void clean_texture(textures_t* texture){
    SDL_DestroyTexture(texture->Personnage);
}

void apply_texture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y){
    SDL_Rect Dest = {0, 0, 0, 0};
    SDL_QueryTexture(texture, NULL, NULL, &Dest.w, &Dest.h);
    Dest.x = x; 
    Dest.y = y;

    SDL_RenderCopy(renderer, texture, NULL, &Dest);
}

void apply_sprite(SDL_Renderer* renderer, SDL_Texture* texture, sprite_t* sprite){
    apply_texture(texture, renderer, sprite->x, sprite->y);
}

void apply_perso(SDL_Renderer* renderer, SDL_Texture* texture, sprite_t* sprite){
    apply_sprite(renderer, texture->Personnage, sprite);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    apply_perso(renderer, textures->Personnage, &(world->Personnage));
}

//--------------RENDERER--------------//

void renderer_clear(SDL_Renderer* renderer){
    SDL_RenderClear(renderer);
}

void mise_a_jour_renderer(SDL_Renderer* renderer){
    SDL_RenderPresent(renderer);
}